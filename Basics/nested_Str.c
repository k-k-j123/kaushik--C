#include<stdio.h>
struct date 
{
    int d;
    int m;
    int y;
};
struct person
{
    char name ;
    char address;
    struct date day;
};
int main()
{
    struct person a[10];
    int n,i;
    printf("\nhow many person\t");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nenter name and address\t");
        scanf("%s%s",a[i].name,a[i].address);
        printf("\nenter date (%d %d %d)");
        scanf("%d%d%d",&a[i].day.d,&a[i].day.m,&a[i].day.y);
    }
    printf("\ndisplay record\n");
    for ( i = 0; i < n; i++)
    {
      printf("\nnsmr=%s , address=%s ",a[i].name,a[i].address);
      printf("date=%d/%d/%d",a[i].day.d,a[i].day.m,a[i].day.y);
    }
    return 0;
    
}
