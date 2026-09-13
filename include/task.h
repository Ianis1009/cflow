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


Task *task_create(int id, const char *title, TaskPriority priority);


void task_add(Task **head, int id, const char *title, TaskPriority priority);


Task *task_find(Task *head, int id);


int task_delete(Task **head, int id);
int task_start(Task *head, int id);
int task_complete(Task *head, int id);


size_t task_count(const Task *head);


void task_print(const Task *task);
void task_print_all(const Task *head);


void task_free(Task **head);

const char *task_status_to_string(TaskStatus status);
const char *task_priority_to_string(TaskPriority priority);


#endif