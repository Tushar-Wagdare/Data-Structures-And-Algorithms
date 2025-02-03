#include <assert.h>
#include "queue.hpp"


int main(void)
{
    status_t status;
    data_t data = 0;
    queue* p_queue = new queue();

    assert(p_queue->is_queue_empty() == true);
    printf("Assertion on is_queue_empty()...ok\n");

    for(int i = 1; i <= 5; i++)
    {
        status = p_queue->enqueue(i*100);
        assert(status == SUCCESS);
    }
    printf("Assertion on enqueue()...ok\n");

    status = p_queue->peek(&data);
    assert(status == SUCCESS);
    printf("Assertion on peek() = %d...ok\n", data);

    status = p_queue->dequeue(&data);
    assert(status == SUCCESS);
    printf("Assertion on dequeue() = %d...ok\n", data);

    status = p_queue->dequeue(&data);
    assert(status == SUCCESS);
    printf("Assertion on dequeue() = %d...ok\n", data);

    status = p_queue->dequeue(&data);
    assert(status == SUCCESS);
    printf("Assertion on dequeue() = %d...ok\n", data);

    status = p_queue->dequeue(&data);
    assert(status == SUCCESS);
    printf("Assertion on dequeue() = %d...ok\n", data);

    status = p_queue->dequeue(&data);
    assert(status == SUCCESS);
    printf("Assertion on dequeue() = %d...ok\n", data);

    assert(p_queue->is_queue_empty() == true);
    printf("Assertion on is_queue_empty()...ok\n");

    delete p_queue;
    p_queue = 0;

    return(0);
}