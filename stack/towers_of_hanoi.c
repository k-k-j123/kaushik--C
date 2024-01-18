#include<stdio.h>
#include<stdlib.h>
void hanoi(int n,int start,int end)
{
    if(n==1)
        printf("%d -> %d\n",start,end);
    else{
        int other=6-(start+end);
        hanoi(n-1,start,other);
        printf("%d -> %d\n",start,end);
        hanoi(n-1,other,end);
    }
}
int main()
{
    int n,start,end;
    printf("\nenter the number of disks\t");
    scanf("%d",&n);
    printf("\nenter the start rod pos\t");
    scanf("%d",&start);
    printf("\nenter the end rod pos\t");
    scanf("%d",&end);
    hanoi(n,start,end);
    return 0;

}
