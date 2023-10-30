#include<stdio.h>
#include<string.h>
int main()
{
    char str[10];
    printf("\nenter a string\n");
    scanf("%s",str);
    
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]>='a'&& str[i]<='z')
        {
            str[i]=str[i]-32;
        }
    }
    printf("\nupper case string is\t%s",str);
}