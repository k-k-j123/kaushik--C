#include <stdio.h>

#define MAX 20

void fifo(int frames, int references, int ref[])
{
    int mem[frames]; // 1D array to simulate memory
    int faults = 0;
    int sp = 0;

    // Initialize memory with -1 (empty)
    for (int i = 0; i < frames; i++)
    {
        mem[i] = 0;
    }

    // Iterate through each page reference
    for (int i = 0; i < references; i++)
    {
        // Check if page is already in memory
        int found = 0;
        for (int j = 0; j < frames; j++)
        {
            if (mem[j] == ref[i])
            {
                found = 1;
                break;
            }
        }

        // Handle page fault
        if (!found)
        {
            // Add page to current frame
            mem[sp] = ref[i];

            // Increment frame pointer (circular buffer)
            sp = (sp + 1) % frames;

            // Increment page fault counter
            faults++;
        }
        printf("Memory: ");
        for (int i = 0; i < frames; i++)
        {
            printf("%d ", mem[i]);
        }
        printf("\n");
    }

    // Display reference string
    printf("Reference String: ");
    for (int i = 0; i < references; i++)
    {
        printf("%d ", ref[i]);
    }
    printf("\n");

    // Display total page faults
    printf("Total Page Faults: %d\n", faults);
}
int main()
{
    int frames, references;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of references: ");
    scanf("%d", &references);

    int ref[references];
    printf("Enter reference string: ");
    for (int i = 0; i < references; i++)
    {
        scanf("%d", &ref[i]);
    }

    fifo(frames, references, ref);

    return 0;
}