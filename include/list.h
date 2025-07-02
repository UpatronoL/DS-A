#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct list {
    Node *head;
    Node *tail;
} List;

Node *list_newNode(int data);
List *list_new(void);
int list_length(List *list);
void list_print(List *list);
void list_push(List **list, int data);
void list_append(List **list, int data);
Node *list_pop(List **list);
Node *list_removeTail(List **list);
void list_insertAt(List **list, int pos, int data);
void list_removeAt(List **list, int pos);
int list_getAt(List *list, int index);
void list_setAt(List *list, int index, int data);
bool list_contains(List *list, int data);
int list_indexOf(List *list, int data);
bool list_isEmpty(List *list);
void list_clear(List **list);
List *list_duplicate(List *list);
void list_reverse(List **list);

#endif
