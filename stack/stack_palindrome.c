#include<stdio.h>
#include<string.h>
#include "sstack.h"
int main(){
    struct stack s;
    char str[20],t[20];
    printf("\nenter string\n");
    scanf("%s",str);
    int i;
    for(i=0;i<strlen(str);i++){
        push(&s,str[i]);
    }
    for(i=0;i<strlen(str);i++){
        if(str[i]!=pop(&s)){
            printf("\nnot a palindrome");
            return 0;
        }
    }
    printf("\npalindrome");
    return 0;
    
}