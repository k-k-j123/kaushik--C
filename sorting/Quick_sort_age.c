#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee
{
    char name[50];
    int age;
};

void swap(struct Employee *a, struct Employee *b)
{
    struct Employee t = *a;
    *a = *b;
    *b = t;
}

int partition(struct Employee A[], int low, int high)
{
    struct Employee pivot = A[low];
    int i = low + 1;
    int j = high;

    do
    {
        // Find the first element greater than or equal to the pivot
        //while (strcmp(A[i].name, pivot.name) < 0)//A[i].age>pivot.age
      while(A[i].age>pivot.age)
        {
            i++;
        }

        // Find the first element less than or equal to the pivot
        //while (strcmp(A[j].name, pivot.name) > 0)
         while (A[j].age<pivot.age)
        {
            j--;
        }
            
        if (i < j)
        {
            swap(&A[i], &A[j]);
        }
    } while (i < j);

    // Swap A[low] and A[j]
    swap(&A[low], &A[j]);
    return j;
}

void quickSort(struct Employee A[], int low, int high)
{
    if (low < high)
    {
        int p = partition(A, low, high);
        quickSort(A, low, p - 1);
        quickSort(A, p + 1, high);
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
        quickSort(employees, 0, n - 1);
        print_file(employees, n);
        printf("Employees sorted by name and saved back to the file.\n");
    }
    else
    {
        printf("No employee data found in the file.\n");
    }

    return 0;
}
