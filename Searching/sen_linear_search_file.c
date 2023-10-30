#include <stdio.h>
#include <string.h>

typedef struct city
{
    char name[20];
    int code;
} record;

record city[101]; // Increase the array size by 1 to add a sentinel element.

int read_file(record *a)
{
    int i = 0;
    FILE *fp;
    if ((fp = fopen("city.txt", "r")) != NULL)
    {
        while (!feof(fp))
        {
            fscanf(fp, "%s%d", a[i].name, &a[i].code);
            i++;
        }
        fclose(fp);
    }
    return i; // Return the actual number of records read.
}

void search(record *a, int n, char x[20])
{
    int i = 0;
    
    // Add a sentinel element to the end of the array.
    strcpy(a[n].name, x);
    a[n].code = 0;
    
    while (strcmp(a[i].name, x) != 0)
    {
        i++;
    }
    
    if (i < n) // If i is less than n, the element was found.
    {
        printf("\n%s=%d\n", a[i].name, a[i].code);
    }
    else
    {
        printf("\ncity not found\n");
    }
}

int main()
{
    char x[20];
    int n;
    n = read_file(city);
    printf("\nenter city name\n");
    scanf("%s", x);
    search(city, n, x);
    return 0;
}
