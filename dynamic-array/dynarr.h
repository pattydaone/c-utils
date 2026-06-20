#ifndef DYNARR_H
#define DYNARR_H

enum Types {
	BOOL,
	CHAR,
	CHAR_SIGNED,
	CHAR_UNSIGNED,
	INT_SHORT,
	INT_SHORT_SIGNED,
	INT_SHORT_UNSIGNED,
	INT,
	INT_SIGNED,
	INT_UNSIGNED,
	INT_LONG,
	INT_LONG_SIGNED,
	INT_LONG_UNSIGNED,
	INT_LONG_LONG,
	INT_LONG_LONG_SIGNED,
	INT_LONG_LONG_UNSIGNED,
	FLOAT,
	DOUBLE,
	DOUBLE_LONG
};

typedef enum Types DA_types;


typedef struct {
	int *data;
	long size;
	long capacity;
} DynArr;

DynArr* DA_construct(int *arr, long size);

void DA_push_back(DynArr *arr, int n);

void DA_reserve(DynArr *arr, long size);

void DA_shrink_to_fit(DynArr *arr);

void DA_clear(DynArr *arr);

void DA_insert(DynArr *arr, long index, int x);

void DA_erase(DynArr *arr, long index);

int DA_pop_back(DynArr *arr);

#endif // !DYNARR_H
