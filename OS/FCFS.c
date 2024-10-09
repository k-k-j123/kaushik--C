#include <stdio.h>
#include <string.h>

#define MAX 10

struct Process {
    char name[5];
    int at, bt, ct, tat, wt;
};

struct Process p[MAX];
int n;

void input() {
    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter process %d details:\n", i + 1);
        scanf("%s %d %d", p[i].name, &p[i].at, &p[i].bt);
    }
}

void sort() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].at > p[j].at) {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

void fcfs() {
    int time = 0;
    for (int i = 0; i < n; i++) {
        if (p[i].at > time) {
            printf("|%d # ", time);
            time = p[i].at;
        }
        printf("|%d %s ", time, p[i].name);
        time += p[i].bt;
        printf("%d|", time);
        p[i].ct = time;
    }
}

void output() {
    int totalTat = 0, totalWt = 0;
    printf("\nProcess Details\n");
    printf("Name\tAT\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        totalTat += p[i].tat;
        totalWt += p[i].wt;
        printf("%s\t%d\t%d\t%d\t%d\t%d\n", p[i].name, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("Average TAT: %.2f\n", (float) totalTat / n);
    printf("Average WT: %.2f\n", (float) totalWt / n);
}

int main() {
    input();
    sort();
    fcfs();
    output();

    return 0;
}