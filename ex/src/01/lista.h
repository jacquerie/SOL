/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2014 Jacopo Notarstefano
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

typedef struct nodo {
	int valore;
	struct nodo *next;
} nodo;

typedef nodo *lista;

/** crea una lista vuota
 *  \retval NULL il puntatore alla lista vuota
 */
lista newList (void);

/** dealloca la lista
 *  \param l la lista
 */
void freeList (lista l);

/** trasforma una lista applicando a ogni elemento la funzione f
 *  \param l la lista
 *  \param f la funzione da mappare
 */
void mapList (int (*f) (int), lista l);

/** combina gli elementi della lista l usando un operatore binario associativo
 *  \param l la lista
 *  \param f l'operatore binario
 *  \param e l'elemento neutro di f
 *
 * \return la 'somma' degli elementi di l secondo f(l1, f(l2, f(... f(ln, e))))
 */
int reduceList (int (*f) (int, int), int e, lista l);

