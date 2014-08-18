#include <signal.h>

#include "constants.h"
#include "morse_handler.h"

volatile sig_atomic_t keep_going = TRUE;
volatile sig_atomic_t received_dot = FALSE;
volatile sig_atomic_t received_dash = FALSE;

void quit (int signal)
{
	keep_going = FALSE;
}

void receive_dot (int signal)
{
	received_dot = TRUE;
}

void receive_dash (int signal)
{
	received_dash = TRUE;
}
