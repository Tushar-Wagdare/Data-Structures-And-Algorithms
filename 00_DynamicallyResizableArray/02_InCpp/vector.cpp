#include<iostream>
#include<cstdlib>

#define SUCCESS 0
#define FAIL    1

typedef int status_t;


class Vector
{
    private:
        int* pArr;
        size_t N;

    public:
        Vector() : pArr(0), N(0) { }

        status_t push_back(int _data)
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

        void show(void) const
        {
            for(int i = 0; i < N; i++)
                std::cout << "arr[" << i << "] = " << *(pArr + i) << std::endl;
        }

        ~Vector()
        {
            free(pArr);
        }
};


int main(void)
{
    Vector* pVec = new Vector();

    for(int i = 1; i <= 5; i++)
        pVec->push_back(i * 100);

    pVec->show();

    delete pVec;
    pVec = 0;

    return(0);
}