#include <assert.h>
#include "stack.hpp"

int main(void)
{
    status_t result;
    stack* p_stack = new stack();

    assert(p_stack->is_empty() == true);
    puts("is_empty() on stack....ok");

    for(int i = 1; i < 6; ++i)
    {
        result = p_stack->push(i*100);
        assert(result == SUCCESS);
    }
    puts("push() on stack....ok");

    int data = 0;
    result = p_stack->top(&data);
    assert(result == SUCCESS);
    printf("top() = %d on stack....ok\n", data);

    result = p_stack->pop(&data);
    assert(result == SUCCESS);
    printf("pop() = %d on stack....ok\n", data);

    result = p_stack->pop(&data);
    assert(result == SUCCESS);
    printf("pop() = %d on stack....ok\n", data);

    result = p_stack->pop(&data);
    assert(result == SUCCESS);
    printf("pop() = %d on stack....ok\n", data);

    result = p_stack->pop(&data);
    assert(result == SUCCESS);
    printf("pop() = %d on stack....ok\n", data);

    result = p_stack->pop(&data);
    assert(result == SUCCESS);
    printf("pop() = %d on stack....ok\n", data);

    result = p_stack->pop(&data);
    assert(result == STACK_EMPTY);
    printf("pop() = on empty stack....ok\n", data);

    delete p_stack;


    return(0);
}