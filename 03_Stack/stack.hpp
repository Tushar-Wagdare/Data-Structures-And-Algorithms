#ifndef _STACK_HPP
#define _STACK_HPP

#include "list.hpp"

const int STACK_EMPTY = LIST_EMPTY;

class stack
{
    private:
        ttw::list* p_list;

    public:
        stack();
        ~stack();
        status_t push(int data);
        status_t pop(int* data);
        status_t top(int* data) const;
        bool is_empty(void) const;
};


#endif  // _STACK_HPP