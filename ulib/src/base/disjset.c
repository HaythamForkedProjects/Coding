/* The MIT License

   Copyright (C) 2017 Zilong Tan (eric.zltan@gmail.com)

   Permission is hereby granted, free of charge, to any person obtaining
   a copy of this software and associated documentation files (the
   "Software"), to deal in the Software without restriction, including
   without limitation the rights to use, copy, modify, merge, publish,
   distribute, sublicense, and/or sell copies of the Software, and to
   permit persons to whom the Software is furnished to do so, subject to
   the following conditions:

   The above copyright notice and this permission notice shall be
   included in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
   BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
   ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
   SOFTWARE.
*/

#include <stdlib.h>
#include "disjset.h"

int disjset_init(struct disj_set *ds, size_t ne)
{
	size_t i;

	if (ne == 0)
		return -1;

	ds->ptr = (size_t*) malloc(sizeof(size_t) * ne);
	if (ds->ptr == NULL)
		return -1;

	ds->size = (size_t*) malloc(sizeof(size_t) * ne);
	if (ds->size == NULL) {
		free(ds->ptr);
		return -1;
	}

	for (i = 0; i < ne; ++i) {
		ds->ptr[i] = i;
		ds->size[i] = 1;
	}
	
	ds->nelem = ne;
	ds->nroot = ne;

	return 0;
}

void disjset_destroy(struct disj_set *ds)
{
	free(ds->ptr);
	free(ds->size);
}

size_t disjset_nroot(const struct disj_set *ds)
{
	return ds->nroot;
}

static inline size_t
__disjset_root(const size_t *ptr, size_t a)
{
	while (a != ptr[a])
		a = ptr[a];
	return a;
}

int disjset_connected(const struct disj_set *ds, size_t a, size_t b)
{
	return __disjset_root(ds->ptr, a) == __disjset_root(ds->ptr, b);
}

void disjset_connect(struct disj_set *ds, size_t a, size_t b)
{
	a = __disjset_root(ds->ptr, a);
	b = __disjset_root(ds->ptr, b);

	if (a == b)
		return;

	if (ds->size[a] < ds->size[b]) {
		ds->ptr[a] = b;
		ds->size[b] += ds->size[a];
	} else {
		ds->ptr[b] = a;
		ds->size[a] += ds->size[b];
	}

	--ds->nroot;
}
