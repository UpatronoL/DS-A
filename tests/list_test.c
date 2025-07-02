#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/list.h"

int main() {
    List *list = list_new();
    assert(list);
    assert(list_isEmpty(list));
    assert(list_length(list) == 0);

    list_push(&list, 1);
    assert(list->head->data == 1);
    assert(list->tail->data == 1);
    assert(!list_isEmpty(list));
    assert(list_length(list) == 1);

    list_append(&list, 2);
    assert(list->head->data == 1);
    assert(list->tail->data == 2);
    assert(list_length(list) == 2);

    list_append(&list, 3);
    list_append(&list, 4);
    Node *node = list_removeTail(&list);
    assert(list_length(list) == 3);

    list_insertAt(&list, 1, 99);
    assert(list_length(list) == 4);

    printf("%d\n", list_getAt(list, 3));
    list_setAt(list, 2, 10);

    assert(list_contains(list, 10));
    assert(!list_contains(list, 9));
    assert(list_indexOf(list, 10) == 2);
    assert(list_indexOf(list, 9) == -1);
    list_print(list);

    list_reverse(&list);
    list_print(list);

    List *list2 = list_duplicate(list);
    list_clear(&list);
    list_print(list2);
    list_clear(&list2);
    assert(!list);
    assert(!list2);

    printf("All Tests Passed\n");
    free(node);
    return 0;
}
