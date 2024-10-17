#include <stdio.h>

void lfu(int frames, int references, int ref[])
{
    int mem[frames], frequency[frames];
    int faults = 0;

    // Initialize memory and frequency arrays
    for (int i = 0; i < frames; i++)
    {
        mem[i] = -1;
        frequency[i] = 0;
    }

    for (int i = 0; i < references; i++)
    {
        int found = 0;
        // Check if reference is already in memory
        for (int j = 0; j < frames; j++)
        {
            if (mem[j] == ref[i])
            {
                found = 1;
                frequency[j]++; // Increment frequency
                break;
            }
        }

        if (!found)
        {
            faults++;
            // Find victim (least frequently used)
            int min_freq = frequency[0];//max_freq for MFU
            int min_index = 0;//max_freq for MFU
            for (int j = 1; j < frames; j++)
            {
                if (frequency[j] < min_freq) //for MFU just change less than sign to greater than 
                {
                    min_freq = frequency[j];
                    min_index = j;
                }
            }

            // Replace victim with new reference
            mem[min_index] = ref[i];
            frequency[min_index] = 1;
        }
        // Print current memory state
        printf("Memory and freq: ");
        for (int j = 0; j < frames; j++)
        {
            printf("%d:%d ", mem[j], frequency[j]);
        }
        printf("\n");
    }

    printf("Page Faults: %d\n", faults);
}

int main()
{
    int frames = 3;
    int references = 10;
    int ref[] = {3, 4, 2, 1, 5, 2, 1, 4, 6, 2};

    lfu(frames, references, ref);

    return 0;
}