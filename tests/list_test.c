#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
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
    assert(list->tail->data == 2);
    assert(list_length(list) == 2);

    list_append(&list, 3);
    list_append(&list, 4);
    assert(list_length(list) == 4);

    Node *removed = list_removeTail(&list);
    assert(removed->data == 4);
    free(removed);
    assert(list_length(list) == 3);

    list_insertAt(&list, 1, 99);
    assert(list_getAt(list, 1) == 99);
    assert(list_length(list) == 4);

    list_setAt(list, 2, 10);
    assert(list_getAt(list, 2) == 10);

    assert(list_contains(list, 10));
    assert(!list_contains(list, 9));
    assert(list_indexOf(list, 10) == 2);
    assert(list_indexOf(list, 9) == -1);

    list_reverse(&list);
    list_print(list);

    List *copy = list_duplicate(list);
    assert(copy);
    assert(list_length(copy) == list_length(list));

    int array[] = {7, 8, 9};
    List *fromArray = array_toList(array, 3);
    assert(list_length(fromArray) == 3);
    int *toArray = list_toArray(fromArray);
    for (int i = 0; i < 3; i++) {
        assert(toArray[i] == array[i]);
    }
    free(toArray);

    list_clear(&list);
    list_clear(&copy);
    list_clear(&fromArray);
    assert(!list);
    assert(!copy);
    assert(!fromArray);

    printf("All list tests passed\n");
    return 0;
}

