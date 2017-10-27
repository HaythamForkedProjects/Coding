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

#ifndef _ULIB_DISJSET_H
#define _ULIB_DISJSET_H

#include <stddef.h>

struct disj_set {
	size_t *ptr;
	size_t *size;
	size_t nelem;
	size_t nroot;
};
	
#ifdef __cplusplus
extern "C" {
#endif

/**
 * disjset_init - create a disjoint set
 * @ds: pointer to the discriptor
 * @ne: number of elements
 * returns 0 if successful
 */
int disjset_init(struct disj_set *ds, size_t ne);

/**	
 * disjset_destroy - destroy internally allocated memory
 * @ds: pointer to the descriptor 
 */
void disjset_destroy(struct disj_set *ds);

/**
 * disjset_nroot - get the number of disjoint subsets
 * @ds: pointer to the descriptor
 */
size_t disjset_nroot(const struct disj_set *ds);

/**
 * disjset_connected - test whether two elements are in the same subset
 * @ds: pointer to the descriptor
 * @a, @b: two elements
 * returns nonzero if connected
 */
int disjset_connected(const struct disj_set *ds, size_t a, size_t b);

/**
 * disjset_connect - connect subsets of the two elements
 * @ds: pointer to the descriptor
 * @a, @b: elements representing the two subsets
 */
void disjset_connect(struct disj_set *ds, size_t a, size_t b);

#ifdef __cplusplus
}
#endif

#endif  /* _ULIB_DISJSET_H */
