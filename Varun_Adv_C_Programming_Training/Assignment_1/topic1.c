//1. Simple weekly calender to-do-list

#include <stdio.h>
#include <string.h>

typedef struct {
    char name[10];
    char tasks[3][100];
    int taskCount;
} Day;

void inputTasks(Day week[]) {
    int i = 0;
    while (i < 7) {
        printf("Enter number of tasks for %s (max %d): ", week[i].name, 3);
        scanf("%d", &week[i].taskCount);
        getchar();
        if (week[i].taskCount > 3) {
            printf("Enter only max 3 tasks\n");
            i = 0;
            continue;
        }
        for (int j = 0; j < week[i].taskCount; j++) {
            printf("  Task %d: ", j + 1);
            fgets(week[i].tasks[j], 100, stdin);
            week[i].tasks[j][strcspn(week[i].tasks[j], "\n")] = '\0';
        }
        i++;
    }
}

void displayTasks(const Day week[]) {
    printf("\n--- Weekly Tasks ---\n");
    for (int i = 0; i < 7; i++) {
        printf("%s:\n", week[i].name);
        for (int j = 0; j < week[i].taskCount; j++) {
            printf("  - %s\n", week[i].tasks[j]);
        }
    }
}

int main() {
    Day week[7] = {
        {"Monday"}, {"Tuesday"}, {"Wednesday"},
        {"Thursday"}, {"Friday"}, {"Saturday"}, {"Sunday"}
    };
    inputTasks(week);
    displayTasks(week);
    return 0;
}
