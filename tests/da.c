#include "../dynamic-array/dynarr.h"

#include <assert.h>
#include <stdbool.h>

bool arr_cmpr(DynArr *arr, int *carr, long carr_size) {
	if (arr->size != carr_size) return false;

	for (long i = 0; i < carr_size; ++i) {
		if (arr->data[i] != carr[i]) return false;
	}

	return true;
}

int main() {
	{ // Basic test
		int array[5] = { 1, 2, 3, 4, 5 };
		DynArr* arr = DA_construct(array, 5);

		assert( arr_cmpr(arr, array, 5) );

		DA_push_back(arr, 6);
		assert( arr->capacity == 10 );
		assert( arr->size == 6 );
		int equal[6] = { 1, 2, 3, 4, 5, 6 };
		assert( arr_cmpr(arr, equal, 6) );

		DA_reserve(arr, 20);
		assert( arr->capacity == 20 );

		DA_push_back(arr, 7);
		DA_shrink_to_fit(arr);
		assert( arr->size == arr->capacity && arr->capacity == 7 );

		DA_insert(arr, 3, 10);
		assert( arr->capacity == 14 );
		assert( arr->size == 8 );
		assert( arr->data[3] == 10 );

		DA_erase(arr, 0);
		assert( arr->size == 7 );
		assert( arr->data[0] == 2 );
		assert( arr->data[2] == 10 );

		int popped = DA_pop_back(arr);
		assert( popped == 7 );
		assert( arr->size == 6 );

		DA_clear(arr);
		assert( arr->size == 0 );
		assert( arr->capacity == 14 );
	}
	
	{ // Empty array
		int array[0] = {};
		DynArr *arr = DA_construct(array, 0);

		DA_reserve(arr, 100);
		assert( arr->capacity == 100 );

		DA_shrink_to_fit(arr);
		assert( arr->capacity == 0 );

		DA_push_back(arr, 1);
		assert( arr->data[0] == 1 );

		DA_erase(arr, 0);
		assert( arr->size == 0 );
	}

	{ // Try to break things maybe
		int array[1] = {12};
		DynArr *arr = DA_construct(array, 1);
		assert( arr->data[0] == 12 );

		DA_insert(arr, 10, 10);
		assert( arr->size == 1 && arr->capacity == 1 && arr->data[0] == 12 );

		DA_erase(arr, 100000);
		assert( arr->size == 1 && arr->capacity == 1 && arr->data[0] == 12 );
	}

	return 0;
}
