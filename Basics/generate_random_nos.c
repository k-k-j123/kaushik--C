#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *fp;
    fp=fopen("rand_int.txt","w");
    int n=1000;
    for(int i=0;i<=n;i++){
        int no=rand()%10;
        fprintf(fp,"%d\n",no);
    }
    return 0;
}