#include <stdio.h>
#include "queue.c"

int main(){
        queue_t queue = malloc(sizeof(queue_t));
        for(int i = 1; i <= 5; i++)
                enqueue(queue, i);
        for(int i = 1; i <= 5; i++){
                printf("%d ", peak(queue));
                dequeue(queue);
        }
        
        printf("\n");
        return 0;
}