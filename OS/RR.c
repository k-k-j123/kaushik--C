#include <stdio.h>

struct process {
    char PName[5];
    int AT, BT, TAT, WT, CT, tempBT;
} p[10];

int N, TQ;

void input() {
    printf("Enter number of processes: ");
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        printf("\nEnter details of process %d", i + 1);
        printf("\nProcess name: ");
        scanf("%s", p[i].PName);
        printf("Arrival time (AT): ");
        scanf("%d", &p[i].AT);
        printf("Burst time (BT): ");
        scanf("%d", &p[i].BT);
        p[i].tempBT = p[i].BT;
    }
    
    printf("Enter time quantum: ");
    scanf("%d", &TQ);
}

void sortProcessAT() {
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (p[i].AT > p[j].AT) {
                struct process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

void RR() {
    int time = 0, completed = 0; // Initialize current time to 0 and count of completed processes to 0.

    while (completed < N) { // Loop until all processes are completed.
        int processExecuted = 0; // This flag checks if a process was executed in this cycle.
        
        for (int i = 0; i < N; i++) { // Loop through all processes.
            // Check if process has arrived (p[i].AT <= time) and still has burst time left (p[i].tempBT > 0).
            if (p[i].AT <= time && p[i].tempBT > 0) {
                printf("| %d %s", time, p[i].PName); // Print the current time and process name.
                
                if (p[i].tempBT > TQ) { // Case 1: Process's remaining burst time is greater than the time quantum.
                    time += TQ; // Increase the current time by the time quantum.
                    p[i].tempBT -= TQ; // Decrease the remaining burst time by the time quantum.
                } else { // Case 2: Process can finish within this time quantum.
                    time += p[i].tempBT; // Increase the current time by the remaining burst time.
                    p[i].CT = time; // Set the completion time to the current time.
                    p[i].tempBT = 0; // Set the remaining burst time to 0 since the process is complete.
                    completed++; // Increment the count of completed processes.
                }
                printf(" %d |", time); // Print the updated time after the process has run.
                processExecuted = 1; // A process was executed in this cycle.
            }
        }
        
        // If no process was executed in the above loop (either because none have arrived or all are completed):
        if (!processExecuted) {
            printf("| %d ## %d |", time, ++time); // Print idle time and increment the time by 1.
        }
    }
}


void output() {
    int totalTAT = 0, totalWT = 0;
    
    printf("\n\nProcess Details\n");
    printf("************************************");
    printf("\nPname\tAT\tBT\tTAT\tWT\n");
    printf("************************************\n");
    
    for (int i = 0; i < N; i++) {
        p[i].TAT = p[i].CT - p[i].AT;
        p[i].WT = p[i].TAT - p[i].BT;
        totalTAT += p[i].TAT;
        totalWT += p[i].WT;
        printf("%s\t%d\t%d\t%d\t%d\n", p[i].PName, p[i].AT, p[i].BT, p[i].TAT, p[i].WT);
    }
    
    printf("************************************\n");
    printf("Avg TAT: %.2f\n", (float)totalTAT / N);
    printf("Avg WT: %.2f\n", (float)totalWT / N);
}

int main() {
    input();
    sortProcessAT();
    RR();
    output();
    return 0;
}
