#include <stdio.h>

#define SWAP(a,b,t)   (t=a, a=b, b=t)



void selection_sort(int* arr, int arr_size);
int binary_search(int* arr, int search_num, int left, int right);

int main(void)
{
    int arr[10] = {100, 70, 30, 80, 50, 40, 20, 10, 60};

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

    int search_num = 60;

    int binary_search_ret = binary_search(arr, search_num, 0, 10); 
    if(binary_search_ret == -1)
        printf("binary seaarch for %d in arr[] not found....", search_num);
    else
        printf("binary seaarch for %d in arr[] found at index = %d\n", search_num, binary_search_ret);
        

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

int binary_search(int* arr, int search_num, int left, int right)
{
    int middle = (int)(left + right) / 2;

    if(left <= right)
    {
        if(search_num > arr[middle])
        {
            left = middle + 1;
            return(binary_search(arr, search_num, left, right));
        }
        else if(search_num == arr[middle])
        {
            return(middle);
        }
        else if(search_num < arr[middle])
        {
            right = middle - 1;
            return(binary_search(arr, search_num, left, right));
        }
    }
    
    

    return(-1);
}