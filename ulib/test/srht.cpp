#include <stdio.h>
#include <stdlib.h>
#include <ulib/tran_srht.h>

int main(int argc, char *argv[])
{
	double X[] = {1,1,1,1};
	double S[] = {-9,-9,-9,-9};
	double rout[] = {-3,-3}; 
	double idx[]  = {1,2};

	(void)argc;
	(void)argv;

	if(!srht(X, NULL, 1, 2, 2, -1, S, rout, idx)) {
		printf("S = [%lf %lf %lf %lf]\n", S[0], S[1], S[2], S[3]);
		printf("rout = [%lf %lf]\n", rout[0], rout[1]);
		printf(" idx = [%lf %lf]\n", idx[0], idx[1]);
		printf("passed\n");
	}

	return 0;
}
