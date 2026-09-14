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

