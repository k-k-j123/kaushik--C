#include<stdio.h>
int main()
{
    int a,b;
    printf("enter value of a and b");
    scanf("%d%d",&a,&b);
    a+=b;
   printf("the addition of a and b is:%d\n",a);
    a-=b;
     printf("the substraction of a and b is:%d\n",a);
    a*=b;
     printf("the multiplication of a and b is:%d\n",a);
    a/=b;
     printf("the division of a and b is:%f\n",a);
    return 0;
 
}