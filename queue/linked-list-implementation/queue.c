#ifndef         QUEUE_C
#define         QUEUE_C

#include        "queue.h"

void    enqueue(queue* queue, int data){

        node* temp = get_new_node(data);

        if(queue == NULL){
                printf("IN FUNCTION ENQUEUE: ERROR, QUEUE POINTER IS NULL\n");
                assert(0);
        }
        else if(queue->front == NULL && queue->rear == NULL){
               queue->front = queue->rear = temp;
               return;
        }

        queue->rear->next = temp;
        queue->rear = temp;
}
void    dequeue(queue* queue){
        if(queue == NULL){
                printf("IN FUNCTION ENQUEUE: ERROR, QUEUE POINTER IS NULL\n");
                assert(0);
        }
        node* temp = queue->front;
        if(queue->front == NULL){
                goto Exit;
        }
        else if(queue->front == queue->rear){
                queue->front = queue->rear = NULL;
                goto Exit;
        }
        else {
                queue->front = queue->front->next;
        }

        // good programing practice, before every free, should have a condition 
        if(temp != NULL) free(temp);

        Exit:
        return;
}
int     peak(queue* queue){
        return queue->front->data;
}

#endif
