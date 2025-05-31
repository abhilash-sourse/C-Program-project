#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_TASK_LEN 100

char tasks[MAX_TASKS][MAX_TASK_LEN];
int task_count = 0;

void add_task() {
    if (task_count >= MAX_TASKS) {
        printf("Task list is full! Cannot add more tasks.\n");
        return;
    }
    printf("Enter the task description: ");
    getchar(); // consume leftover newline
    fgets(tasks[task_count], MAX_TASK_LEN, stdin);
    tasks[task_count][strcspn(tasks[task_count], "\n")] = 0; // remove newline
    task_count++;
    printf("Task added successfully.\n");
}

void display_tasks() {
    if (task_count == 0) {
        printf("No tasks in the list.\n");
        return;
    }
    printf("To-Do List:\n");
    for (int i = 0; i < task_count; i++) {
        printf("%d. %s\n", i + 1, tasks[i]);
    }
}

void delete_task() {
    int task_num;
    if (task_count == 0) {
        printf("No tasks to delete.\n");
        return;
    }
    printf("Enter task number to delete: ");
    scanf("%d", &task_num);

    if (task_num < 1 || task_num > task_count) {
        printf("Invalid task number.\n");
        return;
    }
    // Shift remaining tasks up
    for (int i = task_num - 1; i < task_count - 1; i++) {
        strcpy(tasks[i], tasks[i + 1]);
    }
    task_count--;
    printf("Task deleted successfully.\n");
}

int main() {
    int choice;
    printf("Simple To-Do List\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add Task\n");
        printf("2. Display Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_task();
                break;
            case 2:
                display_tasks();
                break;
            case 3:
                delete_task();
                break;
            case 4:
                printf("Exiting To-Do List. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}