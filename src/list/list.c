#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

int main() {
    List *list = newList();
    assert(list);
    assert(listLen(list) == 0);

    push(&list, 1);
    assert(list->head->data == 1);
    assert(list->tail->data == 1);
    assert(listLen(list) == 1);

    append(&list, 2);
    assert(list->head->data == 1);
    assert(list->tail->data == 2);
    assert(listLen(list) == 2);
    append(&list, 3);
    append(&list, 4);
    Node *node = removeTail(&list);
    assert(listLen(list) == 3);
    instertAt(&list, 1, 99);
    assert(listLen(list) == 4);
    printf("%d\n", getAt(list, 3));
    setAt(list, 2, 10);
    printList(list);
    printf("All Tests Passed\n");
    free(node);
    return 0;
}

Node *newNode(int data) {
    Node *temp = malloc(sizeof(Node));
    assert(temp);
    temp->data = data;
    temp->next = NULL;
    return temp;
}

List *newList(void) {
    List *temp = malloc(sizeof(List));
    assert(temp);
    temp->head = NULL;
    temp->tail = NULL;
    return temp;
}

int listLen(List *list) {
    int count = 0;
    Node *current = list->head;
    if (!current) return 0;
    while(current) {
        count++;
        current = current->next;
    }
    return count;
}

void printList(List *list) {
    Node *current = list->head;
    while (current) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void push(List **list, int data) {
    List *tempList = *list;
    Node *temp = newNode(data);
    assert(temp);
    if (!tempList->head) {
        tempList->head = temp;
        tempList->tail = temp;
    } else {
        temp->next = tempList->head;
        tempList->head = temp;
    }
}

void append(List **list, int data) {
    List *tempList = *list;
    Node *temp = newNode(data);
    assert(temp);
    if (!tempList->head) {
        tempList->head = temp;
        tempList->tail = temp;
    } else {
        tempList->tail->next = temp;
        tempList->tail = temp;
    }
}

Node *pop(List **list) {
    List *templist = *list;
    Node *temp = templist->head;
    assert(temp);
    templist->head = templist->head->next;
    return temp;
}

Node *removeTail(List **list) {
    List *templist = *list;
    Node *cur = templist->head;
    assert(cur);
    Node *temp = NULL;
    assert(!temp);
    if (!templist->head) return NULL;

    if (templist->head == templist->tail) {
        temp = templist->head;
        templist->head = NULL;
        templist->tail = NULL;
        return temp;
    }
    while(cur->next != templist->tail) {
        cur = cur->next; 
    }

    temp = templist->tail;
    templist->tail = cur;
    templist->tail->next = NULL;

    return temp;
}

void instertAt(List **list, int pos, int data) {
    List *templist = *list;
    Node *cur = templist->head;
    assert(cur);
    Node *temp = newNode(data);
    assert(temp);
    int len = listLen(templist);
    int curPos = 1;
    if (pos == 0) push(list, data);
    if (pos == len) append(list, data); 
    if (pos > len || pos < 0) {
        printf("Error: Position out of bounds\n");
        exit(-1);
    }
    while(curPos != pos) {
        cur = cur->next;
        curPos++;
    }
    temp->next = cur->next;
    cur->next = temp;
}

void removeAt(List **list, int pos) {
    List *templist = *list;
    Node *cur = templist->head;
    assert(cur);
    Node *temp = NULL;
    assert(!temp);
    int len = listLen(templist);
    int curPos = 1;
    if (pos == 0) pop(list);
    if (pos == len) removeTail(list); 
    if (pos > len || pos < 0) {
        printf("Error: Position out of bounds\n");
        exit(-1);
    }
    while(curPos != pos) {
        cur = cur->next;
        curPos++;
    }
    temp = cur->next;
    cur->next = cur->next->next;
    free(temp);
}

int getAt(List *list, int index) {
    Node *cur = list->head;
    int len = listLen(list);

    if (index < 0 || index >= len) {
        printf("Error: Position out of bounds\n");
        exit(-1);
    }
    if (index == len-1) return list->tail->data;

    for(int i = 0; i < index; i++) {
        cur = cur->next;
    }
    return cur->data;
}

void setAt(List *list,int index, int data) {
    Node *cur = list->head;
    int len = listLen(list);

    if (index < 0 || index >= len) {
        printf("Error: Position out of bounds\n");
        exit(-1);
    }
    if (index == len-1) list->tail->data = data;

    for(int i = 0; i < index; i++) {
        cur = cur->next;
    }
    cur->data = data;
}
