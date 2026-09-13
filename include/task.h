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
    char* title;
    TaskPriority priority;
    TaskStatus status;

    struct Task* next;
} Task;


#endif