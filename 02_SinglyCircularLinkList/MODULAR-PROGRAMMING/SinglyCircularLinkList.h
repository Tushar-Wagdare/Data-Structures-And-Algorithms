#pragma once

#define FALSE             0
#define SUCCESS           1
#define TRUE              1
#define LIST_EMPTY        2
#define LIST_INVALID_DATA 3

struct Node
{
    int data;
    struct Node* next;
};

struct Node* xmalloc(size_t);
struct Node* createList(void);
struct Node* getNode(int);
int insertEnd(struct Node*, int);
int insertStart(struct Node*, int);
int popStart(struct Node*, int*);
int popEnd(struct Node*, int*);
int removeStart(struct Node*);
int removeEnd(struct Node*);
int showList(struct Node*, char*);
int getStart(struct Node*, int*);
int getEnd(struct Node*, int*);
int getLength(struct Node*);
int isListEmpty(struct Node*);
int insertAfter(struct Node*, int, int);
int insertBefore(struct Node*, int, int);
int genericInsert(struct Node*, struct Node*, struct Node*);
int removeData(struct Node*, int);
int destroyList(struct Node*);
struct Node* concatLists(struct Node*, struct Node*);
struct Node* getReversedList(struct Node*);
int append(struct Node*, struct Node**);
struct Node* searchNode(struct Node*, int);
int getNodeAndItsPred(struct Node*, int, struct Node**, struct Node**);