#include "cli.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_SIZE 512
#define TITLE_SIZE 400

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

