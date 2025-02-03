#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TRUE    1
#define FALSE   0
#define SUCCESS 1
#define FAIL    0

typedef struct node node_t;
typedef struct bst bst_t;
typedef int status_t;
typedef int data_t;

struct node
{
    data_t data;
    struct node* left;
    struct node* right;
    struct node* parent;
};

struct bst
{
    node_t* root;
    int count;
};

void* xmalloc(size_t size);
node_t* get_node(data_t data);
bst_t* create_bst(void);
status_t insert_bst(bst_t* root, data_t data);


int main(void)
{



    return(0);
}

void* xmalloc(size_t size)
{
    void* ptr = malloc(size);
    if(!ptr)
    {
        puts("Memory allocation failed...");
        return(EXIT_FAILURE);
    }

    return(ptr);
}

node_t* get_node(data_t data)
{
    node_t* new_node = xmalloc(sizeof(node_t));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->parent = NULL;

    return(new_node);
}

bst_t* create_bst(void)
{
    bst_t* new_bst = (bst_t*)xmalloc(sizeof(bst_t));
    new_bst->count = 0;
    new_bst->root = NULL;

    return(new_bst);
}

status_t insert_bst(bst_t* bst, data_t data)
{
    node_t* new_node = get_node(data);
    node_t* run = NULL;
    node_t* run_pred = NULL;

    if(NULL == bst->root)
    {
        bst->root = new_node;
        bst->count++;

        return(SUCCESS);
    }

    run = bst->root;
    while(1)
    {
        if(data < run->data)
        {
            if(run->left != NULL)
                run = run->left;
            else
            {
                run->left = new_node;
                new_node->parent = run;
                break;
            }    
        }
        else
        {
            if(run->right != NULL)
                run = run->right;
            else
            {
                run->right = new_node;
                new_node->parent = run;
                break;
            }
        }
    }

    bst->count++;
    return(SUCCESS);
}

