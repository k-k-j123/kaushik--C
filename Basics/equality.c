#include<stdio.h>
int main()
{
    int a ,b,i,temp,x;
    float r,q;
    printf("\n enter values of a And b\n");
    scanf("%d%d",&a,&b);
    printf("\nChoose the following from below");
    printf("\n1:check if a is equal to b");
    printf("\n2:check if a is less thanb b");
    printf("\n3:divide a by b and display the quotient and remainder");
    printf("\n4:accept a number and check range");
    printf("\n5:swap values of x and y\n");
    scanf("%d",&i);
    switch(i)
    {
        case 1:
        if(a==b)
        {
         printf("\na is equal to b");
        }
        else{
         printf("\n a is not equal to b");
        }
        break;
        case 2:
        if(a<b)
        {
         printf("\na is less than b");
        }
        else
        {
         printf("\n a is not less than b");
        }
        break;
        case 3:
        q=(float)a/b;
        r=a%b;
        printf("\n divison of a and b is %f",q);
        printf("\n remiander of a and b is %f",r);
        break;
        case 4:
        printf("\nenter a number");
        scanf("%d",&x);
        if(x>=a && x<=b)
        {
            printf("\nin range");
        }
        else
        {
            printf("\nnot in range");
        }
        break;
        case 5:
        printf("\nbefore swapping a is %d and b is %d",a,b);
        temp=a;
        a=b;
        b=temp;
        printf("\nafter swapping a is %d and b is %d",a,b);  
        break;                            
        default:
        printf("\ninvalid choice");
        break;
    }
    return 0;
}