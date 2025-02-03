#include<stdio.h>
#include<stdlib.h>
#include"doubly_circular_link_list.h"

/* Interface functions declaration */
list_t* create_list(void)
{
    list_t* p_list = get_node(0);
    p_list->prev = p_list;
    p_list->next = p_list;

    return(p_list);
}

status_t insert_start(list_t* p_list, data_t data)
{
    generic_insert(p_list, get_node(data), p_list->next);

    return(SUCCESS);
}

status_t insert_end(list_t* p_list, data_t data)
{
    generic_insert(p_list->prev, get_node(data), p_list);

    return(SUCCESS);
}

status_t insert_after(list_t* p_list, data_t e_data, data_t new_data)
{
    node_t* e_node = NULL;
    e_node = search_node(p_list, e_data);
    if(NULL == e_node)
        return(LIST_INVALID_DATA);

    generic_insert(e_node, get_node(new_data), e_node->next);

    return(SUCCESS);
}

status_t insert_before(list_t* p_list, data_t e_data, data_t new_data)
{
    node_t* e_node = NULL;
    e_node = search_node(p_list, e_data);
    if(NULL == e_node)
        return(LIST_INVALID_DATA);

    generic_insert(e_node->prev, get_node(new_data), e_node);

    return(SUCCESS);
}

status_t get_start(list_t* p_list, data_t* p_data)
{
    if(is_list_empty(p_list) == TRUE)
        return(LIST_EMPTY);

    *p_data = p_list->next->data;

    return(SUCCESS);
}

status_t get_end(list_t* p_list, data_t* p_data)
{
    if(is_list_empty(p_list) == TRUE)
        return(LIST_EMPTY);

    *p_data = p_list->prev->data;

    return(SUCCESS);
}

status_t pop_start(list_t* p_list, data_t* p_data)
{
    if(is_list_empty(p_list) == TRUE)
        return(LIST_EMPTY);

    *p_data = p_list->next->data;

    generic_delete(p_list, p_list->next, p_list->next->next);

    return(SUCCESS);
}

status_t pop_end(list_t* p_list, data_t* p_data)
{
    if(is_list_empty(p_list) == TRUE)
        return(LIST_EMPTY);

    *p_data = p_list->prev->data;

    generic_delete(p_list->prev->prev, p_list->prev, p_list);

    return(SUCCESS);
}

status_t remove_start(list_t* p_list)
{
    if(is_list_empty(p_list) == TRUE)
        return(LIST_EMPTY);

    generic_delete(p_list, p_list->next, p_list->next->next);

    return(SUCCESS);
}

status_t remove_end(list_t* p_list)
{
     if(is_list_empty(p_list) == TRUE)
        return(LIST_EMPTY);

    generic_delete(p_list->prev->prev, p_list->prev, p_list);

    return(SUCCESS);
}

status_t remove_data(list_t* p_list, data_t r_data)
{
    node_t* e_node = NULL;
    e_node = search_node(p_list, r_data);
    if(NULL == e_node)
        return(LIST_INVALID_DATA);

    e_node->data = 0;

    return(SUCCESS);
}

void show_list(list_t* p_list, const char* msg)
{
    if(msg)
        puts(msg);
    
    printf("<-[HEAD]");
    for(node_t* run = p_list->next; run != p_list; run = run->next)
        printf("<->[%d]<->", run->data);

    printf("[END]->\n");
} 

len_t get_length(list_t* p_list)
{
    int len = 0;

    for(node_t* run = p_list->next; run != p_list; run = run->next)
    {
        len++;
    }

    return(len);
}

status_t is_list_empty(list_t* p_list)
{
    if(p_list == p_list->next)
        return(TRUE);

    return(FALSE);
}

status_t destroy_list(list_t* p_list)
{
    node_t* run_suc = NULL;
    for(node_t* run = p_list->next; run != p_list; run = run_suc)
    {
        run_suc = run->next;
        free(run);
    }

    free(p_list);
    p_list->prev = NULL;
    p_list->next = NULL;

    return(SUCCESS);
}

status_t find(list_t* p_list, data_t f_data)
{
    for(node_t* run = p_list->next; run != p_list; run = run->next)
    {
        if(run->data == f_data)
            return(SUCCESS);
    }

    return(FAIL);
} 

/* List auxillary function */
static node_t* get_node(data_t data)
{
    node_t* new_node = (node_t*)xmalloc(sizeof(node_t));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    return(new_node);
}

static node_t* search_node(list_t* p_list, data_t e_data)
{
    node_t* run = p_list->next;
    
    while(run != p_list)
    {
        if(run->data == e_data)
            return(run);

        run = run->next;
    }

    return(NULL);
}

static void generic_insert(node_t* start, node_t* mid, node_t* end)
{
    start->next = mid;
    mid->prev = start;
    mid->next = end;
    end->prev = mid;
}

static void generic_delete(node_t* p_start, node_t* p_delete_node, node_t* p_next)
{
    p_start->next = p_next;
    p_next->prev = p_start;

    free(p_delete_node);
    p_delete_node = NULL;
} 

/* General auxillary function declarations */
static void* xmalloc(size_t size)
{
    void* p_new_node = malloc(size);
    if(NULL == p_new_node)
    {
        puts("Error in memory allocation");
        exit(EXIT_FAILURE);
    }
    return(p_new_node);
}