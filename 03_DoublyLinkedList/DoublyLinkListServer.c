#include<stdio.h>
#include<stdlib.h>
#include"DoublyLinkList.h"



struct Node* xmalloc(size_t size)
{
    struct Node* pHead = (struct Node*)malloc(size);
    if(NULL == pHead)
    {
        printf("Memory Allocation Error !!!");
        exit(0);
    }

    return(pHead);
}

 
struct Node* createList(void)
{
    struct Node* pHead = NULL;
    
    pHead = getNode(0);

    return(pHead);
}


struct Node* getNode(int data)
{
    struct Node* node = NULL;
    
    node = xmalloc(sizeof(struct Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;

    return(node);
}


void insertEnd(struct Node* pHead, int data)
{
    struct Node* run = pHead;
    struct Node* newNode = getNode(data);

    while(run->next != NULL)
        run = run->next;

    run->next = newNode;
    newNode->prev = run;
}


void showList(struct Node* pHead, char* message)
{
    struct Node* run = NULL;

    if(message != NULL)
        puts(message);

    printf("[START]->");
    for(run = pHead->next; run != NULL; run = run->next)
    {
        printf("[%d]->",run->data);
    }
    printf("[END]\n");
}
 

void insertStart(struct Node* pHead, int data)
{
    struct Node* node = getNode(data);
    if(pHead->next != NULL)
    {
        node->next = pHead->next;
        (pHead->next)->prev = node; 
    }
    pHead->next = node;
    node->prev = pHead;
}


int popStart(struct Node* pHead, int* data)
{
    struct Node* tempPtr = pHead->next;

    if(isListEmpty(pHead) == TRUE)
        return(LIST_EMPTY);

    *data = tempPtr->data;
    (tempPtr->next)->prev = pHead;
    pHead->next = tempPtr->next;
    free(tempPtr);
    tempPtr = NULL;
    
    return(SUCCESS);
}


int popEnd(struct Node* pHead, int* data)
{
    struct Node* run = pHead;

    if(isListEmpty(pHead) == TRUE)
        return(LIST_EMPTY);

    while(run->next != NULL)
        run = run->next;
    

    *data = run->data;
    (run->prev)->next = NULL;
    free(run);
    run = NULL;

    return(SUCCESS);
}


int removeStart(struct Node* pHead)
{
    struct Node* tempPtr = pHead->next;

    if(isListEmpty(pHead) == TRUE)
        return(LIST_EMPTY);

    pHead->next = tempPtr->next;
    (tempPtr->next)->prev = pHead;
    free(tempPtr);
    tempPtr = NULL;

    return(SUCCESS);
}


int removeEnd(struct Node* pHead)
{
    struct Node* run = pHead;

    if(isListEmpty(pHead) == TRUE)
        return(LIST_EMPTY);

    while(run->next != NULL)
        run = run->next;
    
    (run->prev)->next = NULL;
    free(run);
    run = NULL;

    return(SUCCESS);
}


int getStart(struct Node* pHead, int* data)
{
    if(isListEmpty(pHead) == TRUE)
        return(LIST_EMPTY);

    *data = (pHead->next)->data;

    return(SUCCESS);
}


int getEnd(struct Node* pHead, int* data)
{
    struct Node* run = pHead;

    if(isListEmpty(pHead) == TRUE)
        return(LIST_EMPTY);

    while(run->next != NULL)
        run = run->next;
    
    *data = run->data;

    return(SUCCESS);
}


int getLength(struct Node* pHead)
{
    struct Node* run = pHead;
    unsigned int number_of_nodes = 0;

    while(run->next != NULL)
    {
        number_of_nodes++;
        run = run->next;
    }

    return(number_of_nodes);
}


int isListEmpty(struct Node* pHead)
{
    if(pHead->next == NULL)
        return(TRUE);
    else
        return(FALSE);
}


int insertAfter(struct Node* pHead, int currentNodeData, int successorNewNodeData)
{
    struct Node* node = getNode(successorNewNodeData);
    struct Node* targetNode = searchNode(pHead, currentNodeData);

    if(targetNode == NULL)
        return(LIST_INVALID_DATA);
    

    genericInsert(targetNode, node, targetNode->next);

    return(SUCCESS);
}


int insertBefore(struct Node* pHead, int targetNodeData, int predNewNodeData)
{
    struct Node* node = getNode(predNewNodeData);
    struct Node* targetNode = NULL;

    getNodeAndItsPred(pHead, targetNodeData, &targetNode);
    if(targetNode == NULL)
        return(LIST_INVALID_DATA);

    genericInsert(targetNode->prev, node, targetNode);

    return(SUCCESS);
}


void genericInsert(struct Node* start, struct Node* mid, struct Node* end)
{
    start->next = mid;
    mid->next = end;
    mid->prev = start;
    end->prev = mid;
}


int removeData(struct Node* pHead, int dataOfNodeToRemove)
{
    struct Node* run = pHead->next;

    while(run != NULL)
    {
        if(run->data == dataOfNodeToRemove)
            break;
    
        run = run->next;
    }

    if(run == NULL)
        return(LIST_INVALID_DATA);

    (run->prev)->next = run->next;
    (run->next)->prev = run->prev;
    free(run);
    run = NULL;

    return(SUCCESS);
}


void destroyList(struct Node* pHead)
{
    struct Node* run = pHead;
    struct Node* runSuccessor = NULL;

    while(run->next != NULL)
    {
        runSuccessor = run->next;
        free(run);
        run = runSuccessor;
    }
}


struct Node* concatLists(struct Node* pList_1, struct Node* pList_2)
{
    struct Node* pNewList = createList();
    struct Node* run = pList_1;

    while(run->next != NULL)
    {
        run = run->next;
        insertEnd(pNewList, run->data);
    }

    run = pList_2;
    while(run->next != NULL)
    {
        run = run->next;
        insertEnd(pNewList, run->data);
    }

    return(pNewList);
}


struct Node* getReversedList(struct Node* pList)
{
    struct Node* pNewList = createList();
    struct Node* run = pList;

    while(run->next != NULL)
    {
        run = run->next;
        insertStart(pNewList, run->data);
    }

    return(pNewList);
}


void append(struct Node* pList_1, struct Node** pList_2)
{
    struct Node* run = pList_1;

    while(run->next != NULL)
        run = run->next;
    
    run->next = (*pList_2)->next;
    run->next->prev = run;

    free(*pList_2);
    *pList_2 = NULL;
}


struct Node* searchNode(struct Node* pHead, int dataToSearch)
{
    struct Node* run = pHead->next;

    while(run != NULL)
    {
        if(run->data == dataToSearch)
            break;
        
        run = run->next;
    }

    return(run);
}


void getNodeAndItsPred(struct Node* pHead, int targetData, struct Node** targetNode)
{
    struct Node* run = pHead->next;

    while(run != NULL)
    {
        if(run->data == targetData)
            break;

        run = run->next;
    }

    *targetNode = run;
}