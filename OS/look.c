#include<stdio.h>
#include<stdlib.h>

int main(){
    int RQ[100],i,j,n,THM=0,initial,size,move;
    printf("Enter no of request:\t");
    scanf("%d",&n);
    printf("enter the request sequence:\n");
    for(i=0;i<n;i++)
        scanf("%d",&RQ[i]);
    printf("Enter initial head position:\t");
    scanf("%d",&initial);
    printf("enter total disk size:\t");
    scanf("%d",&size);
    printf("enter the head movement direction high 1 and low 0:\t");
    scanf("%d",&move);
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(RQ[j] > RQ[j+1]){
                int temp = RQ[j];
                RQ[j] = RQ[j+1];
                RQ[j+1] = temp;
            }
        }
    }
    int index = 0;
    for(i=0;i<n;i++){
        if(initial < RQ[i]){
            index = i;
            break;
        }
    }
    if(move==1){
        for(i=index;i<n;i++){
            THM += abs(RQ[i] - initial);
            initial = RQ[i];
        }
        for(i=index-1;i>=0;i--){
            THM += abs(RQ[i] - initial);
            initial = RQ[i];
        }
    } else{
        for(i=index-1;i>=0;i--){
            THM += abs(RQ[i] - initial);
            initial = RQ[i];
        }
        for(i=index;i<n;i++){
            THM += abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }
    printf("Total head movement is %d\n", THM);
    return 0;
}

