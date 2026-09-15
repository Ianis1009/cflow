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

int queue_push (TaskQueue *queue, Task *task) {

    if (queue == NULL || task == NULL) {
        return 0;
    }

    task ->next = NULL;
    if (queue ->head == NULL) {
        queue ->head = task;
        queue ->tail = task;
        queue ->size++ ;
        return 1;
    }

    queue ->tail->next = task;
    queue ->tail = task;
    queue ->size++;

    return 1;
}

Task* queue_pop (TaskQueue *queue) {

    if (queue == NULL || queue ->head == NULL) {
        return NULL;
    }

    Task *task = queue ->head;
    queue ->head = task ->next;
    if (queue ->head == NULL) {
        queue ->tail = NULL;
    }

    task ->next = NULL;
    queue ->size--;

    return task;
}

Task* queue_find (TaskQueue *queue, int task_id) {
    if (queue == NULL ) {
        return NULL;
    }

    Task* current = queue ->head;

    while (current != NULL ) {
        if (current-> id == task_id) {
            return current;
        }

        current = current ->next;
    }

    return NULL;
}

void queue_print (const TaskQueue *queue) {

    if (queue == NULL || queue ->head == NULL) {
        printf("No tasks. \n");
        return ;
    }

    const Task* current = queue->head;

    while (current != NULL) {
        task_print(current);
        current = current ->next;
    }
}

void queue_clear (TaskQueue *queue) {

    if (queue == NULL) {
        return;
    }

    Task* current = queue ->head;

    while (current != NULL) {
        Task* next = current ->next;
        free(current->title);
        free(current);

        current = next;
    }

    queue ->head = NULL;
    queue ->tail = NULL;
    queue ->size = 0;
}