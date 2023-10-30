#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    char name[50];
    int age;
};

int read_file(struct Employee a[]) {
    int i = 0;
    FILE *fp;
    if ((fp = fopen("employees.txt", "r")) != NULL) {
        while (fscanf(fp, "%s %d", a[i].name, &a[i].age) != EOF) {
            i++;
        }
        fclose(fp); // Close the file when done reading
    }
    return i;
}

void selectionsort(struct Employee arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min =i;
        for (int j = i+1; j < n; j++) {
            if (arr[j].age > arr[min].age) {
                min=j ;
            }
           struct Employee temp = arr[j];
                arr[j] = arr[min];
                arr[min] = temp;
        }
    }
}
void print_file(struct Employee arr[], int n) {
    // Open the file for writing (replace "emp.txt" with the name of your file)
    FILE *file = fopen("employees.txt", "w");

    // Check if the file opened successfully
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    }

    // Write the sorted data back to the file
    for (int i = 0; i < n; i++) {
        fprintf(file, "%s %d\n", arr[i].name, arr[i].age);
    }

    // Close the file
    fclose(file);
}

int main() {
    struct Employee employees[100]; // Assuming a maximum of 100 employees
    int n = read_file(employees);

    if (n > 0) {
        
        selectionsort(employees, n);
        print_file(employees,n);
        printf("Employees sorted by age and saved back to the file.\n");
    } else {
        printf("No employee data found in the file.\n");
    }

    return 0;
}
