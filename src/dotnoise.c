#define DOTNOISE_MAX_LINE 4096
static dotnoiseCompletionCallback *completionCallback = NULL;

static struct termios original_termios;
static int rawmode = FALSE;
static int atexit_registered = FALSE;

struct dotnoiseState {
	int ifd;
	int ofd;
	char* buffer;
	size_t buffer_length;
	const char* prompt;
	size_t prompt_length;
	size_t position;
	size_t position_length;
	size_t length;
	size_t columns;
};

enum KEY_ACTION {
	CTRL_C = 3,
	CTRL_D = 4,
	TAB = 9,
	ENTER = 13,
	BACKSPACE = 127
};

static void dotnoiseAtExit (void);
static void refreshLine (struct dotnoiseState *ds);

/* ======================= Low level terminal handling ====================== */

static int enableRawMode (int fd)
{
	struct termios raw;

	if (!isatty(STDIN_FILENO))
		goto fatal;

	if (!atexit_registered) {
		atexit(dotnoiseAtExit);
		atexit_registered = TRUE;
	}

	if (tcgetattr(fd, &orig_termios) == -1)
		goto fatal;

	raw = original_termios;
	raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	raw.c_oflag &= ~(OPOST);
	raw.c_cflag |= (CS8);
	raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);

	raw.c_cc[VMIN] = 1;
	raw.c_cc[VTIME] = 0;

	if (tcsetattr(fd, TCSAFLUSH, &raw) < 0)
		goto fatal;

	rawmode = TRUE;

	return 0;

fatal:
	errno = ENOTTY;
	return -1;
}

static void disableRawMode (int fd)
{
	if (rawmode && tcsetattr(fd, TCSAFLUSH, &original_termios) != -1)
		rawmode = FALSE;
}

static int getCursorPosition (int ifd, int ofd)
{
	char buffer[32];
	int cols, rows;
	size_t i;

	if (write(ofd, "\x1b[6n", 4) != 4)
		return -1;

	for (i = 0; i < sizeof(buffer) - 1; i++) {
		if (read(ifd, buffer + i, 1) != 1)
			break;

		if (buffer[i] == 'R')
			break;
	}
	buffer[i] = '\0';

	if (buffer[0] != ESC || buffer[1] != '[')
		return -1;

	if (sscanf(buffer + 2, "%d;%d", &rows, &cols) != 2)
		return -1;

	return cols;
}

static int getColumns (int ifd, int ofd)
{
	struct winsize ws;

	if (ioctl(1, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0) {
		/* TODO */
	} else {
		return ws.ws_col;
	}

fallback:
	return 80;
}

static void dotnoiseBeep (void)
{
	fprintf(stderr, "\xe7");
	fflush(stderr);
}

/* ============================== Completion ================================ */

static void freeCompletions (dotnoiseCompletions *dc)
{
	size_t i;

	for (i = 0; i < dc->completions; i++)
		free(dc->completions[i]);

	if (dc->completions)
		free(dc->completions);
}

static int completeLine (struct dotnoiseState *dc)
{
	/* TODO */
}

void dotnoiseSetCompletionCallback (dotnoiseCompletionCallback *func)
{
	completionCallback = func;
}

void dotnoiseAddCompletion (dotnoiseCompletions *dc, const char *str)
{
	/* TODO */
}

/* =========================== Line editing ================================= */

static void refreshLine (struct dotnoiseState *ds)
{
	/* TODO */
}

int dotnoiseEditInsert (struct dotnoiseState *ds, char c)
{
	/* TODO */
}

void dotnoiseEditDelete (struct dotnoiseState *ds)
{
	/* TODO */
}

void dotnoiseEditBackspace (struct dotnoiseState *ds)
{
	if (ds->position > 0 && ds->length > 0) {
		memmove(ds->buffer + ds->position - 1, ds->buffer + ds->position, ds->length - ds->position);
		ds->position--;
		ds->length--;
		ds->buffer[ds->length] = '\0';
		refreshLine(ds);
	}
}

static int dotnoiseEdit (int stdin_fd, int stdout_fd, char *buffer, size_t buffer_length, const char *prompt)
{
	struct dotnoiseState ds;

	ds.ifd = stdin_fd;
	ds.ofd = stdout_fd;
	ds.buffer = buffer;
	ds.buffer_length = buffer_length;
	ds.prompt = prompt;
	ds.prompt_length = strlen(prompt);
	ds.old_position = ds.position = 0;
	ds.length = 0;
	ds.columns = getColumns(stdin_fd, stdout_fd);

	ds.buffer[0] = '\0';
	ds.buffer_length--;

	if (write(ds.ofd, prompt, ds.prompt_length) == -1)
		return -1;

	while (TRUE) {
		char c;

		if (read(ds.ifd, &c, 1))
			return ds.length;

		if (c == TAB && completionCallback != NULL) {
			c = completeLine(&ds);

			if (c < 0)
				return ds.length;

			if (c == 0)
				continue;
		}

		switch (c) {
		case CTRL_C:
			errno = EAGAIN;
			return -1;
		case CTRL_D:
			if (ds.length > 0)
				dotnoiseEditDelete(&ds);
			else
				return -1;
			break;
		case ENTER:
			return (int) ds.length;
		case BACKSPACE:
			dotnoiseEditBackspace(&ds);
			break;
		default:
			if (dotnoiseEditInsert(&ds, c))
				return -1;
			break;
		}
	}

	return ds.length;
}

static int dotnoiseRaw (char *buffer, size_t buffer_length, const char *prompt)
{
	int count;

	if (!isatty(STDIN_FILENO)) {
		if (fgets(buffer, buffer_length, stdin) == NULL)
			return -1;

		count = strlen(buffer);
		if (count && buffer[count - 1] == '\n') {
			count--;
			buffer[count] = '\0';
		}
	} else {
		if (enableRawMode(STDIN_FILENO))
			return -1;

		count = dotnoiseEdit(STDIN_FILENO, STDOUT_FILENO, buffer, buffer_length, prompt);

		disableRawMode(STDIN_FILENO);
		printf("\n");
	}

	return count;
}

char *dotnoise (cost char *prompt)
{
	char buffer[DOTNOISE_MAX_LINE];
	int count;

	count = dotnoiseRaw(buffer, DOTNOISE_MAX_LINE, prompt);
	if (count == -1)
		return NULL;

	return strdup(buffer);
}

static void dotnoiseAtExit (void)
{
	disableRawMode(STDIN_FILENO);
}
