#include "DoubleLinkedList.h"

PDoubleLinkedList DoubleLinkedList_create() {
    return calloc(1, sizeof(DoubleLinkedList));
}
VOID DoubleLinkedList_free(PDoubleLinkedList pList) {
    PListNode pNode = pList->first;
    while (pNode != NULL) {
        free(pNode->prev);
        pNode = pNode->next;
    }
    free(pList->last);
    free(pList);
}

VOID DoubleLinkedList_push(PDoubleLinkedList pList, PVOID value) {
    PListNode pNode = calloc(1, sizeof(ListNode));
    pNode->value = value;
    if (pList->last == NULL) {
        pList->first = pList->last = pNode;
    } else {
        pList->last->next = pNode;
        pNode->prev = pList->last;
        pList->last = pNode;
    }
    pList->length++;
}

PVOID DoubleLinkedList_pop(PDoubleLinkedList pList) {

}

VOID DoubleLinkedList_unshift(PDoubleLinkedList pList) {

}

VOID DoubleLinkedList_shift(PDoubleLinkedList pList) {

}

VOID DoubleLinkedList_remove(PDoubleLinkedList pList) {

}