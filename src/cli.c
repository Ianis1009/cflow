#include "cli.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_SIZE 512
#define TITLE_SIZE 400

#define LOOP 1

static void print_help(void)
{
    printf("\n");
    printf("CFlow commands:\n\n");

    printf("  add <priority> <title>\n");
    printf("      Add a new task.\n");
    printf("      Priority: low, medium, high\n\n");

    printf("  list\n");
    printf("      List all tasks.\n\n");

    printf("  start <id>\n");
    printf("      Start a task.\n\n");

    printf("  done <id>\n");
    printf("      Complete an active task.\n\n");

    printf("  delete <id>\n");
    printf("      Delete a task.\n\n");

    printf("  help\n");
    printf("      Show this help message.\n\n");

    printf("  exit\n");
    printf("      Exit CFlow.\n\n");
}


static TaskPriority parse_priority (const char *value) {

    if (strcmp(value, "low") == 0) {
        return PRIORITY_LOW;
    }

    if (strcmp(value, "medium") == 0) {
        return PRIORITY_MEDIUM;
    }

    if (strcmp(value, "high") == 0) {
        return PRIORITY_HIGH;
    }

    return -1;
}

static int parse_id(const char *value)
{
    char *end;

    long id = strtol(value, &end, 10);

    if (*value == '\0' || *end != '\0') {
        return -1;
    }

    if (id <= 0 || id > 2147483647) {
        return -1;
    }

    return (int)id;
}


static void handle_add(Task **tasks, char *input, int *next_id)
{
    char priority_text[32];
    char title[TITLE_SIZE];

    int result = sscanf(
        input,
        "add %31s %399[^\n]",
        priority_text,
        title
    );

    if (result != 2) {
        printf("Usage: add <priority> <title>\n");
        return;
    }

    TaskPriority priority = parse_priority(priority_text);

    if (priority == -1) {
        printf("Invalid priority. Use: low, medium, high\n");
        return;
    }

    task_add(tasks, *next_id, title, priority);

    printf("Task added with ID %d.\n", *next_id);

    (*next_id)++;
}

static void handle_list (const Task *tasks) {
    task_print_all (tasks);
}

static void handle_delete (Task **tasks, char *input) {

    char id_text[32];
    int result = sscanf(input, "delete %31s", id_text);

    if (result != 1) {
        printf("Usage: delete <id>\n");
        return;
    }

    int id = parse_id(id_text);

    if (id == -1) {
        printf("Invalid task ID.\n");
        return;
    }

    if (task_delete(tasks, id)) {
        printf("Task %d deleted.\n", id);
    } else {
        printf("Task %d not found.\n", id);
    }

}

static void handle_start (Task* tasks, char *input) {

    char id_text[32];
    int result = sscanf(input, "start %31s", id_text);

    if (result != 1) {
        printf("Usage: start <id>\n");
        return;
    }

    int id = parse_id(id_text);

    if (id == -1) {
        printf("Invalid task ID.\n");
        return;
    }

    Task *task = task_find(tasks, id);

    if (task == NULL) {
        printf("Task %d not found.\n", id);
        return;
    }

    if (task->status != TASK_TODO) {
        printf("Task %d cannot be started.\n", id);
        return;
    }

    task_start(tasks, id);

    printf("Task %d started.\n", id);
}

static void handle_done (Task *tasks, char *input) {

    char id_text[32];
    int result = sscanf(input, "done %31s", id_text);

    if (result != 1) {
        printf("Usage: done <id>\n");
        return;
    }

    int id = parse_id(id_text);

    if (id == -1) {
        printf("Invalid task ID.\n");
        return;
    }

    Task *task = task_find(tasks, id);

    if (task == NULL) {
        printf("Task %d not found.\n", id);
        return;
    }

    if (task->status != TASK_ACTIVE) {
        printf("Task %d cannot be completed.\n", id);
        return;
    }

    task_complete(tasks, id);

    printf("Task %d completed.\n", id);


}

void cli_run (Task **tasks) {

    if (tasks == NULL) {
        return;
    }

    char input[INPUT_SIZE];
    int next_id = 1;

    printf(" ---------------------- CFLOW (C11) ---------------------- \n");
    printf("Type 'help' for available commands. \n\n");

    while (LOOP ) {

        printf(">> ");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) == 0) {continue;}

        if (strcmp(input, "exit") == 0) {
            break;
        }

        if (strcmp(input, "help") == 0) {
            print_help();
            continue;
        }

        if (strcmp(input, "list") == 0) {
            handle_list(*tasks);
            continue;
        }

        if (strncmp(input, "add ", 4) == 0) {
            handle_add(tasks, input, &next_id);
            continue;
        }

        if (strncmp(input, "delete ", 7) == 0) {
            handle_delete(tasks, input);
            continue;
        }

        if (strncmp(input, "start ", 6) == 0) {
            handle_start(*tasks, input);
            continue;
        }

        if (strncmp(input, "done ", 5) == 0) {
            handle_done(*tasks, input);
            continue;
        }

        printf("Unknown command. Type 'help'.\n");
        
    }
}