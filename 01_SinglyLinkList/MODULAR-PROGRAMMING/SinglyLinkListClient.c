#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"SinglyLinkList.h"


int main(void)
{
    struct Node* pList = NULL; 
    int data; 
    int status; 
    int length; 

    puts("SINGLY LINKED LIST : "); 

    pList = createList(); 
    assert(pList != NULL); 

    assert(getStart(pList, &data) == LIST_EMPTY); 
    assert(popStart(pList, &data) == LIST_EMPTY); 
    assert(getEnd(pList, &data) == LIST_EMPTY); 
    assert(popEnd(pList, &data) == LIST_EMPTY); 
    assert(removeStart(pList) == LIST_EMPTY); 
    assert(removeEnd(pList) == LIST_EMPTY); 
    assert(getLength(pList) == 0); 
    assert(isListEmpty(pList) == TRUE); 
    puts("testing, getStart(), popStart(), getEnd(), popEnd(), removeStart(), removeEnd() on empty list...OK"); 
    puts("testing, getLength() on empty list ... ok ");
    puts("testing, isListEmpty() on empty list ... ok"); 
    showList(pList, "testing, empty list"); 

    for(data = 0; data <= 40; data = data + 10)
        insertStart(pList, data); 

    showList(pList, "testing, insertStart()"); 

    for(data = 50; data <= 100; data = data + 10)
        insertEnd(pList, data); 

    showList(pList, "testing, insertEnd()"); 

    puts("testing, insertAfter() for false case"); 
    status = insertAfter(pList, -300, 500); 
    assert(status == LIST_INVALID_DATA); 
    puts("testing, insertAfter() false case... ok"); 

    puts("testing insertBefore() for false case"); 
    status = insertBefore(pList, 8976, 500); 
    assert(status == LIST_INVALID_DATA); 
    puts("testing, insertBefore() false case ... ok"); 

    puts("testing insertAfter() and insertBefore() for valid data"); 
    status = insertAfter(pList, 0, 1000); 
    assert(status == SUCCESS); 
    status = insertBefore(pList, 0, 2000); 
    assert(status == SUCCESS); 

    showList(pList, "test, insertAfter(), insertBefore()... ok"); 

    status = getStart(pList, &data); 
    assert(status == SUCCESS); 
    printf("START OF LIST = %d\n", data); 
    showList(pList, "showing list after getStart()"); 

    status = getEnd(pList, &data); 
    assert(status == SUCCESS); 
    printf("END OF LIST = %d\n", data); 
    showList(pList, "showing list after getEnd()"); 

    status = popStart(pList, &data); 
    assert(status == SUCCESS); 
    printf("START OF LIST = %d\n", data); 
    showList(pList, "showing list after popStart()"); 

    status = popEnd(pList, &data); 
    assert(status == SUCCESS); 
    printf("END OF LIST = %d\n", data); 
    showList(pList, "showing list after popEnd()"); 

    status = removeStart(pList); 
    assert(status == SUCCESS); 
    showList(pList, "showing list after removeStart()"); 

    status = removeEnd(pList); 
    assert(status == SUCCESS); 
    showList(pList, "showing list after removeEnd()"); 

    puts("testing, getStart(), popStart(), getEnd(), popEnd(), removeStart(), removeEnd() on non-empty list...OK"); 

    length = getLength(pList); 
    printf("length = %d\n", length); 

    puts("testing removeData() for false case"); 
    status = removeData(pList, 1234); 
    assert(status == LIST_INVALID_DATA); 
    puts("testing remove data for false case ... ok"); 

    puts("testing removeData() for success case"); 
    status = removeData(pList, 0); 
    assert(status == SUCCESS); 
    puts("testing remove data for success case ... ok"); 
    showList(pList, "showing list after removing 0"); 

    assert(isListEmpty(pList) == FALSE); 
    puts("testing, isListEmpty() for non-empty list...ok"); 

    destroyList(pList); 
    pList = NULL;

    struct Node* pList_1 = createList(); 
    struct Node* pList_2 = createList(); 

    for(data = 10; data <= 50; data += 10)  
        insertEnd(pList_1, data); 

    for(data = 15; data <= 85; data += 10)
        insertEnd(pList_2, data); 

    struct Node* p_concat_list = concatLists(pList_1, pList_2); 

    showList(pList_1, "List 1:"); 
    showList(pList_2, "List 2:"); 
    showList(p_concat_list, "Concatenated list"); 

    struct Node* p_reversed_list = getReversedList(pList_2); 
    showList(p_reversed_list, "Reversed version of list 2"); 

    
    append(pList_1, &pList_2); 
    assert(pList_2 == NULL); 
    showList(pList_1, "After appending list 2 to list 1"); 

    destroyList(pList_1); 
    pList_1 = NULL; 

    destroyList(p_concat_list); 
    p_concat_list = NULL; 

    destroyList(p_reversed_list); 
    p_reversed_list = NULL;  

    puts("exiting from application:SUCCESS"); 
    return (EXIT_SUCCESS); 


    
    return(0);
}