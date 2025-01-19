#include<stdio.h>
#include<stdlib.h>
int main(){
    int RQ[100],i,n,TotalHeadMovement=0,initial,count=0;
    printf("enter the number of request\n");
    scanf("%d",&n);
    printf("enter the request sequence\n");
    for(i=0;i<n;i++)
        scanf("%d",&RQ[i]);
    printf("enter the initial head position\n");
    scanf("%d",&initial);
    while(count!=n){
        int min=1000,d,index;
        for(i=0;i<n;i++){
            d=abs(RQ[i]-initial);
            if(d<min){
                min=d;
                index=i;
            }
        }
        TotalHeadMovement+=min;
        initial=RQ[index];
        RQ[index]=1000;
        count++;
    }
    printf("Total head movement is %d\n",TotalHeadMovement);
    return 0;
}