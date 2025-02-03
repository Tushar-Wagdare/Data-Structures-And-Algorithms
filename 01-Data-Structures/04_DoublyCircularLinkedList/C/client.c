#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include "doubly_circular_link_list.h"

int main(void){
    list_t* lst = NULL; 
    status_t status; 
    data_t data; 
    len_t lst_length = 0; 

    lst = create_list();
    assert(get_start(lst, &data) == LIST_EMPTY); 
    assert(get_end(lst, &data) == LIST_EMPTY); 
    assert(pop_start(lst, &data) == LIST_EMPTY); 
    assert(pop_end(lst, &data) == LIST_EMPTY); 
    assert(remove_start(lst) == LIST_EMPTY); 
    assert(remove_end(lst) == LIST_EMPTY); 
    assert(get_length(lst) == 0); 

    show_list(lst, "List just after creation:"); 

    status = insert_start(lst, 100); 
    assert(status == SUCCESS); 
    show_list(lst, "List after insert_start(lst, 100):"); 

    status = insert_end(lst, 200); 
    assert(status == SUCCESS); 
    show_list(lst, "List after insert_end(lst, 200):"); 

    for(data = 1500; data <= 9500; data += 1000)
        assert(insert_end(lst, data) == SUCCESS); 
    show_list(lst, "List after adding 1500 to 9500 (with step 1000) at the end:"); 

    status = insert_after(lst, 100, 300); 
    assert(status == SUCCESS); 
    show_list(lst, "List after insert_after(lst, 100, 300):"); 

    status = insert_after(lst, -500, 400); 
    assert(status == LIST_INVALID_DATA); 

    status = insert_before(lst, 200, 1000); 
    assert(status == SUCCESS); 
    show_list(lst, "List after insert_before(lst, 200, 1000)"); 

    status = insert_before(lst, -4000, 2000); 
    assert(status == LIST_INVALID_DATA); 

    status = get_start(lst, &data); 
    assert(status == SUCCESS); 
    printf("start data: %d\n", data); 

    status = get_end(lst, &data); 
    assert(status == SUCCESS); 
    printf("end data: %d\n", data); 

    status = pop_start(lst, &data); 
    assert(status == SUCCESS); 
    printf("poped data at start: %d\n", data); 
    show_list(lst, "List after pop_start(lst, &data):"); 

    status = pop_end(lst, &data); 
    assert(status == SUCCESS); 
    printf("poped data at end = %d\n", data); 
    show_list(lst, "List after pop_end(lst, &data):"); 

    status = remove_start(lst); 
    assert(status == SUCCESS); 
    show_list(lst, "List after remove_start(lst):"); 

    status = remove_end(lst); 
    assert(status == SUCCESS); 
    show_list(lst, "List after remove_end(lst):"); 

    status = remove_data(lst, 5500); 
    assert(status == SUCCESS);       
    show_list(lst, "List after remove_data(lst, 5500):"); 

    status = remove_data(lst, -48921); 
    assert(status == LIST_INVALID_DATA); 

    lst_length = get_length(lst); 
    printf("List length = %d\n", lst_length); 

    status = find(lst, 2500); 
    if(status == SUCCESS)
        puts("2500 is present in the list"); 
    else 
        puts("find(lst, 2500): Unexpected error"); 

    status = find(lst, -43636); 
    if(status == LIST_INVALID_DATA)
        puts("-43636 is not present in the list"); 
    else 
        puts("find(lst, -43636): Unexpected error");

    status = is_list_empty(lst); 
    assert(status == FALSE); 

    status = destroy_list(lst); 
    assert(status == SUCCESS); 
    puts("List is destroyed successfully"); 
    puts("Unit tests: all ok"); 

    return (EXIT_SUCCESS); 
}