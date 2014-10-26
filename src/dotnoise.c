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
	/* TODO */
}

static int getColumns (int ifd, int ofd)
{
	/* TODO */
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
	/* TODO */
}

static int dotnoiseEdit (int stdin_fd, int stdout_fd, char *buffer, size_t buffer_length, const char *prompt)
{
	/* TODO */
}

static int dotnoiseRaw (char *buffer, size_t buffer_length, const char *prompt)
{
	/* TODO */
}

char *dotnoise (cost char *prompt)
{
	/* TODO */
}
