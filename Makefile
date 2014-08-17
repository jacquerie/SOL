all: pdf

clean:
	rm -f relazione.aux relazione.log relazione.out

pdf:
	pdflatex tex/relazione.tex

.PHONY: all clean pdf
