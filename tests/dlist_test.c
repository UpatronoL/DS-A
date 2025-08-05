#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/dlist.h"

int main() {
    Node *node = dlist_newNode(4);
    assert(node);
    assert(!node->next);
    assert(!node->prev);
    assert(node->data == 4);

    DList *dlist = dlist_new();
    assert(dlist);
    assert(!dlist->head);
    assert(!dlist->tail);
    assert(dlist_isEmpty(dlist));

    dlist_push(&dlist, 1);
    dlist_push(&dlist, 2);
    assert(dlist->head->data == 2);
    assert(dlist->tail->data == 1);
    assert(dlist_length(dlist) == 2);

    dlist_append(&dlist, 3);
    assert(dlist->tail->data == 3);
    assert(dlist_length(dlist) == 3);

    dlist_insertAt(&dlist, 1, 99);
    assert(dlist_getAt(dlist, 1) == 99);
    assert(dlist_length(dlist) == 4);

    dlist_setAt(dlist, 1, 88);
    assert(dlist_getAt(dlist, 1) == 88);

    dlist_removeAt(&dlist, 1);
    assert(dlist_getAt(dlist, 1) != 88);
    assert(dlist_length(dlist) == 3);

    assert(dlist_contains(dlist, 3));
    assert(!dlist_contains(dlist, 88));
    assert(dlist_indexOf(dlist, 3) != -1);
    assert(dlist_indexOf(dlist, 88) == -1);

    dlist_print(dlist);
    dlist_reverse(&dlist);
    dlist_print(dlist);

    DList *copy = dlist_duplicate(dlist);
    assert(copy);
    assert(dlist_length(copy) == dlist_length(dlist));

    dlist_clear(&dlist);
    dlist_clear(&copy);
    assert(dlist);
    assert(copy);

    dlist_free(&dlist);
    dlist_free(&copy);
    assert(!dlist);
    assert(!copy);

    printf("All tests passed\n");
    return 0;
}
