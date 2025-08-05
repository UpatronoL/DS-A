#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
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
    List *tempList = *list;
    Node *temp = list_newNode(data);
    if (!tempList->head) {
        tempList->head = temp;
        tempList->tail = temp;
    } else {
        temp->next = tempList->head;
        tempList->head = temp;
    }
}

void list_append(List **list, int data) {
    List *tempList = *list;
    Node *temp = list_newNode(data);
    if (!tempList->head) {
        tempList->head = temp;
        tempList->tail = temp;
    } else {
        tempList->tail->next = temp;
        tempList->tail = temp;
    }
}

Node *list_pop(List **list) {
    List *tempList = *list;
    Node *temp = tempList->head;
    assert(temp);
    tempList->head = temp->next;
    if (tempList->head == NULL)
        tempList->tail = NULL;
    return temp;
}

Node *list_removeTail(List **list) {
    List *tempList = *list;
    Node *cur = tempList->head;
    if (!cur) return NULL;

    if (tempList->head == tempList->tail) {
        Node *temp = tempList->head;
        tempList->head = NULL;
        tempList->tail = NULL;
        return temp;
    }

    while (cur->next != tempList->tail) {
        cur = cur->next;
    }

    Node *temp = tempList->tail;
    tempList->tail = cur;
    cur->next = NULL;
    return temp;
}

void list_insertAt(List **list, int pos, int data) {
    List *tempList = *list;
    int len = list_length(tempList);
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
    Node *cur = tempList->head;
    for (int i = 1; i < pos; i++) {
        cur = cur->next;
    }
    Node *temp = list_newNode(data);
    temp->next = cur->next;
    cur->next = temp;
}

void list_removeAt(List **list, int pos) {
    List *tempList = *list;
    int len = list_length(tempList);
    if (pos < 0 || pos >= len) {
        printf("Error: Position out of bounds\n");
        exit(-1);
    }
    if (pos == 0) {
        Node *temp = list_pop(list);
        free(temp);
        return;
    }
    Node *cur = tempList->head;
    for (int i = 1; i < pos; i++) {
        cur = cur->next;
    }
    Node *temp = cur->next;
    cur->next = temp->next;
    if (temp == tempList->tail) tempList->tail = cur;
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
    List *tempList = *list;
    Node *cur = tempList->head;
    while (cur) {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
    free(tempList);
    *list = NULL;
}

void list_reverse(List **list) {
    List *tempList = *list;
    Node *prev = NULL;
    Node *cur = tempList->head;
    Node *next = NULL;
    tempList->tail = tempList->head;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    tempList->head = prev;
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

List *array_toList(int array[], int size) {
    List *newList = list_new();
    for (int i = 0; i < size; i++) {
        list_append(&newList, array[i]);
    }
    return newList;
}
