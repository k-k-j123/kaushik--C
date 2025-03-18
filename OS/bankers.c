#include <stdio.h>

int N, M;             // Processes, Resources
int avail[10];        // Available resources
int max[10][10];      // Max demand
int alloc[10][10];    // Allocated resources
int need[10][10];     // Remaining need

void input() {
    printf("Processes, Resources: ");
    scanf("%d %d", &N, &M);

    printf("Available: ");
    for (int i = 0; i < M; i++) scanf("%d", &avail[i]);

    printf("Max Matrix:\n");
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &max[i][j]);

    printf("Allocation Matrix:\n");
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            scanf("%d", &alloc[i][j]);
            need[i][j] = max[i][j] - alloc[i][j];  // Compute need
        }
}

void safe() {
    int done[10] = {0}, count = 0;

    printf("\nSafe Sequence: ");
    while (count < N) {
        for (int i = 0; i < N; i++) {
            if (!done[i]) {
                int canRun = 1;
                for (int j = 0; j < M; j++) {
                    if (need[i][j] > avail[j]) {
                        canRun = 0;
                        break;
                    }
                }

                if (canRun) {
                    for (int j = 0; j < M; j++) avail[j] += alloc[i][j];
                    printf("P%d ", i);  // Print immediately instead of storing
                    done[i] = 1;
                    count++;
                }
            }
        }
    }
    printf("\n");
}

void request() {
    int p, req[10];
    printf("\nProcess & Request: ");
    scanf("%d", &p);
    for (int i = 0; i < M; i++) scanf("%d", &req[i]);

    for (int i = 0; i < M; i++) {
        if (req[i] > need[p][i] || req[i] > avail[i]) {
            printf("\nRequest Denied!\n");
            return;
        }
    }

    printf("\nRequest Granted!\n");
    safe();  // Check safety again
}

int main() {
    input();
    safe();
    request();
    return 0;
}
