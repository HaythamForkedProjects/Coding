#include <stdio.h>
#include <assert.h>
#include <ulib/disjset.h>

int main(int argc, const char *argv[])
{
	disj_set ds;

	(void)argc;
	(void)argv;

	assert(!disjset_init(&ds, 3));
	assert(disjset_nroot(&ds) == 3);
	assert(!disjset_connected(&ds,0,1));
	assert(!disjset_connected(&ds,0,2));
	assert(!disjset_connected(&ds,1,2));
	assert(!disjset_connected(&ds,1,2));
	assert(disjset_connected(&ds,0,0));
	assert(disjset_connected(&ds,1,1));
	assert(disjset_connected(&ds,2,2));
	assert(!disjset_connected(&ds,1,0));
	assert(!disjset_connected(&ds,2,0));
	assert(!disjset_connected(&ds,2,1));

	disjset_connect(&ds,1,0);
	assert(disjset_connected(&ds,0,1));
	assert(disjset_connected(&ds,1,0));	
	assert(!disjset_connected(&ds,1,2));
	assert(!disjset_connected(&ds,0,2));
	assert(disjset_nroot(&ds) == 2);	
	disjset_connect(&ds,2,1);
	assert(disjset_nroot(&ds) == 1);
	assert(disjset_connected(&ds,0,1));
	assert(disjset_connected(&ds,1,2));	
	assert(disjset_connected(&ds,2,0));

	disjset_destroy(&ds);

	printf("passed\n");

	return 0;
}
