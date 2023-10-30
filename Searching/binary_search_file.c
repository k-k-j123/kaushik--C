#include<stdio.h>
#include<string.h>
typedef struct city
{
    char name[20];
    int code;
}record;
record city[100];
int read_file(record *a)
{
    int i=0;
    FILE *fp;
    if((fp=fopen("sorted_cities.txt","r"))!=NULL)
    {
        while(!feof(fp))
        {
            fscanf(fp,"%s%d",a[i].name,&a[i].code);
            i++;
        }
    }
    return (i);
}
int search(record *a,int n,char x[20],int l,int h)
{
   if(l>h){
    return -1;
   }
    int mid = (l + h) / 2;

    if(strcmp(a[mid].name,x)==0)
        return mid;
    
    if(strcmp(a[mid].name,x)>0)
        return search(a,n,x,l,mid-1);

    if(strcmp(a[mid].name,x)<0)
        return search(a,n,x,mid+1,h);
   
   
}
int main()
{
    char x[20];
    int n;
    n= read_file(city);
    
    printf("\nenter city name\n");
    scanf("%s",x);
    int res=search(city,n,x,0,n-1);
    if(res == -1)
        printf("\ncity not found");
    else
        printf("\n%s=%d\n",city[res].name,city[res].code);

    return 0;
}

// #include <stdio.h>
// #include <string.h>

// typedef struct city
// {
//     char name[20];
//     int code;
// } record;

// record city[100];

// int read_file(record *a)
// {
//     int i = 0;
//     FILE *fp;
//     if ((fp = fopen("sorted_cities.txt", "r")) != NULL) // Assume the file is sorted.
//     {
//         while (!feof(fp))
//         {
//             fscanf(fp, "%s%d", a[i].name, &a[i].code);
//             i++;
//         }
//         fclose(fp);
//     }
//     return i;
// }

// int binary_search_recursive(record *a, int low, int high, char x[20])
// {
//     if (low > high)
//     {
//         return -1; // Element not found.
//     }

//     int mid = (low + high) / 2;
//     int cmp = strcmp(a[mid].name, x);

//     if (cmp == 0)
//     {
//         return mid; // Element found at index 'mid'.
//     }
//     else if (cmp < 0)
//     {
//         return binary_search_recursive(a, mid + 1, high, x); // Adjust the search range to the right half.
//     }
//     else
//     {
//         return binary_search_recursive(a, low, mid - 1, x); // Adjust the search range to the left half.
//     }
// }

// int main()
// {
//     char x[20];
//     int n;
//     n = read_file(city);
//     printf("\nenter city name\n");
//     scanf("%s", x);

//     int result = binary_search_recursive(city, 0, n - 1, x);

//     if (result != -1)
//     {
//         printf("\n%s=%d\n", city[result].name, city[result].code);
//     }
//     else
//     {
//         printf("\ncity not found\n");
//     }

//     return 0;
// }
