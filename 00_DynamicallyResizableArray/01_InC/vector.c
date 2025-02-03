#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


#define SUCCESS 0
#define FAIL    1


typedef int status_t;
typedef struct Vector
{
    int* pArr;
    size_t sSize;
}Vector;


status_t create_vector(Vector** _pVec)
{
    Vector* pVec = (Vector*)malloc(sizeof(Vector));
    if(pVec == NULL)
    {
        puts("Memory allocation failed...");
        exit(0);
    }

    pVec->pArr = (int*)malloc(sizeof(int));
    if(pVec->pArr == NULL)
    {
        puts("Memory allocation failed...");
        exit(0);
    }

    *pVec->pArr = 0;
    pVec->sSize = 1;

    *_pVec = pVec;

    return(SUCCESS);
}

status_t push_back(Vector** pVec, int val)
{
    (*pVec)->sSize++;
    (*pVec)->pArr = (int*)realloc((*pVec)->pArr, (*pVec)->sSize * sizeof(int));
    if(*pVec == NULL)
    {
        puts("Memory reallocation failed...");
        exit(0);
    }

    *((*pVec)->pArr + ((*pVec)->sSize)-1) = val;

    return(SUCCESS);
}

size_t size_of_vector(Vector* pVec)
{
    return(pVec->sSize);
}

void destroy_vector(Vector* pVec)
{
    free(pVec->pArr);
    pVec->pArr = NULL;

    free(pVec);
    pVec = NULL;
}

void show_vector(Vector* pVec)
{
    for(int i = 0; i < pVec->sSize; i++)
    {
        printf("pVec[%d] = %d\n", i, (pVec->pArr)[i]);
    }
}



int main(void)
{
    status_t status = FAIL;
    Vector* pVec = NULL;
    status = create_vector(&pVec);
    assert(status == SUCCESS);

    printf("%d\n", *pVec->pArr);

    for(int i = 1; i <= 5; i++)
    {
        status = push_back(&pVec, i * 100);
        assert(status == SUCCESS);
    }

    show_vector(pVec);

    destroy_vector(pVec);
    pVec = NULL;


    return(0);
}

