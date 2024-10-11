#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct process_info {
    char pname[20];
    int at, bt, ct, tat, wt, bt1;
} process;

process p[MAX];
int n;

void accept_info() {
    int i;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("\nEnter process name: ");
        scanf("%s", p[i].pname);
        printf("Enter arrival time: ");
        scanf("%d", &p[i].at);
        printf("Enter CPU burst time: ");
        scanf("%d", &p[i].bt);
        p[i].bt1 = p[i].bt;
    }
}

void print_output() {
    float avg_tat = 0, avg_wt = 0;
    printf("\npname\tat\tbt\tct\ttat\twt\n");
    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        avg_tat += p[i].tat;
        avg_wt += p[i].wt;
        printf("%s\t%d\t%d\t%d\t%d\t%d\n", p[i].pname, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("\nAvg TAT = %f\tAvg WT = %f\n", avg_tat / n, avg_wt / n);
}

void sort() {
    process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].at > p[j].at) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

void sjfp() {
    int time = 0, n1 = 0;
    while (n1 != n) {
        int min = 99, min_index = -1;
        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].bt1 != 0 && p[i].bt1 < min) {
                min = p[i].bt1;
                min_index = i;
            }
        }
        if (min_index == -1) {
            time++;
        } else {
            time++;
            p[min_index].ct = time;
            p[min_index].bt1--;
            if (p[min_index].bt1 == 0)
                n1++;
        }
    }
}

void print_gantt_chart() {
    int time = 0;
    printf("Gantt Chart:\n");
    for (int i = 0; i < n; i++) {
        while (p[i].at > time) {
            printf("%d | IDLE | %d ", time, ++time);
        }
        printf("%d | %s | %d \n", time, p[i].pname, p[i].ct);
        time = p[i].ct;
    }
}

int main() {
    accept_info();
    sort();
    sjfp();
    print_output();
    print_gantt_chart();
    return 0;
}