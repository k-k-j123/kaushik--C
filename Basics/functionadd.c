//with parameter and with return type
#include<stdio.h>
int sum(int a,int b);
int main()
{
 int a,b,add;
 printf("\n enter two nos\n");
 scanf("%d%d",&a,&b);
 add=sum(a,b);
 printf("\naddition is %d",add);
 return 0;
}
int sum(int a,int b)
{   int c;
    c=a+b;
    return c;
}