#include<stdio.h>

#define MAX 5

struct process {
    char name[10];
    int arrival, burst, priority, completion,tempBT;
};

int main() {
    struct process p[MAX];
    int n, time = 0;

    // Input processes
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter process %d name: ", i + 1);
        scanf("%s", p[i].name);
        printf("Enter arrival time: ");
        scanf("%d", &p[i].arrival);
        printf("Enter burst time: ");
        scanf("%d", &p[i].burst);
        printf("Enter priority (lower value = higher priority): ");
        scanf("%d", &p[i].priority);
		p[i].tempBT=p[i].burst;
    }

    // Sorting by arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].arrival > p[j].arrival) {
                struct process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Preemptive Priority Scheduling
    printf("\nGantt Chart:\n");
    int completed = 0;
    while (completed < n) {
        int min_p = 999, min_i = -1;
        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= time && p[i].tempBT > 0 && p[i].priority < min_p) {
                min_p = p[i].priority;
                min_i = i;
            }
        }
        if (min_i == -1) {
            time++;
            printf("%d # %d|", time - 1, time);
        } else {
            time++;
            p[min_i].tempBT--;
            printf("%d %s %d|", time - 1, p[min_i].name, time);
            if (p[min_i].tempBT == 0) {
                p[min_i].completion = time;
                completed++;
            }
        }
    }

    // Print process details
    float avgTAT = 0, avgWT = 0;
    printf("\nPname\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        int tat = p[i].completion - p[i].arrival;
        int wt = tat - p[i].tempBT;
        avgTAT += tat;
        avgWT += wt;
        printf("%s\t%d\t%d\t%d\t%d\t%d\n", p[i].name, p[i].arrival, p[i].burst, p[i].completion, tat, wt);
    }
    avgTAT /= n;
    avgWT /= n;
    printf("\nAverage TAT = %f\nAverage WT = %f\n", avgTAT, avgWT);

    return 0;
}