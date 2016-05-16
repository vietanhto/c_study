#ifndef UTILS_DOUBLELINKEDLIST_H
#define UTILS_DOUBLELINKEDLIST_H

#include "common/CommonDefinitions.h"

typedef struct ListNode {
    struct ListNode *next;
    struct ListNode *prev;
    PVOID value;
} ListNode, *PListNode;

typedef struct DoubleLinkedList {
    int length;
    PListNode first;
    PListNode last;
} DoubleLinkedList, *PDoubleLinkedList;

PDoubleLinkedList DoubleLinkedList_create();
VOID DoubleLinkedList_free(PDoubleLinkedList);

#define DoubleLinkedList_length(list) ((list)->length)
#define DoubleLinkedList_first(list) ((list)->first != NULL ? (list)->first->value : NULL) 
#define DoubleLinkedList_last(list) ((list)->last != NULL ? (list)->last->value : NULL)

VOID DoubleLinkedList_push(PDoubleLinkedList, PVOID);
PVOID DoubleLinkedList_pop(PDoubleLinkedList);
VOID DoubleLinkedList_unshift(PDoubleLinkedList);
VOID DoubleLinkedList_shift(PDoubleLinkedList);
VOID DoubleLinkedList_remove(PDoubleLinkedList);

#endif // UTILS_DOUBLELINKEDLIST_H