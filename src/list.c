#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct list {
    Node *head;
    Node *tail;
} List;

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
    if(!current) return 0;
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
    if(!templist->head) return NULL;

    if(templist->head == templist->tail) {
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
    printList(list);
    free(node);
    return 0;
}
