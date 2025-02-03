#include<stdio.h>

/* Symbolic Constant */
#define SUCCESS           0
#define FAIL              1
#define LIST_EMPTY        3
#define LIST_INVALID_DATA 4
#define TRUE              1 
#define FALSE             0 

/* typedefs */
typedef int data_t;
typedef struct node_t node_t;
typedef node_t list_t;
typedef int status_t;
typedef int len_t;

/* node layout */
struct node_t
{
    int data;
    struct node_t* next;
    struct node_t* prev;
};

/* Interface functions declaration */
list_t* create_list(void);

status_t insert_start(list_t*, data_t);
status_t insert_end(list_t*, data_t);
status_t insert_after(list_t*, data_t, data_t);
status_t insert_before(list_t*, data_t, data_t);

status_t get_start(list_t*, data_t*);
status_t get_end(list_t*, data_t*);
status_t pop_start(list_t*, data_t*);
status_t pop_end(list_t*, data_t*);

status_t remove_start(list_t*);
status_t remove_end(list_t*);
status_t remove_data(list_t*, data_t r_data);

void show_list(list_t* p_list, const char* msg); 
len_t get_length(list_t*);
status_t is_list_empty(list_t*);
status_t destroy_list(list_t*);
status_t find(list_t* p_list, data_t f_data); 

/* List auxillary function */
static node_t* get_node(data_t);
static node_t* search_node(list_t*, int);
static void generic_insert(node_t*, node_t*, node_t*);
static void generic_delete(node_t* p_start, node_t* p_delete_node, node_t* p_next); 

/* General auxillary function declarations */
static void* xmalloc(size_t);
 

 











