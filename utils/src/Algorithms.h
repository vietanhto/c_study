#ifndef UTILS_ALGORITHMS_H
#define UTILS_ALGORITHMS_H

#include "common/CommonDefinitions.h"
#include "DoubleLinkedList.h"

typedef INT32 (*ListCompare)(PVOID, PVOID);

STATUS List_bubble_sort(PDoubleLinkedList, ListCompare);

PDoubleLinkedList List_merge_sort(PDoubleLinkedList, ListCompare);

#endif // UTILS_ALGORITHMS_H