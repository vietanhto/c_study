#include "DoubleLinkedList.h"

PDoubleLinkedList DoubleLinkedList_create() {
    return calloc(1, sizeof(DoubleLinkedList));
}

STATUS DoubleLinkedList_free(PDoubleLinkedList list) {
    STATUS retValue = STATUS_SUCCESS;
    CHK(list != NULL, STATUS_NULL_ARG);
    PListNode node = list->first;
    while (node != NULL) {
        free(node->prev);
        node = node->next;
    }
    free(list->last);
    free(list);

CleanUp:
    return retValue;
}

STATUS DoubleLinkedList_push(PDoubleLinkedList list, PVOID value) {
    STATUS retValue = STATUS_SUCCESS;
    CHK(list != NULL, STATUS_NULL_ARG);

    PListNode node = calloc(1, sizeof(ListNode));
    node->value = value;
    if (list->last == NULL) {
        list->first = list->last = node;
    } else {
        list->last->next = node;
        node->prev = list->last;
        list->last = node;
    }
    list->length++;

CleanUp:
    return retValue;
}

STATUS DoubleLinkedList_pop(PDoubleLinkedList list, PVOID *pOutValue) {
    STATUS retValue = STATUS_SUCCESS;
    CHK(list != NULL, STATUS_NULL_ARG);
    CHK(list->last != NULL, DOUBLELINKEDLIST_STATUS_EMPTY_LIST);
    PListNode node = list->last;
    retValue = DoubleLinkedList_remove(list, node, pOutValue);

CleanUp:
    return retValue;
}

STATUS DoubleLinkedList_unshift(PDoubleLinkedList list, PVOID value) {
    STATUS retValue = STATUS_SUCCESS;
    CHK(list != NULL, STATUS_NULL_ARG);

    PListNode node = calloc(1, sizeof(ListNode));
    node->value = value;
    if (list->first == NULL) {
        list->first = list->last = node;
    } else {
        list->first->prev = node;
        node->next = list->first;
        list->last = node;
    }
    list->length++;

CleanUp:
    return retValue;
}

STATUS DoubleLinkedList_shift(PDoubleLinkedList list, PVOID *pOutValue) {
    STATUS retValue = STATUS_SUCCESS;
    CHK(list != NULL, STATUS_NULL_ARG);
    CHK(list->last != NULL, DOUBLELINKEDLIST_STATUS_EMPTY_LIST);
    PListNode node = list->first;
    retValue = DoubleLinkedList_remove(list, node, pOutValue);

CleanUp:
    return retValue;
}

STATUS DoubleLinkedList_remove(PDoubleLinkedList list, PListNode node, PVOID *pOutValue) {
    STATUS retValue = STATUS_SUCCESS;
    CHK(list != NULL, STATUS_NULL_ARG);
    CHK(node != NULL, STATUS_NULL_ARG);
    CHK((list->first != NULL) && (list->last != NULL),
        DOUBLELINKEDLIST_STATUS_EMPTY_LIST);

    if (node == list->first && node == list->last) {
        list->first = NULL;
        list->last = NULL;
    } else if (node == list->first) {
        list->first = node->next;
        list->first->prev = NULL;
    } else if (node == list->last) {
        list->last = node->prev;
        list->last->next = NULL;
    } else {
        PListNode after = node->next;
        PListNode before = node->prev;
        after->prev = before;
        before->next = after;
    }

    list->length--;
    *pOutValue = node->value;
    free(node);

CleanUp:
    return retValue;
}