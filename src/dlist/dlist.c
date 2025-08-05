#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/dlist.h"


Node *dlist_newNode(int data) {
    Node *temp = malloc(sizeof(Node));
    if (!temp) exit(EXIT_FAILURE);
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

DList *dlist_new(void) {
    DList *temp = malloc(sizeof(DList));
    if (!temp) exit(EXIT_FAILURE);
    temp->head = NULL;
    temp->tail = NULL;
    return temp;
}

bool dlist_isEmpty(DList *dlist) {
    if (!dlist) return true;
    return (dlist->head == NULL && dlist->tail == NULL);
}

int dlist_length(DList *dlist) {
    if (!dlist) exit(EXIT_FAILURE);
    int len = 0;
    Node *cur = dlist->head;
    while (cur) {
        len++;
        cur = cur->next;
    }
    return len;
}

void dlist_print(DList *dlist) {
    if (dlist_isEmpty(dlist)) {
        printf("List is empty or null\n");
        return;
    }
    Node *cur = dlist->head;
    while (cur) {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

void dlist_printReverse(DList *dlist) {
    if (dlist_isEmpty(dlist)) {
        printf("List is empty or null\n");
        return;
    }
    Node *cur = dlist->tail;
    while (cur) {
        printf("%d -> ", cur->data);
        cur = cur->prev;
    }
    printf("NULL\n");
}

void dlist_push(DList **dlist, int data) {
    if (dlist_isEmpty(*dlist)) exit(EXIT_FAILURE);
    DList *temp = *dlist;
    Node *node = dlist_newNode(data);
    node->next = temp->head;

    if (!temp->head) {
        temp->head = temp->tail = node;
    } else {
        temp->head->prev = node;
        temp->head = node;
    }
}

void dlist_append(DList **dlist, int data) {
    if (dlist_isEmpty(*dlist)) exit(EXIT_FAILURE);
    DList *temp = *dlist;
    Node *node = dlist_newNode(data);
    node->prev = temp->tail;

    if (!temp->tail) {
        temp->head = temp->tail = node;
    } else {
        temp->tail->next = node;
        temp->tail = node;
    }
}

Node *dlist_popFront(DList **dlist) {
    if (dlist_isEmpty(*dlist)) return NULL;
    DList *temp = *dlist;
    Node *node = temp->head;

    if (temp->head == temp->tail) {
        temp->head = temp->tail = NULL;
    } else {
        temp->head = node->next;
        temp->head->prev = NULL;
    }

    node->next = NULL;
    node->prev = NULL;
    return node;
}

Node *dlist_popBack(DList **dlist) {
    if (dlist_isEmpty(*dlist)) return NULL;
    DList *temp = *dlist;
    Node *node = temp->tail;

    if (temp->head == temp->tail) {
        temp->head = temp->tail = NULL;
    } else {
        temp->tail = node->prev;
        temp->tail->next = NULL;
    }

    node->next = NULL;
    node->prev = NULL;
    return node;
}

void dlist_insertAt(DList **dlist, int index, int data) {
    if (dlist_isEmpty(*dlist)) {
        printf("The list is empty\n");
        exit(-1);
    }
    DList *temp = *dlist;

    int len = dlist_length(temp);
    if (index < 0 || index > len) {
        printf("Index out of bounds\n");
        exit(-1);
    }

    if (index == 0) {
        dlist_push(dlist, data);
        return;
    }

    if (index == len) {
        dlist_append(dlist, data);
        return;
    }

    Node *node = dlist_newNode(data);
    Node *cur;
    int mid = len / 2;

    if (index <= mid) {
        cur = temp->head;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
    } else {
        cur = temp->tail;
        for (int i = len - 1; i > index; i--) {
            cur = cur->prev;
        }
    }

    node->next = cur;
    node->prev = cur->prev;

    if (cur->prev) cur->prev->next = node;
    cur->prev = node;
}

void dlist_removeAt(DList **dlist, int index) {
     if (dlist_isEmpty(*dlist)) {
        printf("The list is empty\n");
        exit(-1);
    }
    DList *temp = *dlist;

    int len = dlist_length(temp);
    if (index < 0 || index > len) {
        printf("Index out of bounds\n");
        exit(-1);
    }

    if (index == 0) {
        dlist_popFront(dlist);
        return;
    }

    if (index == len) {
        dlist_popBack(dlist);
        return;
    }

    Node *cur, *node;
    int mid = len / 2;

    if (index <= mid) {
        cur = temp->head;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
    } else {
        cur = temp->tail;
        for (int i = len - 1; i > index; i--) {
            cur = cur->prev;
        }
    }
    node = cur;
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    free(node);
}
