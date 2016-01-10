/* The MIT License

   Copyright (C) 2014 Zilong Tan (eric.zltan@gmail.com)

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

#ifndef _ULIB_DP_LIS_H
#define _ULIB_DP_LIS_H

#include <algorithm>

namespace ulib {

/**
 * dp_lis - find the longest increasing subsequence and return its
 * length
 * @seq: sequence to process
 * @res: resulting longest increasing subsequence.
 * @num: number of elements in the sequence
 * NOTE: this function returns 0 if seq is NULL or empty. @res can be
 * NULL if the subsequence is not desired. This function throws
 * bad_alloc exception in case of lacking memory.
 * Complexity: O(num*log(num)) time and O(num) space.
 */
template<typename T>
int dp_lis(const T seq[], T res[], int num)
{
	if (seq == NULL || num <= 0)
		return 0;

	T  *lis = new T[num];
	int max_len = 0;

	for (int i = 0; i < num; ++i) {
		int m, j, k;
		for (j = 0, k = max_len; j < k;) {
			m = (j + k) / 2;
			if (seq[i] == lis[m]) {
				j = m;
				break;
			}
			if (seq[i] < lis[m])
				k = m;
			else
				j = m + 1;
		}
		lis[j] = seq[i];
		if (j == max_len)
		    ++max_len;
	}

	if (res)
	    std::copy(lis, lis + max_len, res);

	delete [] lis;

	return max_len;
}

}  // namespace ulib

#endif  /* _ULIB_DP_LIS_H */
