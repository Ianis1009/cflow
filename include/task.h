#ifndef TASK_H
#define TASK_H

#include <stddef.h>


typedef enum {
    TASK_TODO,
    TASK_ACTIVE,
    TASK_COMPLETED
} TaskStatus;


typedef enum {
    PRIORITY_LOW,
    PRIORITY_MEDIUM,
    PRIORITY_HIGH
} TaskPriority;


typedef struct Task {
    int id;
    char *title;

    TaskPriority priority;
    TaskStatus status;

    struct Task *next;
} Task;


Task *task_create(int id, const char *title, TaskPriority priority);


const char *task_status_to_string(TaskStatus status);
const char *task_priority_to_string(TaskPriority priority);

void task_print(const Task *task);

void task_destroy(Task *task);
void task_free_all(Task **head);

#endif