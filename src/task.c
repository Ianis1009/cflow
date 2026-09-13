#include "task.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char* string_duplicate (const char* source) {

    if (source == NULL) {
        return NULL;
    }

    size_t length = strlen(source);
    char *copy = (char *)malloc(sizeof(char) * (length + 1));

    if (copy == NULL) {
        return NULL;
    }

    memcpy(copy, source, length + 1);
    return copy;
}



Task* task_create(int id, const char *title, TaskPriority priority) {

    if (title == NULL) {
        return NULL;
    }

    Task *task = malloc (sizeof(*task));

    if (task == NULL) {
        return NULL;
    }

    task->title = string_duplicate(title);
    if (task->title == NULL) {
        free(task);
        return NULL;
    }

    task ->id = id;
    task->priority = priority;
    task->status = TASK_TODO;
    task->next = NULL;

    return task;
}

void task_add(Task **head, int id, const char *title, TaskPriority priority) {

    //TOOD
}

int task_delete (Task **head, int id) {

    //TODO
}

int task_start (Task*head, int id) {
    //TODO
}

int task_complete (Task *head, int id) {
    //TODO
}

ssize_t task_count (const Task *head) {

    //TODO
}

const char* task_status_to_string (TaskStatus status) {
    //TODO
}

const char *task_priority_to_string(TaskPriority priority) {
    //TODO
}

void task_print (const Task *task) {
    //TODO
}

void task_print_all (const Task *head) {
    //TODO
}

void task_free (Task **head) {
    //TODO
}