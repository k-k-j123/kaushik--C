//without parameter and without return type
#include<stdio.h>
void sum();
int main()
{
 int add;
 sum();
 return 0;
}
void sum()
{  
int a,b,c;
printf("\n enter two nos\n");
scanf("%d%d",&a,&b);
c=a+b;
printf("\naddition is %d",c);
    
}