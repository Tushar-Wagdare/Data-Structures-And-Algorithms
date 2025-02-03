#include "stack.hpp"

stack::stack() : p_list(new ttw::list()) {}

stack::~stack()
{
    delete p_list;
}

status_t stack::push(int data)
{
    return p_list->insert_end(data);
}

status_t stack::pop(int* data)
{
    return p_list->pop_end(data);
}

status_t stack::top(int* data) const
{
    return p_list->get_end(data);
}

bool stack::is_empty(void) const
{
    return p_list->is_list_empty();
}

