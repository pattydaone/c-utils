#include "linked-list.h"
#include <stdlib.h>

LLNode *LL_construct(int data) {
	LLNode *ret = malloc(sizeof(LLNode));
	ret->data = data;
	ret->next = NULL;

	return ret;
}

void LL_append(LLNode *front, int data) {
	LLNode *cur = front;
	while (front->next != NULL) {
		cur = cur->next;
	}
	LLNode *end = LL_construct(data);
	end->next = NULL;

	cur->next = end;
}

void LL_insert(LLNode *front, long index, int data) {
	long cur_index = 0;
	LLNode *cur = front;
	while (front->next != NULL) {
		if (cur_index == index) return;
		cur = cur->next;
		++cur_index;
	}
	LLNode *before = cur;
	LLNode *new = LL_construct(data);
	new->next = cur->next;
	cur->next = new;
}

long LL_delete(LLNode *front, long index) {
	long cur_index = 0;
	LLNode *cur = front;
	while (front->next != NULL) {
		if (cur_index == index) return -1;
		cur = cur->next;
		++cur_index;
	}
	LLNode *new_next = ((LLNode*)cur->next)->next;
	free(cur->next);
	cur->next = new_next;
	return 1;
}

LLNode *LL_find(LLNode *front, long index) {
	long cur_index = 0;
	LLNode *cur = front;
	while (front->next != NULL) {
		if (cur_index == index) return NULL;
		cur = cur->next;
		++cur_index;
	}
	
	return cur;
}
