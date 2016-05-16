#include "DoubleLinkedList.h"

PDoubleLinkedList DoubleLinkedList_create() {
    return calloc(1, sizeof(DoubleLinkedList));
}

STATUS DoubleLinkedList_free(PDoubleLinkedList pList) {
    STATUS retValue = STATUS_SUCCESS;
    CHK(pList != NULL, STATUS_NULL_ARG);
    PListNode pNode = pList->first;
    while (pNode != NULL) {
        free(pNode->prev);
        pNode = pNode->next;
    }
    free(pList->last);
    free(pList);

CleanUp:
    return retValue;
}

STATUS DoubleLinkedList_push(PDoubleLinkedList pList, PVOID value) {
    STATUS retValue = STATUS_SUCCESS;
    CHK(pList != NULL, STATUS_NULL_ARG);

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

CleanUp:
    return retValue;
}

STATUS DoubleLinkedList_pop(PDoubleLinkedList pList, PVOID *pOutValue) {
    STATUS retValue = STATUS_SUCCESS;
    CHK(pList != NULL, STATUS_NULL_ARG);
    CHK(pList->last != NULL, DOUBLELINKEDLIST_STATUS_EMPTY_LIST);
    PListNode pNode = pList->last;
    retValue = DoubleLinkedList_remove(pList, pNode, pOutValue);
CleanUp:
    return retValue;
}

VOID DoubleLinkedList_unshift(PDoubleLinkedList pList) {

}

VOID DoubleLinkedList_shift(PDoubleLinkedList pList) {

}

STATUS DoubleLinkedList_remove(PDoubleLinkedList pList, PListNode pNode, PVOID *pOutValue) {
    STATUS retValue = STATUS_SUCCESS;
    CHK(pList != NULL, STATUS_NULL_ARG);
    CHK(pNode != NULL, STATUS_NULL_ARG);
    CHK((pList->first != NULL) && (pList->last != NULL),
        DOUBLELINKEDLIST_STATUS_EMPTY_LIST);

    if (pNode == pList->first && pNode == pList->last) {
        pList->first = NULL;
        pList->last = NULL;
    } else if (pNode == pList->first) {
        pList->first = pNode->next;
        pList->first->prev = NULL;
    } else if (pNode == pList->last) {
        pList->last = pNode->prev;
        pList->last->next = NULL;
    } else {
        PListNode after = pNode->next;
        PListNode before = pNode->prev;
        after->prev = before;
        before->next = after;
    }

    pList->length--;
    *pOutValue = pNode->value;
    free(pNode);

CleanUp:
    return retValue;
}