#include"vector.hpp"

vector::vector() : pArr(0), N(0) { }

status_t vector::push_back(int _data)
{
    N++;
    pArr = (int*)realloc(pArr, N * sizeof(int));
    if(NULL == pArr)
        {
            std::cout << "Error in memory allocation" << std::endl;
            exit(-1);
        }

    *(pArr + (N - 1)) = _data;

    return(SUCCESS);
}

void vector::show(const char* msg) const
{
    if(msg)
        std::cout << msg << std::endl;

    for(int i = 0; i < N; i++)
        std::cout << "arr[" << i << "] = " << *(pArr + i) << std::endl;
}

vector::~vector()
{
    free(pArr);
}

