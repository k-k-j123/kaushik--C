#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random integer between min and max
int randomInt(int min, int max) {
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

// MergeSort implementation
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// MergeSort function
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for large l and r
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

int main() {
    // Define the file name
    const char *file_name = "random_numbers.txt";
    const char *sorted_file_name = "sorted_numbers.txt";

    // Define the number of numbers and other constants
    const int num_numbers = 1000000; // Adjust this for your desired file size
    const int min_number = 1;
    const int max_number = 1000000;

    // Seed the random number generator
    srand(time(NULL));

    // Generate random numbers and write them to a file
    FILE *file = fopen(file_name, "w");
    if (file == NULL) {
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

    // Measure the start time for MergeSort
    clock_t mergesort_start_time = clock();

    // Sort the numbers using MergeSort
    mergeSort(numbers, 0, num_numbers - 1);

    // Measure the end time for MergeSort
    clock_t mergesort_end_time = clock();

    // Calculate the time taken by MergeSort
    double mergesort_elapsed_time = (double)(mergesort_end_time - mergesort_start_time) / CLOCKS_PER_SEC;

    // Print the time taken by MergeSort
    printf("Time taken by MergeSort: %lf seconds\n", mergesort_elapsed_time);

    // Write the sorted numbers to a new file
    file = fopen(sorted_file_name, "w");
    if (file == NULL) {
        printf("Error opening file for writing sorted numbers.\n");
        return 1;
    }

    for (int i = 0; i < num_numbers; i++) {
        fprintf(file, "%d\n", numbers[i]);
    }

    fclose(file);

    // Clean up
    free(numbers);

    return 0;
}
