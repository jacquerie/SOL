#ifndef _morse_buffer_h
#define _morse_buffer_h

static char buffer[8];
static int _index;

void buffer_add (char);
void buffer_flush (char*);

#endif
