#include "cli.h"
#include "task.h"

int main () {

    Task *tasks = NULL;
    cli_run(&tasks);
    task_free(&tasks);

    return 0;
}