all: tar

clean:
	rm -f relazione.aux relazione.log relazione.out

pdf:
	pdflatex -shell-escape tex/relazione.tex

tar:
	tar czvf jnotarstefano.tar.gz src/*

.PHONY: all clean pdf tar
