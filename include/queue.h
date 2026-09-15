#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>
#include "task.h"

typedef struct {

    Task *head;
    Task *tail;
    size_t size;
} TaskQueue;

void queue_init (TaskQueue *queue);

int queue_is_empty (const TaskQueue *queue);
size_t queue_size (const TaskQueue *queue);

int queue_push (TaskQueue *queue, Task *task);

Task* queue_pop (TaskQueue *queue);
int queue_remove (TaskQueue *queue, int task_id);

Task* queue_find (TaskQueue *queue, int task_id);
void queue_print (const TaskQueue *queue);
void queue_clear (TaskQueue *queue);


#endif 