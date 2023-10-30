#include<stdio.h>
int main()
{
    int a ,b,add,sub,mul,divi;
    char x;
    printf("enter a operator(+,-,*,/)\n");
    scanf("%c",&x);
    switch(x)
    {
        case  '+':
        printf("\n enter two numbers\t");
        scanf("%d%d",&a,&b);
        add=a+b;
        printf("\n addition of a and b is%d",add);
        break;
        case  '-':
        printf("\n enter two numbers\t");
        scanf("%d%d",&a,&b);
        sub=a-b;
        printf("\n substraction of a and b is%d",sub);
        break;
        case  '*':
        printf("\n enter two numbers\t");
        scanf("%d%d",&a,&b);
        mul=a*b;
        printf("\n multiplication of a and b is%d",mul);
        break;
        case  '/':
        printf("\n enter two numbers\t");
        scanf("%d%d",&a,&b);
        divi=a/b;
        printf("\n addition of a and b is%d",divi);
        break;
        default:
        printf("\n invalid choice");
        break;
    }


}