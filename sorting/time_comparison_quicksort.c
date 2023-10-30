#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random integer between min and max
int randomInt(int min, int max) {
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

// Custom comparison function for QuickSort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    // Define the file name
    const char *file_name = "temp.txt";

    // Define the number of numbers and other constants
    const int num_numbers = 1000000; // Adjust this for your desired file size
    const int min_number = 1;
    const int max_number = 1000000;

    // Seed the random number generator
    srand(time(NULL));

    // Generate random numbers and write them to a file
    FILE *file = fopen(file_name, "w");
     if(file == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    for (int i = 0; i < num_numbers; i++) {
        int random_num = randomInt(min_number, max_number);
        fprintf(file, "%d\n", random_num);
    }

    fclose(file);

    // Read the random numbers from the file
    int *numbers = malloc(num_numbers * sizeof(int));
    if (numbers == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return 1;
    }

    for (int i = 0; i < num_numbers; i++) {
        fscanf(file, "%d", &numbers[i]);
    }

    fclose(file);

    // Measure the start time for QuickSort
    clock_t quicksort_start_time = clock();

    // Sort the numbers using QuickSort
    qsort(numbers, num_numbers, sizeof(int), compare);

    // Measure the end time for QuickSort
    clock_t quicksort_end_time = clock();

    FILE *fp = fopen(file_name, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    for (int i = 0; i < num_numbers; i++) {
        
        fprintf(file, "%d\n", numbers[i]);
    }
    fclose(fp);
    // Calculate the time taken by QuickSort
    double quicksort_elapsed_time = (double)(quicksort_end_time - quicksort_start_time) / CLOCKS_PER_SEC;

    // Print the time taken by QuickSort
    printf("Time taken by QuickSort: %lf seconds\n", quicksort_elapsed_time);

    // Clean up
    free(numbers);

    return 0;
}
// 0.169000 seconds for random int
//0.298000 seconds for sorted int

