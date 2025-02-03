#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int* pArr = NULL;
    size_t arrSize = 5;

    pArr = (int*)calloc(arrSize, sizeof(int));
    if(NULL == pArr)
    {
        printf("Error in memory allocation for malloc");
        return(EXIT_FAILURE);
    }
    else
    {
        printf("Memory allocation successfull at base address %p\n", pArr);
    }

    for(int i = 0; i < arrSize; ++i)
        pArr[i] = i * 100;
    
    for(int i = 0; i < arrSize; ++i)
        printf("pArr[%d] = %d\n", i, pArr[i]);

    
    arrSize = 8;
    pArr = (int*)realloc(pArr, arrSize * sizeof(int));
    if(NULL == pArr)
    {
        printf("Error in memory allocation for realloc");
        return(EXIT_FAILURE);
    }
    else
    {
        printf("Memory reallocation successfull at base address %p\n", pArr);
    }

    pArr[5] = 500;
    pArr[6] = 600;
    pArr[7] = 700;

    for(int i = 0; i < arrSize; ++i)
        printf("pArr[%d] = %d\n", i, pArr[i]);

    free(pArr);
    pArr = NULL;


    return(0);
}

