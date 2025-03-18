#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DISK_SIZE 100          // Total number of disk blocks
#define MAX_FILES 50           // Maximum number of files that can be stored
#define NAME_LENGTH 50         // Maximum length of a file name

// Structure to define a file
typedef struct {
    char name[NAME_LENGTH];    // Name of the file
    int start_block;           // Starting block of the file
    int length;                // Length of the file (number of blocks)
} File;

int bit_vector[DISK_SIZE] = {0}; // Bit vector to represent disk blocks (0 = free, 1 = allocated)
File files[MAX_FILES];           // Array to store file metadata
int file_count = 0;              // Counter to track the number of files

// Function to create a file (automatically finds free space)
void create_file(char *name, int length) {
    // Check if the maximum number of files has been reached
    if (file_count >= MAX_FILES) {
        printf("Error: Maximum number of files reached.\n");
        return;
    }

    int start_block = -1;       // Variable to store the starting block of the file
    int free_blocks = 0;        // Counter to track contiguous free blocks

    // Search for a contiguous free block of the required length
    for (int i = 0; i < DISK_SIZE; i++) {
        if (bit_vector[i] == 0) {
            free_blocks++;      // Increment the counter if the block is free
            if (free_blocks == length) {
                // If enough contiguous free blocks are found, calculate the starting block
                start_block = i - length + 1;
                break;
            }
        } else {
            // Reset the counter if a block is already allocated
            free_blocks = 0;
        }
    }

    // If no contiguous free space is found, display an error message
    if (start_block == -1) {
        printf("Error: Not enough contiguous free space to create the file.\n");
        return;
    }

    // Allocate the blocks for the file
    for (int i = start_block; i < start_block + length; i++) {
        bit_vector[i] = 1;      // Mark the blocks as allocated
    }

    // Add file metadata to the files array
    strcpy(files[file_count].name, name);       // Copy the file name
    files[file_count].start_block = start_block; // Set the starting block
    files[file_count].length = length;          // Set the length of the file
    file_count++;                               // Increment the file counter

    printf("File '%s' created successfully from block %d to %d.\n", name, start_block, start_block + length - 1);
}

// Function to delete a file
void delete_file(char *name) {
    int found = 0; // Flag to check if the file is found

    // Search for the file in the files array
    for (int i = 0; i < file_count; i++) {
        if (strcmp(files[i].name, name) == 0) {
            found = 1; // Set the flag if the file is found

            // Deallocate the blocks for the file
            for (int j = files[i].start_block; j < files[i].start_block + files[i].length; j++) {
                bit_vector[j] = 0; // Mark the blocks as free
            }

            printf("File '%s' deleted successfully from block %d to %d.\n", files[i].name, files[i].start_block, files[i].start_block + files[i].length - 1);

            // Remove the file from the files array by shifting elements
            for (int j = i; j < file_count - 1; j++) {
                files[j] = files[j + 1];
            }
            file_count--; // Decrement the file counter
            break;
        }
    }

    // If the file is not found, display an error message
    if (!found) {
        printf("Error: File '%s' not found.\n", name);
    }
}

// Function to display the bit vector
void display_bit_vector() {
    printf("Bit Vector:\n");
    for (int i = 0; i < DISK_SIZE; i++) {
        printf("%d ", bit_vector[i]); // Print the status of each block
    }
    printf("\n");
}

// Function to display all files
void display_files() {
    printf("Files:\n");
    for (int i = 0; i < file_count; i++) {
        // Print the metadata of each file
        printf("File: %s, Start Block: %d, Length: %d\n", files[i].name, files[i].start_block, files[i].length);
    }
}

int main() {
    int choice, length;
    char name[NAME_LENGTH];

    while (1) {
        // Display the menu
        printf("\n1. Create File\n2. Delete File\n3. Display Bit Vector\n4. Display Files\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Create a file
                printf("Enter file name: ");
                scanf("%s", name);
                printf("Enter length of the file: ");
                scanf("%d", &length);
                if (length > DISK_SIZE) {
                    printf("Error: File size exceeds disk size.\n");
                } else {
                    create_file(name, length);
                }
                break;
            case 2:
                // Delete a file
                printf("Enter file name to delete: ");
                scanf("%s", name);
                delete_file(name);
                break;
            case 3:
                // Display the bit vector
                display_bit_vector();
                break;
            case 4:
                // Display all files
                display_files();
                break;
            case 5:
                // Exit the program
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}