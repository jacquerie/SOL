all: ctlm recvm sendm

clean:
	rm -f ctlm recvm sendm

ctlm: ctlm.c recvm sendm
	gcc ctlm.c -o ctlm

recvm: recvm.c
	gcc recvm.c -o recvm

sendm: msleep.c morse.c morse_signal.c sendm.c
	gcc msleep.c morse.c morse_signal.c sendm.c -o sendm

test: ctlm
	./ctlm 500 10 | tee "$$$$.tmp"
	./statm <"$$$$.tmp"
	rm -f "$$$$.tmp"
