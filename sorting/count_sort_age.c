#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee
{
    char name[50];
    int age;
};

void countingSortByAge(struct Employee A[], int n, int maxAge)
{
    // Counting Sort by age
    int count[maxAge + 1];
    for(int i=0;i<maxAge;i++){
        count[i]=0;//initialize by zero 
    }
    struct Employee output[n];

    // Count the occurrences of each age
    for (int i = 0; i < n; i++)
    {
        count[A[i].age]++;
    }

    // Modify the count array to store the actual position of each age in the sorted output
    for (int i = 1; i <= maxAge; i++)
    {
        count[i] += count[i - 1];
    }

    // Build the sorted output array
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[A[i].age] - 1] = A[i];
        count[A[i].age]--;
    }

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
        int maxAge = 0;

        // Find the maximum age to determine the range
        for (int i = 0; i < n; i++)
        {
            if (employees[i].age > maxAge)
            {
                maxAge = employees[i].age;
            }
        }

        countingSortByAge(employees, n, maxAge);
        print_file(employees, n);
        printf("Employees sorted by age and saved back to the file.\n");
    }
    else
    {
        printf("No employee data found in the file.\n");
    }

    return 0;
}
