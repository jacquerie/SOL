#ifndef __DOTNOISE_H
#define __DOTNOISE_H

typedef struct dotnoiseCompletions {
	size_t length;
	char** completions;
} dotnoiseCompletions;

typedef void(dotnoiseCompletionCallback)(const char*, dotnoiseCompletions*);
void dotnoiseSetCompletionCallback (dotnoiseCompletionCallback*);
void dotnoiseAddCompletion (const char*, dotnoiseCompletions*);

char* dotnoise (const char* prompt);

#endif
