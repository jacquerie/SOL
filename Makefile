clean:
	rm -f relazione.aux relazione.log relazione.out

pdf:
	pdflatex tex/relazione.tex

.PHONY: clean pdf
