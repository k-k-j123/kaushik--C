#include<stdio.h>
#include<stdlib.h>
int main()
{
    char ch;
    int count;
    FILE *fp;
    fp=fopen("a.txt","r");
    if(fp==NULL)
    {
        printf("\nerror opening the file");
        exit(-1);
    }

    printf("\nprinting alternate characters from file\n");
    while((ch=fgetc(fp))!=EOF)
    {
        if(count%2==0)
        {
            printf("%c ",ch);
        }
        count++;
    }
}