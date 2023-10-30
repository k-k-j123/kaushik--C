#include<stdio.h>
int main()
{
    int a,b,sum=0,sub=0,mul=0,i;
    printf("\nenter two numbers ");
    scanf("%d%d",&a,&b);
    printf("\n1:addition \n2:substraction \n3:multiplication \n4:exit\nChoose an option from above ");
    scanf("%d",&i);
    switch(i)
    {
        case 1: sum=a+b;
                printf("\naddition is %d",sum);
                break;
        case 2: sub=a-b;
                printf("\naddition is %d",sub);
                break;
        case 3: mul=a*b;
                printf("\naddition is %d",mul);
                break;
        case 4: break;
        default:printf("\n invalid choice");
                 break;
    }
    return 0;
    
}