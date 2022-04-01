#ifndef         QUEUE_H
#define         QUEUE_H
//Linked list implementation of queue
#include        "linkedlist.c"

//front 100                         rear 350
//2|200  ->     4|300   6|350       7|450  -> NULL
//delete/dequeue at front - O(1)     insert/enqueue at rear - O(1) 
typedef struct queue{
        node*           front;
        node*           rear;       
}queue;

typedef queue*  queue_t;

static void    enqueue(queue* queue, int data);
static void    dequeue(queue* queue);
static int     peak(queue* queue);

#endif
