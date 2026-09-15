#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

void queue_init (TaskQueue *queue) {

    if (queue == NULL) {return;}

    queue ->head = NULL;
    queue ->tail = NULL;
    queue ->size = 0;
}

int queue_is_empty (const TaskQueue *queue) {

    if (queue == NULL) {
        return 1;
    }
    return queue ->head == NULL;
}

size_t queue_size (const TaskQueue *queue) {

    if (queue == NULL) {
        return 0;
    }

    return queue ->size;
}

