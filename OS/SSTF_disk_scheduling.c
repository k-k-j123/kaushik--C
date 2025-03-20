#include <stdio.h>
#include <stdlib.h>

int main() {
    int RQ[100], n, TotalHeadMovement = 0, initial;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    printf("Enter the request sequence: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &RQ[i]);

    printf("Enter the initial head position: ");
    scanf("%d", &initial);

    for (int count = 0; count < n; count++) {
        int min = 1000, index;

        for (int i = 0; i < n; i++) {
            int d = abs(RQ[i] - initial);
            if (d < min) {
                min = d;
                index = i;
            }
        }

        TotalHeadMovement += min;
        initial = RQ[index];
        RQ[index] = 1000; // Mark the request as processed
    }

    printf("Total head movement is %d\n", TotalHeadMovement);
    return 0;
}