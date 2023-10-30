#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee
{
    char name[50];
    int age;
};

void countingSortByName(struct Employee A[], int n)
{
    // Counting Sort by name
    int count[256] = {0}; // Assuming ASCII characters, adjust as needed
    struct Employee output[n];

    // Count the occurrences of each character in the employee names
    for (int i = 0; i < n; i++)
    {
        count[A[i].name[0]]++; // Using the first character of the name
    }

    // Modify the count array to store the actual position of each character in the sorted output
    for (int i = 1; i < 256; i++)
    {
        count[i] += count[i - 1]; // cumulative sum
    }

    // Build the sorted output array
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[A[i].name[0]] - 1] = A[i];
        count[A[i].name[0]]--;
    }
    /*count[A[i].name[0]] - 1 calculates the index where this employee should 
    be placed in the sorted output array. Since counting sort is a 0-based 
    index-based algorithm, subtracting 1 adjusts the index accordingly*/
    // Copy the sorted output back to the original array
    for (int i = 0; i < n; i++)
    {
        A[i] = output[i];
    }
}

int read_file(struct Employee a[])
{
    int i = 0;
    FILE *fp;
    if ((fp = fopen("employees.txt", "r")) != NULL)
    {
        while (fscanf(fp, "%s %d", a[i].name, &a[i].age) != EOF)
        {
            i++;
        }
        fclose(fp);
    }
    return i;
}

void print_file(struct Employee arr[], int n)
{
    FILE *file = fopen("employees.txt", "w");

    if (file == NULL)
    {
        printf("Unable to open the file.\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(file, "%s %d\n", arr[i].name, arr[i].age);
    }

    fclose(file);
}

int main()
{
    struct Employee employees[100];
    int n = read_file(employees);

    if (n > 0)
    {
        countingSortByName(employees, n);
        print_file(employees, n);
        printf("Employees sorted by name and saved back to the file.\n");
    }
    else
    {
        printf("No employee data found in the file.\n");
    }

    return 0;
}
