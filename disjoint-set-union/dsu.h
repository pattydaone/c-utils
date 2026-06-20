#ifndef DSU_H
#define DSU_H

long *DSU_init(long n);

void DSU_make_set(long *DSU_parent, long element);

long DSU_find(long *DSU_parent, long inp);

void DSU_union(long *DSU_parent, long set_a, long set_b);

#endif // !DSU_H
