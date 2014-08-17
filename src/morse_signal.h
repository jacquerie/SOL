#ifndef _morse_signal_h
#define _morse_signal_h

void send_symbol (char, pid_t);
void send_letter (char, pid_t, int);
void end_word (int);

#endif
