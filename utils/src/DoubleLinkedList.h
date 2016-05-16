#ifndef UTILS_DOUBLELINKEDLIST_H
#define UTILS_DOUBLELINKEDLIST_H

#include "common/CommonDefinitions.h"

#define DOUBLELINKEDLIST_STATUS_BASE                     0x80000000
#define DOUBLELINKEDLIST_STATUS_EMPTY_LIST               DOUBLELINKEDLIST_STATUS_BASE + 0x00000001

typedef struct ListNode {
    struct ListNode *next;
    struct ListNode *prev;
    PVOID value;
} ListNode, *PListNode;

typedef struct DoubleLinkedList {
    UINT32 length;
    PListNode first;
    PListNode last;
} DoubleLinkedList, *PDoubleLinkedList;

PDoubleLinkedList DoubleLinkedList_create();
STATUS DoubleLinkedList_free(PDoubleLinkedList);

#define DoubleLinkedList_length(list) ((list)->length)
#define DoubleLinkedList_first(list) ((list)->first != NULL ? (list)->first->value : NULL) 
#define DoubleLinkedList_last(list) ((list)->last != NULL ? (list)->last->value : NULL)

STATUS DoubleLinkedList_push(PDoubleLinkedList, PVOID);
STATUS DoubleLinkedList_pop(PDoubleLinkedList, PVOID*);
VOID DoubleLinkedList_unshift(PDoubleLinkedList);
VOID DoubleLinkedList_shift(PDoubleLinkedList);
STATUS DoubleLinkedList_remove(PDoubleLinkedList, PListNode, PVOID*);

#endif // UTILS_DOUBLELINKEDLIST_H