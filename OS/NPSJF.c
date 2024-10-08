#include <stdio.h>

// Define structure
typedef struct process_info {
    char pname[20];
    int at, bt, ct, remaining_bt;
} Process;

// Define global variables
Process p[100];
int n;

void accept_info() {
    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter process name: ");
        scanf("%s", p[i].pname);
        printf("Enter arrival time: ");
        scanf("%d", &p[i].at);
        printf("Enter burst time: ");
        scanf("%d", &p[i].bt);
        p[i].remaining_bt = p[i].bt;
        p[i].ct = 0;
    }
}

void print_output() {
    float total_tat = 0, total_wt = 0;
    printf("\npname\tat\tbt\tct\ttat\twt\n");

    for (int i = 0; i < n; i++) {
        int tat = p[i].ct - p[i].at;
        int wt = tat - p[i].bt;
        total_tat += tat;
        total_wt += wt;
        printf("%s\t%d\t%d\t%d\t%d\t%d\n", p[i].pname, p[i].at, p[i].bt, p[i].ct, tat, wt);
    }
    printf("avg_tat=%.2f\tavg_wt=%.2f\n", total_tat / n, total_wt / n);
}

void sort_processes() {
    // Bubble sort based on arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                // Swap processes
                Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

int get_next_process(int time) {
    int selected = -1;
    for (int i = 0; i < n; i++) {
        // Check if the process has arrived and is not completed
        if (p[i].at <= time && p[i].remaining_bt > 0) {
            // If no process is selected yet or this one has a shorter remaining time
            if (selected == -1 || p[i].remaining_bt < p[selected].remaining_bt) {
                selected = i;  // Select this process
            }
        }
    }
    return selected;  // Return the index of the selected process
}

void sjf_non_preemptive() {
    int time = 0, completed = 0;
    while (completed < n) {
        int index = get_next_process(time);
        if (index == -1) {
            time++;
        } else {
            time += p[index].remaining_bt;
            p[index].ct = time;
            p[index].remaining_bt = 0;
            completed++;
        }
    }
}

void print_gantt_chart() {
    int time = 0;
    printf("%d", time);
    for (int i = 0; i < n; i++) {
        printf(" -- %s -- %d", p[i].pname, p[i].ct);
        time = p[i].ct;
    }
    printf("\n");
}

int main() {
    accept_info();
    sort_processes();
    sjf_non_preemptive();
    print_output();
    print_gantt_chart();
    return 0;
}