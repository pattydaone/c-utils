#include "dsu.h"

#include <stdlib.h>

long *DSU_init(long n) {
	long* parent = malloc(sizeof(long) * n);
	for (long i = 0; i < n; ++i) {
		parent[i] = i;
	}
	
	return parent;
}

void DSU_make_set(long *DSU_parent, long element) {
	DSU_parent[element] = element;
}

long DSU_find(long *DSU_parent, long inp) {
	if (inp == DSU_parent[inp]) {
		return inp;
	}

	return DSU_parent[inp] = DSU_find(DSU_parent, DSU_parent[inp]);
}

long find_replace(long *DSU_parent, long inp, long replace_with) {
	if (inp == DSU_parent[inp]) {
		DSU_parent[inp] = replace_with;
		return inp;
	}

	long next = DSU_parent[inp];
	DSU_parent[inp] = replace_with;
	return find_replace(DSU_parent, next, replace_with);
}
void DSU_union(long *DSU_parent, long set_a, long set_b) {
	find_replace(DSU_parent, set_b, DSU_find(DSU_parent, set_a));
}
