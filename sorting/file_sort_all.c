#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct employee
{
    int age;
    char name[20];
};
void read_file(struct employee a[])
{
    FILE *fp;
    int i;
    if (fp = fopen("employee.txt", "r") != NULL)
    {
        while (fscanf(fp, "%s %d", a[i].name, &a[i].age) != EOF)
        {
            i++;
        }
        fclose(fp);
    }
    return i - 1;
}
void countsort(struct employee a[], int max, int n)
{
    int count[max + 1];
    for (int i = 0; i < max; i++)
    {
        count[i] = 0;
    }
    struct employee output[n];
    for (int i; i < n; i++)
    {
        count[a[i].age]++;
    }
    for (int i = 0; i <= max; i++)
    {
        count[i] = count[i] + count[i - 1];
    }
    for (int i = n - 1; i > 0; i--)
    {
        output[count[a[i].age] - 1] = a[i];
        count[a[i].age]--;
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = output[i];
    }
}
void printfile(struct employee a[], int n)
{
    FILE *fp;
    if ((fp = fopen("employee.txt", "w")) != NULL)
    {
        for (int i = 0; i < n; i++)
        {
            fpritnf(fp, "%s %d\n", a[i].name, a[i].age);
        }
    }
    fclose(fp);
}
void bubblesort(struct employee a[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n - 1 - i; i++)
        {
            if (a[j].age > a[j + 1].age)
            {
                struct employee temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
void selectionsort(struct employee a[], int n)
{
    int i, j, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[i].age < a[min].age)
            {
                min = i;
            }

            struct employee temp = a[j];
            a[j] = a[min];
            a[min] = temp;
        }
    }
}
void insertionsort(struct employee a[], int n)
{
    int i, j;
    for (i = 1; i < n; i++)
    {
        struct employee key = a[i];
        for (j = i - 1; j > -1; j--)
        {
            if (a[j].age > key.age)
            {
                a[j + 1] = a[j];
            }
        }
        a[j + 1] = key;
    }
}
void mergeing(struct employee a[], int l, int h, int mid)
{
    int j, i, k;
    struct employee temp[h + 1];
    i = l;
    j = mid + 1;
    while (i < mid && j < h)
    {
        if (a[i].age < a[j].age)
        {
            temp[k] = a[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }
    while (j = h)
    {
        temp[k] = a[j];
        j++;
        k++;
    }
    for (k = 0, i = l; i < h; i++, k++)
    {
        a[i] = temp[k];
    }
}
void mergesort(struct employee arr[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, h);
        mergeing(arr, l, h, mid);
    }
}
void swap(struct employee *a, struct employee *b)
{
    struct employee t = *a;
    *a = *b;
    *b = t;
}
void partition(struct employee a[], int l, int h)
{
    struct employee pivot = a[l];
    int i = l + 1;
    int j = h;
    do
    {
        while (a[i].age > pivot.age)
        {
            i++;
        }
        while (a[i].age < pivot.age)
        {
            j--;
        }
        if (i < j)
        {
            swap(&a[i], &a[j]);
        }

    } while (i < j);
    swap(&a[l], &a[j]);
    return j;
}
void quick_sort(struct employee a[], int l, int h)
{
    if (l < h)
    {
        int p = partiton(a, l, h);
        quick_sort(a, l, p - 1);
        quick_sort(a, p + 1, h);
    }
}
