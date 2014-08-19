all: ctlm recvm sendm

clean:
	rm -f ctlm recvm sendm

ctlm: ctlm.c recvm sendm
	gcc -Wall -pedantic ctlm.c -o ctlm

recvm: recvm.c
	gcc -Wall -pedantic recvm.c -o recvm

sendm: millisleep.c morse.c morse_signal.c sendm.c
	gcc -Wall -pedantic -lm millisleep.c morse.c morse_signal.c sendm.c -o sendm

test: ctlm
	./ctlm 500 10 | tee "$$$$.tmp"
	./statm <"$$$$.tmp"
	rm -f "$$$$.tmp"
