all: ctlm recvm sendm

clean:
	rm -f ctlm recvm sendm

ctlm: random_msg.c ctlm.c recvm sendm
	gcc -Wall -pedantic random_msg.c ctlm.c -o ctlm

recvm: morse.c morse_buffer.c stopwatch.c recvm.c
	gcc -Wall -pedantic morse.c morse_buffer.c stopwatch.c recvm.c -o recvm

sendm: millisleep.c morse.c morse_signal.c sendm.c
	gcc -Wall -pedantic -lm millisleep.c morse.c morse_signal.c sendm.c -o sendm

test: ctlm
	./ctlm 500 10 | tee "$$$$.tmp"
	./statm <"$$$$.tmp"
	rm -f "$$$$.tmp"
