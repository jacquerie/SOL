all: ctlm recvm sendm

clean:
	rm -f ctlm recvm sendm

ctlm: ctlm.c recvm sendm
	gcc -Wall -pedantic ctlm.c -o ctlm

recvm: stopwatch.c morse.c morse_handler.c recvm.c
	gcc -Wall -pedantic stopwatch.c morse.c morse_handler.c recvm.c -o recvm

sendm: msleep.c morse.c morse_signal.c sendm.c
	gcc -Wall -pedantic -lm msleep.c morse.c morse_signal.c sendm.c -o sendm

test: ctlm
	./ctlm 500 10 | tee "$$$$.tmp"
	./statm <"$$$$.tmp"
	rm -f "$$$$.tmp"
