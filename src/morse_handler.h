#ifndef _morse_handler_h
#define _morse_handler_h

volatile sig_atomic_t keep_going;
volatile sig_atomic_t received_dot;
volatile sig_atomic_t received_dash;

void quit (int);
void receive_dot (int);
void receive_dash (int);

#endif

