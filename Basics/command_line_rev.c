#include<stdio.h>
#include<string.h>
#define max_len 20
int main(int argc,int argv[])
{
    char str[max_len];
    strcpy(str,argv[1]);
    str[max_len-1]='\0';
    printf("\nstring in reverse is \n%s", strrev(str));
    
}