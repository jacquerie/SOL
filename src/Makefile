CC = gcc
CFLAGS = -Wall -pedantic
EXE = ctlm recvm sendm

all: $(EXE)

clean:
	rm -f $(EXE)

ctlm: ctlm.c random_msg.c
	$(CC) $(CFLAGS) $^ -o $@

recvm: recvm.c morse.c morse_buffer.c stopwatch.c
	$(CC) $(CFLAGS) $^ -o $@

sendm: sendm.c morse.c morse_signal.c millisleep.c
	$(CC) $(CFLAGS) $^ -o $@

test: ctlm
	./ctlm 500 10 | tee "$$$$.tmp" &&
	./statm <"$$$$.tmp" &&
	rm -f "$$$$.tmp"
