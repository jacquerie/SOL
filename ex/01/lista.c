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

lista newList (void)
{
	return calloc(sizeof(nodo), 1);
}

void freeList (lista l)
{
	lista tmp;

	while ((tmp = l)) {
		l = l->next;
		free(tmp);
	}
}

void mapList (int (*f) (int), lista l)
{
	lista tmp;

	while ((tmp = l)) {
		l = l->next;
		tmp->valore = f(tmp->valore);
	}
}

int reduceList (int (*f) (int, int), int e, lista l)
{
	if (l->next) {
		return f(l->valore, reduceList(f, e, l->next));
	} else {
		return f(l->valore, e);
	}
}

