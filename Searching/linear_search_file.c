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
    if((fp=fopen("city.txt","r"))!=NULL)
    {
        while(!feof(fp))
        {
            fscanf(fp,"%s%d",a[i].name,&a[i].code);
            i++;
        }
    }
    return (i-1);
}
void search(record *a,int n,char x[20])
{
    int i;
    for(i=0;i<n;i++)
    {
        if(strcmp(a[i].name,x)==0){
           printf("\n%s=%d\n",a[i].name,a[i].code);
        }
        else if(i==n){
            printf("\ncity not found\n");
        }
    }
}
int main()
{
    char x[20];
    int n;
    n= read_file(city);
    printf("\nenter city name\n");
    scanf("%s",x);
    search(city,n,x);
    return 0;
}
