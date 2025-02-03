#include<iostream>
#include<cstdlib>

#define SUCCESS 0
#define FAIL    1

typedef int status_t;


class vector
{
    private:
        int* pArr;
        size_t N;

    public:
        vector() : pArr(0), N(0) { }

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

        void show(const char* msg) const
        {
            if(msg)
                std::cout << msg << std::endl;

            for(int i = 0; i < N; i++)
                std::cout << "arr[" << i << "] = " << *(pArr + i) << std::endl;
        }

        ~vector()
        {
            free(pArr);
        }
};



int main(void){
    vector* p_vector = new vector; 

    p_vector->push_back(100); 
    p_vector->show("after pushing back 100"); 
    
    p_vector->push_back(200); 
    p_vector->show("after pushing back 200"); 

    p_vector->push_back(300); 
    p_vector->show("after pushing back 300"); 

    p_vector->push_back(400); 
    p_vector->show("after pushing back 400"); 
    
    p_vector->push_back(500); 
    p_vector->show("after pushing back 500"); 

    delete p_vector; 
    p_vector = 0; 

    return (0); 
}