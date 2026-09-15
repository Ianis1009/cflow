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

    if (head == NULL) {return;}

    Task* task = task_create(id, title, priority);

    if (task == NULL) {return;}

    if (*head == NULL) {
        *head = task;
        return;
    }

    Task *current = *head;

    while (current ->next != NULL) {
        current = current ->next;
    }

    current ->next = task;
}

Task* task_find (Task* head, int id) {

    Task *current = head;

    while (current != NULL) {
        if (current ->id == id) {
            return current;
        }
        current = current ->next;
    }

    return NULL;
}
int task_delete (Task **head, int id) {

    if (head == NULL || *head == NULL) {
        return 0;
    }

    Task* current = *head;

    if (current->id == id) {
        *head = current ->next;
        free(current->title);
        free(current);

        return 1;
    }

    while (current->next != NULL) {
        if (current->next->id == id) {
            Task *to_delete = current->next;
            current ->next = to_delete->next;
            free(to_delete->title);
            free(to_delete);

            return 1;
        }

        current = current ->next;
    }

    return 0;
}

int task_start (Task*head, int id) {
    
    Task* task = task_find(head, id);

    if (task == NULL) {
        return 0;
    }

    if (task ->status != TASK_TODO) {
        return 0;
    }

    task->status = TASK_ACTIVE;
    return 1;
}

int task_complete (Task *head, int id) {
    
    Task *task = task_find(head, id);

    if (task == NULL) {
        return 0;
    }

    if (task ->status != TASK_ACTIVE) {
        return 0;
    }

    task ->status = TASK_COMPLETED;
    return 1;
}

size_t task_count (const Task *head) {

    size_t count = 0;
    const Task *current = head;

    while (current != NULL) {
        count++;
        current = current ->next;
    }

    return count;
}

const char* task_status_to_string (TaskStatus status) {
    
    switch (status) {
        case TASK_TODO:
            return "TODO";
        case TASK_ACTIVE:
            return "ACTIVE";
        case TASK_COMPLETED:
            return "COMPLETED";
        default:
            return "UNKNOWN";
    }
}

const char *task_priority_to_string(TaskPriority priority) {
    
    switch(priority) {
        case PRIORITY_LOW:
           return "LOW";
           
        case PRIORITY_MEDIUM:
            return "MEDIUM";
        case PRIORITY_HIGH:
            return "HIGH";

        default:
            return "UNKNOWN";
    }
}

void task_print (const Task *task) {
    
    if (task == NULL) {
        return ;
    }

    printf("%-4d %-10s %-12s %s\n", task->id, task_priority_to_string(task->priority), task_status_to_string(task->status), task->title);
}

void task_print_all (const Task *head) {
    
    if (head == NULL) {
        printf("No tasks.\n");
        return;
    }

    printf("\n");
    printf("%-4s %-10s %-12s %s\n", "ID", "PRIORITY", "STATUS", "TITLE");

    printf("------------------------------------\n");
    const Task *current = head;

    while (current != NULL) {
        task_print(current);
        current = current ->next;
    }

    printf("\n");
}

void task_free (Task **head) {
    
    if (head == NULL) {
        return;
    }

    Task* current = *head;

    while (current != NULL) {
        Task* next = current ->next;
        free(current->title);
        free(current);
        current = next;
    }

    *head= NULL;
}

void task_destroy(Task *task)
{
    if (task == NULL) {
        return;
    }

    free(task->title);
    free(task);
}

void task_free_all (Task **head) {

    if (head == NULL) {
        return;
    }

    Task *current = *head;
    while (current != NULL) {
        Task *next = current ->next;
        task_destroy(current);
        current = next;
    }

    *head = NULL;
}