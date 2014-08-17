all: pdf

clean:
	rm -f relazione.aux relazione.log relazione.out

pdf:
	pdflatex -shell-escape tex/relazione.tex

.PHONY: all clean pdf
