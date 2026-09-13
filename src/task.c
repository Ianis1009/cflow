#include "task.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char* string_duplicate (const char* source) {

    //TODO
}

Task* task_create(int id, const char *title, TaskPriority priority) {

    //TODO
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