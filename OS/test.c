#include <stdio.h>
#include <stdlib.h>

int main() {
    int cnt = 0;
    char ch;
    int n = -5;
    FILE *handle = fopen("fork.c", "r");

    // Check if file was successfully opened
    if (handle == NULL) {
        printf("Could not open file\n");
        return 1;
    }

    // Count total characters
    while ((ch = fgetc(handle)) != EOF) {
        if(ch=='\n')
            cnt++;
    }

    // Reset file pointer
    rewind(handle);

    int index = cnt + n;
    int i = 0;
    int line = 0;

    // Print specific line
    while ((ch = fgetc(handle)) != EOF) {
        if (ch == '\n') {
            line++;
        }
        if (line >= index) {
            printf("%c", ch);
        }
    }

    fclose(handle);
    return 0;
}