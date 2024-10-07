#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct process_info {
    char pname[20];
    int at, bt, ct, remaining_bt;
    struct process_info *next;
} Process;

Process *head = NULL;

void accept_info(int *n) {
    printf("Enter number of processes: ");
    scanf("%d", n);

    for (int i = 0; i < *n; i++) {
        Process *p = malloc(sizeof(Process));
        printf("Enter process name: ");
        scanf("%s", p->pname);
        printf("Enter arrival time: ");
        scanf("%d", &p->at);
        printf("Enter burst time: ");
        scanf("%d", &p->bt);
        p->remaining_bt = p->bt;
        p->next = head;
        head = p;
    }
}

void print_output(int n) {
    float total_tat = 0, total_wt = 0;
    Process *p = head;
    printf("\npname\tat\tbt\tct\ttat\twt\n");

    while (p) {
        int tat = p->ct - p->at;
        int wt = tat - p->bt;
        total_tat += tat;
        total_wt += wt;
        printf("%s\t%d\t%d\t%d\t%d\t%d\n", p->pname, p->at, p->bt, p->ct, tat, wt);
        p = p->next;
    }
    printf("avg_tat=%.2f\tavg_wt=%.2f\n", total_tat / n, total_wt / n);
}

void sort_processes() {
    // Bubble sort based on arrival time
    for (Process *p = head; p != NULL; p = p->next) {
        for (Process *q = p->next; q != NULL; q = q->next) {
            if (p->at > q->at) {
                // Swap processes
                Process temp = *p;
                *p = *q;
                *q = temp;
            }
        }
    }
}

Process *get_next_process(int time) {
    Process *current = head;
    Process *selected = NULL;
    while (current != NULL) {
        // Check if the process has arrived and is not completed
        if (current->at <= time && current->remaining_bt > 0) {
            // If no process is selected yet or this one has a shorter remaining time
            if (selected == NULL || current->remaining_bt < selected->remaining_bt) {
                selected = current;  // Select this process
            }
        }
        current = current->next;  // Move to the next process
    }
    
    return selected;  // Return the selected process
}

void sjf_non_preemptive(int n) {
    int time = 0, completed = 0;
    while (completed < n) {
        Process *p = get_next_process(time);
        if (!p) {
            time++;
        } else {
            time += p->remaining_bt;
            p->ct = time;
            p->remaining_bt = 0;
            completed++;
        }
        sort_processes();
    }
}

void print_gantt_chart() {
    int time = 0;
    Process *p = head;
    printf("%d", time);
    while (p) {
        if (p->remaining_bt == 0) {
            printf(" -- %s -- %d", p->pname, p->ct);
        }
        p = p->next;
    }
    printf("\n");
}

int main() {
    int n;
    accept_info(&n);
    sort_processes();
    sjf_non_preemptive(n);
    print_output(n);
    print_gantt_chart();
    return 0;
}
