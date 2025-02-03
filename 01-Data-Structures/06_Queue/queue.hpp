#ifndef _QUEUE_HPP
#define _QUEUE_HPP

#include "list.hpp"

const int QUEUE_EMPTY = LIST_EMPTY;

class queue
{
    private:
        ttw::list* p_queue;

    public:
        queue();
        ~queue();
        status_t enqueue(data_t data);
        status_t peek(data_t* p_data);
        status_t dequeue(data_t* p_data);
        bool is_queue_empty(void);
};

#endif // _QUEUE_HPP
