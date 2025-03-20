#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 200

// Structure to represent a file in the directory
typedef struct dir {
    char fname[20];       // File name
    int blocks[max];      // Array to store block numbers allocated to the file
    int block_count;      // Number of blocks allocated to the file
    struct dir *next;     // Pointer to the next file in the directory
} NODE;

// Global variables
NODE *first = NULL, *last = NULL; // Pointers to the first and last file in the directory
int n = 50;                       // Total number of disk blocks (can be changed by user)
int fb;                            // Number of free blocks
int bit[max];                      // Bit vector to track free (0) and used (1) blocks

// Function to display the bit vector
void show_bitvector() {
    printf("Bit Vector:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", bit[i]); // Print the status of each block
    }
    printf("\n");
}

// Function to display the directory (list of files and their block numbers)
void show_dir() {
    NODE *p = first; // Start from the first file
    printf("File\tBlocks\n");
    while (p != NULL) {
        printf("%s\t", p->fname); // Print the file name
        for (int i = 0; i < p->block_count; i++) {
            printf("%d ", p->blocks[i]); // Print the block numbers allocated to the file
        }
        printf("\n");
        p = p->next; // Move to the next file
    }
}

// Function to create a new file
void create() {
    char fname[20]; // File name
    int nob;        // Number of blocks required
    printf("Enter file name: ");
    scanf("%s", fname);
    printf("Enter no of blocks: ");
    scanf("%d", &nob);

    // Check if enough free blocks are available
    if (nob > fb) {
        printf("Failed to create file %s. Not enough free blocks.\n", fname);
        return;
    }

    // Create a new file node
    NODE *p = (NODE *)malloc(sizeof(NODE));
    strcpy(p->fname, fname);  // file name
    p->block_count = 0;      // Initialize block count
    p->next = NULL;          // Initialize the next pointer

    // Allocate blocks for the file
    for (int i = 0; i < n && p->block_count < nob; i++) {
        if (bit[i] == 0) { // If the block is free
            p->blocks[p->block_count++] = i; // Add the block to the file's block list
            bit[i] = 1;                      // Mark the block as used
            fb--;                           // Reduce the number of free blocks
        }
    }

    // Add the file to the directory
    if (first == NULL) {
        first = p; // If directory is empty, set as first file
    } else {
        last->next = p; // Otherwise, add to the end of the list
    }
    last = p; // Update the last file pointer

    printf("File %s created successfully.\n", fname);
}

// Function to delete a file
void delete() {
    char fname[20]; // File name to delete
    printf("Enter file name to be deleted: ");
    scanf("%s", fname);

    NODE *p = first, *q = NULL; // Pointers to traverse the directory
    while (p != NULL && strcmp(p->fname, fname) != 0) {
        q = p;       // Previous file
        p = p->next; // Current file
    }

    // If file not found
    if (p == NULL) {
        printf("File %s not found.\n", fname);
        return;
    }

    // Free the blocks used by the file
    for (int i = 0; i < p->block_count; i++) {
        bit[p->blocks[i]] = 0; // Mark the block as free
        fb++;                  // Increase the number of free blocks
    }

    // Remove the file from the directory
    if (p == first) {
        first = first->next; // If it's the first file, update the first pointer
    } else if (p == last) {
        last = q;           // If it's the last file, update the last pointer
        last->next = NULL;
    } else {
        q->next = p->next; // If it's in the middle, bypass the file
    }
    free(p); // Free the memory allocated for the file node

    printf("File %s deleted successfully.\n", fname);
}

int main() {
    // Initialize the bit vector
    fb = n; // Initially, all blocks are free
    for (int i = 0; i < n; i++) {
        bit[i] = 0; // Mark all blocks as free
    }

    // Menu-driven interface
    int ch;
    while (1) {
        printf("\n1. Show bit vector\n");
        printf("2. Create new file\n");
        printf("3. Show directory\n");
        printf("4. Delete File\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                show_bitvector(); // Show the bit vector
                break;
            case 2:
                create(); // Create a new file
                break;
            case 3:
                show_dir(); // Show the directory
                break;
            case 4:
                delete(); // Delete a file
                break;
            case 5:
                exit(0); // Exit the program
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}