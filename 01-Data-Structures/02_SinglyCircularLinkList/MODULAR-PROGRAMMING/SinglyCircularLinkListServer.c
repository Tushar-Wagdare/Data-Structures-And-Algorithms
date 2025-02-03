#include<stdio.h>
#include<stdlib.h>
#include"SinglyCircularLinkList.h"



struct Node* xmalloc(size_t size)
{
    struct Node* pHead = (struct Node*)malloc(size);
    if(NULL == pHead)
    {
        printf("Memoru Allocation Error !!!");
        exit(0);
    }

    return(pHead);
}


struct Node* createList(void)
{
    struct Node* pHead = NULL;
    
    pHead = getNode(0);
    pHead->next = pHead;

    return(pHead);
}


struct Node* getNode(int data)
{
    struct Node* node = NULL;
    
    node = xmalloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;

    return(node);
}


int insertEnd(struct Node* pHead, int data)
{
    struct Node* run = pHead;
    struct Node* newEnd = getNode(data);

    while(run->next != pHead)
        run = run->next;

    run->next = newEnd;
    newEnd->next = pHead;

    return(SUCCESS);
}


int showList(struct Node* pHead, char* message)
{
    struct Node* run = NULL;

    if(message != NULL)
        puts(message);

    printf("[START]->");
    for(run = pHead->next; run != pHead; run = run->next)
    {
        printf("[%d]->",run->data);
    }
    printf("[END]\n");

    return(SUCCESS);
}
 

int insertStart(struct Node* pHead, int data)
{
    struct Node* node = getNode(data);
    genericInsert(pHead, node, pHead->next); 

    return(SUCCESS);
}


int popStart(struct Node* pHead, int* data)
{
    struct Node* tempPtr = pHead->next;

    if(isListEmpty(pHead) == TRUE)
        return(LIST_EMPTY);

    *data = tempPtr->data;
    pHead->next = tempPtr->next;
    free(tempPtr);
    tempPtr = NULL;
    
    return(SUCCESS);
}


int popEnd(struct Node* pHead, int* data)
{
    struct Node* run = pHead->next;
    struct Node* runPred = pHead;

    if(isListEmpty(pHead) == TRUE)
        return(LIST_EMPTY);

    while(run->next != pHead)
    {
        runPred = run;
        run = run->next;
    }

    *data = run->data;
    free(run);
    run = NULL;

    runPred->next = pHead;

    return(SUCCESS);
}


int removeStart(struct Node* pHead)
{
    struct Node* tempPtr = pHead->next;

    if(isListEmpty(pHead) == TRUE)
        return(LIST_EMPTY);

    pHead->next = tempPtr->next;
    free(tempPtr);
    tempPtr = NULL;

    return(SUCCESS);
}


int removeEnd(struct Node* pHead)
{
    struct Node* run = pHead->next;
    struct Node* runPred = pHead;

    if(isListEmpty(pHead) == TRUE)
        return(LIST_EMPTY);

    while(run->next != pHead)
    {
        runPred = run;
        run = run->next;
    }

    free(run);
    run = NULL;
    runPred->next = pHead;

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

    while(run->next != pHead)
        run = run->next;
    
    *data = run->data;

    return(SUCCESS);
}


int getLength(struct Node* pHead)
{
    struct Node* run = pHead;
    unsigned int number_of_nodes = 0;

    while(run->next != pHead)
    {
        number_of_nodes++;
        run = run->next;
    }

    return(number_of_nodes);
}


int isListEmpty(struct Node* pHead)
{
    if(pHead->next == pHead)
        return(TRUE);
    else
        return(FALSE);
}


int insertAfter(struct Node* pHead, int currentNodeData, int successorNewNodeData)
{
    struct Node* node = getNode(successorNewNodeData);
    struct Node* targetNode = searchNode(pHead, currentNodeData);

    if(targetNode == pHead)
        return(LIST_INVALID_DATA);
    

    genericInsert(targetNode, node, targetNode->next);

    return(SUCCESS);
}


int insertBefore(struct Node* pHead, int targetNodeData, int predNewNodeData)
{
    struct Node* node = getNode(predNewNodeData);
    struct Node* targetNode = NULL;
    struct Node* targetNodePred = NULL;

    getNodeAndItsPred(pHead, targetNodeData, &targetNode, &targetNodePred);
    if(targetNode == pHead)
        return(LIST_INVALID_DATA);

    genericInsert(targetNodePred, node, targetNode);

    return(SUCCESS);
}


int genericInsert(struct Node* start, struct Node* mid, struct Node* end)
{
    start->next = mid;
    mid->next = end;

    return(SUCCESS);
}


int removeData(struct Node* pHead, int dataOfNodeToRemove)
{
    struct Node* run = pHead->next;
    struct Node* runPred = pHead;

    while(run != pHead)
    {
        if(run->data == dataOfNodeToRemove)
            break;
        
        runPred = run;
        run = run->next;
    }

    if(run == pHead)
        return(LIST_INVALID_DATA);

    runPred->next = run->next;
    free(run);
    run = NULL;

    return(SUCCESS);
}


int destroyList(struct Node* pHead)
{
    struct Node* run = pHead->next;
    struct Node* runSuccessor = NULL;

    while(run != pHead)
    {
        runSuccessor = run->next;
        free(run);
        run = runSuccessor;
    }

    free(pHead);

    return(SUCCESS);
}


struct Node* concatLists(struct Node* pList_1, struct Node* pList_2)
{
    struct Node* pNewList = createList();
    struct Node* run = pList_1;

    while(run->next != pList_1)
    {
        run = run->next;
        insertEnd(pNewList, run->data);
    }

    run = pList_2;
    while(run->next != pList_2)
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

    while(run->next != pList)
    {
        run = run->next;
        insertStart(pNewList, run->data);
    }

    return(pNewList);
}


int append(struct Node* pList_1, struct Node** pList_2)
{
    struct Node* lastOfPList_2 = *pList_2;
    struct Node* run = pList_1;

    while(lastOfPList_2->next != *pList_2)
        lastOfPList_2 = lastOfPList_2->next;

    while(run->next != pList_1)
        run = run->next;
    
    run->next = (*pList_2)->next;
    lastOfPList_2->next = pList_1;

    free(*pList_2);
    *pList_2 = NULL;

    return(SUCCESS);
}


struct Node* searchNode(struct Node* pHead, int dataToSearch)
{
    struct Node* run = pHead->next;

    while(run != pHead)
    {
        if(run->data == dataToSearch)
            break;
        
        run = run->next;
    }

    return(run);
}


int getNodeAndItsPred(struct Node* pHead, int targetData, struct Node** targetNode, struct Node** predNode)
{
    struct Node* run = pHead->next;
    struct Node* runPred = pHead;

    while(run != pHead)
    {
        if(run->data == targetData)
            break;

        runPred = run;
        run = run->next;
    }

    *targetNode = run;
    *predNode = runPred;

    return(SUCCESS);
}


