#ifndef _random_msg_h
#define _random_msg_h

extern char ALLOWED_CHARS[];
extern int ALLOWED_LEN;

int random_int (int, int);
char random_char (void);
char* random_msg (int, int);

#endif
