// header inclusion
#include <stdio.h>
#include <stdlib.h>


// global function declaration
int BinSearch(int* arr, size_t arrSize, int key);


// entry point function
int main(void)
{
    // variable declaration
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    //indices:   0   1   2   3   4   5   6   7   8

    // code
    int key = 50;
    int index = BinSearch(arr, sizeof(arr) / sizeof(arr[0]), key);
    if(index < 0)
        printf("Key = %d not found...\n", key);
    else
        printf("Key = %d found at index = %d\n", key, index);

    key = 70;
    index = BinSearch(arr, sizeof(arr) / sizeof(arr[0]), key);
    if(index < 0)
        printf("Key = %d not found...\n", key);
    else
        printf("Key = %d found at index = %d\n", key, index);

    key = 110;
    index = BinSearch(arr, sizeof(arr) / sizeof(arr[0]), key);
    if(index < 0)
        printf("Key = %d not found...\n", key);
    else
        printf("Key = %d found at index = %d\n", key, index);


    return(0);
}


// function defination
int BinSearch(int* arr, size_t arrSize, int key)
{
    int low = 0;
    int high = arrSize - 1;
    int mid = (low + high) / 2;

    while(low <= high)
    {
        if(arr[mid] == key)
        {
            return(mid);           // key is found
        }
        else if(arr[mid] < key)
        {
            low = mid + 1;
            mid = (low + high) / 2;
        }
        else
        {
            high = mid - 1;
            mid = (low + high) / 2;
        }
    }

    return(-1); // if key not found return -1
}