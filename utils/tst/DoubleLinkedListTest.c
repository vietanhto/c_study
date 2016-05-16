#include "common/MinUnit.h"
#include "utils/src/DoubleLinkedList.h"

int tests_run = 0;

PCHAR DoubleLinkedList_ListNodeTest() {
    PListNode pNode = (PListNode) malloc(sizeof(ListNode));
    pNode->value = (PVOID)6;
    MU_ASSERT ("Test value", 6 == (UINT64)pNode->value);
    free(pNode);
    return NULL;
}

PCHAR DoubleLinkedList_DoubleLinkedListTest() {
    PDoubleLinkedList pList = DoubleLinkedList_create();
    MU_ASSERT("First node should be null", DoubleLinkedList_first(pList) ==  NULL);
    MU_ASSERT("Last node should be null", DoubleLinkedList_last(pList) ==  NULL);
    MU_ASSERT("Length should be 0", DoubleLinkedList_length(pList) ==  0);
    MU_ASSERT("Should be able to free", STATUS_SUCCESS == DoubleLinkedList_free(pList));
    MU_ASSERT("Should be able to handle null", STATUS_NULL_ARG == DoubleLinkedList_free(NULL));
    return NULL;
}

PCHAR DoubleLinkedList_pushTest() {
    PDoubleLinkedList pList = DoubleLinkedList_create();
    DoubleLinkedList_push(pList, (PVOID) 10);
    DoubleLinkedList_push(pList, (PVOID) 20);
    MU_ASSERT("Length should be 2", DoubleLinkedList_length(pList) ==  2);
    MU_ASSERT("First value should be 10", (UINT64)DoubleLinkedList_first(pList) ==  10);
    MU_ASSERT("Last should be 20", (UINT64)DoubleLinkedList_last(pList) ==  20);
    DoubleLinkedList_free(pList);
    return NULL;
}

PCHAR DoubleLinkedList_popTest() {
    PDoubleLinkedList pList = DoubleLinkedList_create();
    DoubleLinkedList_push(pList, (PVOID) 10);
    DoubleLinkedList_push(pList, (PVOID) 20);
    PVOID value;
    DoubleLinkedList_pop(pList, &value);
    MU_ASSERT("Popped value should be 20", (UINT64)value == 20);
    MU_ASSERT("Length should be 1", DoubleLinkedList_length(pList) ==  1);
    MU_ASSERT("First value should be 10", (UINT64)DoubleLinkedList_first(pList) ==  10);
    MU_ASSERT("Last should be 10", (UINT64)DoubleLinkedList_last(pList) ==  10);
    DoubleLinkedList_free(pList);
    return NULL;
}

static PCHAR all_tests() {
    MU_RUN_TEST(DoubleLinkedList_ListNodeTest);
    MU_RUN_TEST(DoubleLinkedList_DoubleLinkedListTest);
    MU_RUN_TEST(DoubleLinkedList_pushTest);
    MU_RUN_TEST(DoubleLinkedList_popTest);
    return NULL;
}

MU_RUN_TESTS(all_tests);