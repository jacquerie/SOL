# Esercitazione 4 #

Dove si sperimenta la realizzazione di un `Makefile` da zero.

## Esercizio 1: `Makefile` per la libreria di lista ##

Con riferimento agli esercizi sulle lista dell'Esercitazione 1, definire un
`Makefile` che contenga

* le regole per generare correttamente `main.o` e `lista.o`
* la regola PHONY `lib` per generare correttamente la libreria `libList.a`
* la regola per generare l'eseguibile a partire da oggetti e librerie
* un target PHONY `cleanall` che elimini gli oggetti e gli eseguibili

utilizzare dove possibile le regole implicite, le variabili e le convenzioni
viste a lezione. Usare `gcc -MM` per generare automaticamente le liste di
dipendenze per i target relativi ai moduli oggetto.
