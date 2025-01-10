#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200

typedef struct dir {
    char frame[20];
    int start, length;
    struct dir* next;
} NODE;

NODE* first = NULL, *last = NULL;
int bit[MAX], n;

void init() {
    int i;
    printf("Enter total no of disk blocks: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        bit[i] = 0;
    }
}

void show_bitvector() {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d", bit[i]);
    }
    printf("\n");
}

void show_dir() {
    NODE* p = first;
    printf("File\t\tStart\tLength\n");
    while(p != NULL) {
        // Ensure proper formatting even if filenames are short
        printf("%-20s\t%d\t%d\n", p->frame, p->start, p->length);
        p = p->next;
    }
}


NODE* create_node(const char* fname, int nob) {
    NODE* p = (NODE*)malloc(sizeof(NODE));
    // Copy the filename into the frame array with proper null-termination
    snprintf(p->frame, sizeof(p->frame), "%s", fname);  // Safely copy string
    p->start = 0;
    p->length = nob;
    p->next = NULL;
    return p;
}


void create() {
    NODE* p;
    char fname[20];
    int nob, i = 0, j = 0, start;

    printf("Enter file name: ");
    scanf("%19s", fname);
    printf("Enter no of blocks: ");
    scanf("%d", &nob);

    while(1) {
        // Look for the first contiguous block of size 'nob'
        while(i < n && bit[i] == 1) {
            i++; // Skip occupied blocks
        }

        if(i >= n) {
            printf("Fail to create file %s (No free space)\n", fname);
            return; 
        }

        start = i;  // The starting block index
        j = 0;       // Number of free blocks found

        // Check if enough contiguous free blocks are available
        while(j < nob && i < n && bit[i] == 0) {
            i++;
            j++;
        }

        if(j == nob) {
            // If we found enough free blocks, allocate them
            p = create_node(fname, nob);
            if(first == NULL) {
                first = p;
                last = p;
            } else {
                last->next = p;
                last = p;
            }
            // Mark blocks as used
            for(int k = start; k < start + nob; k++) {
                bit[k] = 1;
            }
            printf("File %s created successfully\n", fname);
            return;
        }

        // If we couldn't find enough contiguous blocks, try again
        // i will keep incrementing in the outer loop until enough blocks are found
    }
}


void delete_file(char* fname) {
    NODE* p = first, *q = NULL;
    while(p != NULL) {
        if(strcmp(p->frame, fname) == 0) {
            break;
        }
        q = p;
        p = p->next;
    }
    if(p == NULL) {
        printf("File %s not found\n", fname);
        return;
    }
    for(int i = p->start; i < p->start + p->length; i++) {
        bit[i] = 0;
    }
    if(p == first) {
        first = first->next;
    } else if(p == last) {
        last = q;
        last->next = NULL;
    } else {
        q->next = p->next;
    }
    free(p);
    printf("File %s deleted successfully\n", fname);
}

int main() {
    int ch;
    init();
    while(1) {
        printf("1.Show bit vector\n");
        printf("2.Create new file\n");
        printf("3.Show directory\n");
        printf("4.Delete File\n");
        printf("5.Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                show_bitvector();
                break;
            case 2:
                create();
                break;
            case 3:
                show_dir();
                break;
            case 4:
                char del_fname[20];
                printf("Enter file to be deleted: ");
                scanf("%19s", del_fname);
                delete_file(del_fname);
                break;
            case 5:
                exit(0);
        }
    }
    return 0;
}

