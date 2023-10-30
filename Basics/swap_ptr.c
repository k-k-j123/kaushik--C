#include<stdio.h>
void swap(int *x,int *y);
int main()
{
    int a,b,temp;
    
    printf("\nenter a and b\t");
    scanf("%d%d",&a,&b);
    printf("\nnumber before swapping are :-a=%d and b=%d\n",a,b);
    swap(&a,&b);
    printf("\nnumber after swapping are :-a=%d and b=%d\n",a,b);
    return 0;
}
void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;

}