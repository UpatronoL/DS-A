#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

Node *list_newNode(int data) {
    Node *temp = malloc(sizeof(Node));
    assert(temp);
    temp->data = data;
    temp->next = NULL;
    return temp;
}

List *list_new(void) {
    List *temp = malloc(sizeof(List));
    assert(temp);
    temp->head = NULL;
    temp->tail = NULL;
    return temp;
}

int list_length(List *list) {
    int count = 0;
    Node *current = list->head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

void list_print(List *list) {
    Node *current = list->head;
    while (current) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void list_push(List **list, int data) {
    Node *temp = list_newNode(data);
    if (!(*list)->head) {
        (*list)->head = temp;
        (*list)->tail = temp;
    } else {
        temp->next = (*list)->head;
        (*list)->head = temp;
    }
}

void list_append(List **list, int data) {
    Node *temp = list_newNode(data);
    if (!(*list)->head) {
        (*list)->head = temp;
        (*list)->tail = temp;
    } else {
        (*list)->tail->next = temp;
        (*list)->tail = temp;
    }
}

Node *list_pop(List **list) {
    Node *temp = (*list)->head;
    assert(temp);
    (*list)->head = temp->next;
    return temp;
}

Node *list_removeTail(List **list) {
    Node *cur = (*list)->head;
    if (!cur) return NULL;

    if ((*list)->head == (*list)->tail) {
        Node *temp = (*list)->head;
        (*list)->head = NULL;
        (*list)->tail = NULL;
        return temp;
    }

    while (cur->next != (*list)->tail) {
        cur = cur->next;
    }

    Node *temp = (*list)->tail;
    (*list)->tail = cur;
    cur->next = NULL;
    return temp;
}

void list_insertAt(List **list, int pos, int data) {
    int len = list_length(*list);
    if (pos < 0 || pos > len) {
        printf("Error: Position out of bounds\n");
        exit(-1);
    }
    if (pos == 0) {
        list_push(list, data);
        return;
    }
    if (pos == len) {
        list_append(list, data);
        return;
    }
    Node *cur = (*list)->head;
    for (int i = 1; i < pos; i++) {
        cur = cur->next;
    }
    Node *temp = list_newNode(data);
    temp->next = cur->next;
    cur->next = temp;
}

void list_removeAt(List **list, int pos) {
    int len = list_length(*list);
    if (pos < 0 || pos >= len) {
        printf("Error: Position out of bounds\n");
        exit(-1);
    }
    if (pos == 0) {
        Node *temp = list_pop(list);
        free(temp);
        return;
    }
    Node *cur = (*list)->head;
    for (int i = 1; i < pos; i++) {
        cur = cur->next;
    }
    Node *temp = cur->next;
    cur->next = temp->next;
    if (temp == (*list)->tail) (*list)->tail = cur;
    free(temp);
}

int list_getAt(List *list, int index) {
    int len = list_length(list);
    if (index < 0 || index >= len) {
        printf("Error: Position out of bounds\n");
        exit(-1);
    }
    Node *cur = list->head;
    for (int i = 0; i < index; i++) {
        cur = cur->next;
    }
    return cur->data;
}

void list_setAt(List *list, int index, int data) {
    int len = list_length(list);
    if (index < 0 || index >= len) {
        printf("Error: Position out of bounds\n");
        exit(-1);
    }
    Node *cur = list->head;
    for (int i = 0; i < index; i++) {
        cur = cur->next;
    }
    cur->data = data;
}

bool list_contains(List *list, int data) {
    Node *cur = list->head;
    while (cur) {
        if (cur->data == data) return true;
        cur = cur->next;
    }
    return false;
}

int list_indexOf(List *list, int data) {
    Node *cur = list->head;
    int index = 0;
    while (cur) {
        if (cur->data == data) return index;
        cur = cur->next;
        index++;
    }
    return -1;
}

bool list_isEmpty(List *list) {
    return (list == NULL || list->head == NULL);
}

void list_clear(List **list) {
    Node *cur = (*list)->head;
    while (cur) {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
    free(*list);
    *list = NULL;
}

void list_reverse(List **list) {
    Node *prev = NULL;
    Node *cur = (*list)->head;
    Node *next = NULL;
    (*list)->tail = (*list)->head;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    (*list)->head = prev;
}

List *list_duplicate(List *list) {
    List *copy = list_new();
    Node *cur = list->head;
    while (cur) {
        list_append(&copy, cur->data);
        cur = cur->next;
    }
    return copy;
}

int *list_toArray(List *list) {
    Node *cur = list->head;
    int size = list_length(list) + 1;
    int *array = malloc(size * sizeof(int));
    int i = 0;
    while(cur) {
        array[i] = cur->data;
        cur = cur->next;
        i++;
    }
    return array;
}

List *array_toList(int *array) {
    List *newList = list_new();
    int size = sizeof(array) / sizeof(int);
    for (int i = 0; i < size; i++) list_append(&list, array[i]);
    return newList;
}
