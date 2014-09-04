#ifndef _morse_buffer_h
#define _morse_buffer_h

extern char buffer[8];
extern int _index;

void buffer_add (char);
void buffer_flush (char*);

#endif
