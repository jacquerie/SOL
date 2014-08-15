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

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void printList (lista l) {
	while (l) {
		printf("%d\t", l->valore);
		l = l->next;
	}

	printf("\n");
}

int square (int n)
{
	return n * n;
}

int sum (int a, int b)
{
	return a + b;
}


int main (void)
{
	lista l = newList();
	lista m = newList();
	lista n = newList();

	l->valore = 1;
	m->valore = 2;
	n->valore = 3;

	l->next = m;
	m->next = n;

	printList(l);
	mapList(square, l);
	printList(l);

	printf("%d\n", reduceList(sum, 0, l));

	freeList(l);

	return 0;
}
