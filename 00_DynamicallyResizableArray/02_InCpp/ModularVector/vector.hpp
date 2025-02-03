#ifndef _VECTOR_HPP
#define _VECTOR_HPP

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
        vector();
        status_t push_back(int);
        void show(const char*) const;
        ~vector();
};


#endif  // _VECTOR_PP
