#include "queue.hpp"

queue::queue()
{
    p_queue = new ttw::list();
}

queue::~queue()
{
    delete p_queue;
}

status_t queue::enqueue(data_t data)
{
    return p_queue->insert_end(data);
}

status_t queue::peek(data_t* p_data)
{
    return p_queue->get_start(p_data);
}

status_t queue::dequeue(data_t* p_data)
{
    return p_queue->pop_start(p_data);
}

bool queue::is_queue_empty(void)
{
    return p_queue->is_list_empty();
}
