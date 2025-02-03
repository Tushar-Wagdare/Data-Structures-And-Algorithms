#include <stdio.h>

#define SWAP(a,b,t)   (t=a, a=b, b=t)



void selection_sort(int* arr, int arr_size);

int main(void)
{
    int arr[10] = {100, 70, 30, 80, 50, 40, 20, 10, 60, 90};

    puts("before selection sort...");
    for(int i = 0; i < 10; ++i)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    selection_sort(arr, 10);

    puts("after selection sort...");
    for(int i = 0; i < 10; ++i)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    } 


    return(0);
}


void selection_sort(int* arr, int arr_size)
{
    int t;

    for(int i = 0; i < arr_size-1; ++i)
    {
        for(int j = i+1; j < arr_size; j++)
        {
            if(arr[i] > arr[j])
                SWAP(arr[i], arr[j], t);
        }
    }
}