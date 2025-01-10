#include <stdio.h>

int N; // Number of processes
int M; // Number of resource types
int available[10]; // Available resources
int tempAvailable[10]; // Temporary available resources
int max[10][10]; // Maximum resource requirement
int alloc[10][10]; // Allocated resources
int need[10][10]; // Needed resources
int safeseq[10]; // Safe sequence

void acceptInput() {
    int i, j;
    printf("Enter the number of processes: ");
    scanf("%d", &N);
    printf("Enter the number of resource types: ");
    scanf("%d", &M);

    printf("Enter available resources:\n");
    for (i = 0; i < M; i++) {
        printf("Enter the number of instances of resource type %c: ", 65 + i);
        scanf("%d", &available[i]);
        tempAvailable[i] = available[i];
    }

    printf("\nEnter maximum resource requirement:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("Enter max for process %d, resource %c: ", i, 65 + j);
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter allocated resources:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("Enter allocation for process %d, resource %c: ", i, 65 + j);
            scanf("%d", &alloc[i][j]);
        }
    }

    for (i = 0; i < N; i++) {
        safeseq[i] = -1;
    }
}

void displayMatrix(int a[10][10], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }
}

void calNeed() {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
}

int isFeasible(int pno) {
    for (int i = 0; i < M; i++) {
        if (need[pno][i] > available[i]) {
            return 0;
        }
    }
    return 1;
}

void banker() {
    int k = 0;
    int i, j;
    int flag[10] = {0}; // Flags to track finished processes
    int finished = 0;

    while (finished < N) {
        int found = 0;
        for (i = 0; i < N; i++) {
            if (!flag[i] && isFeasible(i)) {
                for (j = 0; j < M; j++) {
                    available[j] += alloc[i][j];
                }
                safeseq[k++] = i;
                flag[i] = 1;
                found = 1;
                finished++;
            }
        }

        if (!found) {
            printf("\nSystem is not in a safe state!\n");
            return;
        }
    }

    printf("\nSystem is in a safe state.\nSafe Sequence: ");
    for (i = 0; i < N; i++) {
        printf("P%d", safeseq[i]);
        if (i != N - 1) printf(" -> ");
    }
    printf("\n");
}

void newRequest() {
    int newReq[10];
    int i, process;

    printf("\nEnter the process number for the new request: ");
    scanf("%d", &process);

    printf("Enter the request for resources:\n");
    for (i = 0; i < M; i++) {
        printf("Enter request for resource %c: ", 65 + i);
        scanf("%d", &newReq[i]);
    }

    for (i = 0; i < M; i++) {
        if (newReq[i] > need[process][i] || newReq[i] > tempAvailable[i]) {
            printf("\nRequest cannot be granted (exceeds limits or available resources).\n");
            return;
        }
    }

    for (i = 0; i < M; i++) {
        available[i] -= newReq[i];
        alloc[process][i] += newReq[i];
        need[process][i] -= newReq[i];
    }

    banker(); // Recheck safety after granting the request
}

int main() {
    acceptInput();
    calNeed();

    printf("\nMax Matrix:\n");
    displayMatrix(max, N, M);

    printf("\nAllocation Matrix:\n");
    displayMatrix(alloc, N, M);

    printf("\nNeed Matrix:\n");
    displayMatrix(need, N, M);

    banker();
    newRequest();

    return 0;
}
