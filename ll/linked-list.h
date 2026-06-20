#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct {
	int data;
	void *next;
} LLNode;

LLNode *LL_construct(int data);

void LL_append(LLNode *front, int data);

void LL_insert(LLNode *front, long index, int data);

long LL_delete(LLNode *front, long index);

LLNode *LL_find(LLNode *front, long index);

#endif
