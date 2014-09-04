#ifndef _morse_h
#define _morse_h

extern char* CHAR_TO_MORSE[128];
extern char* MORSE_TO_CHAR[128];

char* encode (char);
char* decode (char*);
int morse_to_index (char*);

#endif

