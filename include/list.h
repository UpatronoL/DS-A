#ifndef LIST_H
#define LIST_H

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct list {
    Node *head;
    Node *tail;
} List;

Node *newNode(int data);
List *newList(void);
int listLen(List *list);
void printList(List *list);
void push(List **list, int data);
void append(List **list, int data);
Node *pop(List **list);
Node *removeTail(List **list);
void instertAt(List **list, int pos, int data);
void removeAt(List **list, int pos);
int getAt(List *list, int index);
void setAt(List *list,int index, int data);

#endif
