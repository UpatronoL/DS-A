#ifndef DLIST_H
#define DLIST_H

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} Node;

typedef struct dlist {
    Node *head;
    Node *tail;
} DList;

Node *dlist_newNode(int data);
DList *dlist_new(void);

void dlist_push(DList **dlist, int data);
void dlist_append(DList **dlist, int data);
Node *dlist_popFront(DList **dlist);
Node *dlist_popBack(DList **dlist);

void dlist_insertAt(DList **dlist, int index, int data);
void dlist_removeAt(DList **dlist, int index);
int dlist_getAt(DList *dlist, int index);
void dlist_setAt(DList *dlist, int index, int data);

bool dlist_contains(DList *dlist, int data);
int dlist_indexOf(DList *dlist, int data);
bool dlist_isEmpty(DList *dlist);
int dlist_length(DList *dlist);

void dlist_reverse(DList **dlist);
void dlist_clear(DList **dlist);
void dlist_free(DList **dlist);
DList *dlist_duplicate(DList *dlist);

void dlist_print(DList *dlist);
void dlist_printReverse(DList *dlist);

#endif
