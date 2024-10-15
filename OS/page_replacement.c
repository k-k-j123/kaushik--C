#include<stdio.h>
#include<stdlib.h>
#define max 20
void fifo(int frames,int references,int ref[]){
    int sp=0,mem[frames],faults=0;
    for(int i=0;i<frames;i++){
        mem[i]=0;
    }
    for(int i=0;i<references;i++){
        int found=0;
        for(int j=0;j<frames;j++){
            if(mem[j]=ref[i]){
                found=1;
                break;
            }
        }

        if(!found){
            mem[sp]=ref[i];
            sp=(sp+1)%frames;
            faults++;
        }

        printf("Memory:");
        for(int i=0;i<frames;i++){
            printf("%d ",mem[i]);
        }
    }
}
void lru(int frames,int references,int ref[]){
    int sp=0,mem[frames],faults=0,timestamp[20];
    for(int i=0;i<frames;i++){
        mem[i]=0;
    }
    for(int i=0;i<references;i++){
        int found=0,oldest=0;
        for(int j=0;j<frames;j++){
            if(mem[j]==ref[i]){
                found=1;
                timestamp[oldest]=j;
                break;
            }
            if(j==0 || mem[oldest]>mem[j]){
                oldest=j;
            }
        }
        if(!found){
            if(sp<frames){
                mem[sp]=ref[i];
                timestamp[sp]=i;
                sp++;
            }else{
                mem[oldest]=ref[i];
                timestamp[oldest]=i;
            }
        }
        printf("Memory:");
        for(int i=0;i<frames;i++){
            printf("%d ",mem[i]);
        }
    }
}