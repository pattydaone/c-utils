#include "dynarr.h"
#include <stdlib.h>
#include <string.h>

DynArr* DA_construct(int *arr, long size) {
	DynArr* ret = malloc(sizeof(DynArr));
	ret->size = size;
	ret->capacity = size;
	ret->data = malloc(size * sizeof(int));
	memcpy(ret->data, arr, size*sizeof(int));
	return ret;
}

void resize(DynArr *arr) {
	if (arr->capacity == 0) arr->capacity = 1;
	arr->capacity *= 2;
	arr->data = realloc(arr->data, arr->capacity * sizeof(int));
}

void DA_push_back(DynArr *arr, int n) {
	if (arr->size >= arr->capacity) {
		resize(arr);
	}
	arr->data[arr->size] = n;
	++arr->size;
}

void DA_reserve(DynArr *arr, long size) {
	if (size > arr->capacity) {
		arr->capacity = size;
		arr->data = realloc(arr->data, size * sizeof(int));
	}
}

void DA_shrink_to_fit(DynArr *arr) {
	arr->capacity = arr->size;
	arr->data = realloc(arr->data, arr->capacity * sizeof(int));
}

void DA_clear(DynArr *arr) {
	free(arr->data);
	arr->data = malloc(arr->capacity * sizeof(int));
	arr->size = 0;
}

void DA_insert(DynArr *arr, long index, int x) {
	if (index >= arr->size) return;
	if (arr->size >= arr->capacity) {
		resize(arr);
	}
	++arr->size;

	for (long i = arr->size - 1; i > index; --i) {
		arr->data[i] = arr->data[i - 1];
	}
	arr->data[index] = x;
}

void DA_erase(DynArr *arr, long index) {
	if (index >= arr->size) return;
	--arr->size;
	for (long i = index; i < arr->size; ++i) {
		arr->data[i] = arr->data[i + 1];
	}
}

int DA_pop_back(DynArr *arr) {
	if (arr->size == 0) exit(1);
	--arr->size;
	return arr->data[arr->size + 1];
}
