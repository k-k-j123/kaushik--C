#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp1,*fp2;
    fp1=fopen("a.txt","r");
    fp2=fopen("b.txt","w");
     if(fp1==NULL && fp2==NULL)
    {
        printf("\nerror opening the file");
        exit(-1);
    }
    char ch;
    while((ch=fgetc(fp1))!=EOF)
    {
        fputc(ch,fp2);
    }

}
