#include <stdio.h>
#define MAX 20
void lru(int frames,int references,int ref[]){
	int sp=0,mem[frames],faults=0,timestamp[MAX];
	for(int i=0;i<frames;i++)
		mem[i]=0;
	
	for(int i=0;i<references;i++){
		int oldest=0,found=0;
		for(int j=0;j<frames;j++){
			if(mem[j]==ref[i]){
				timestamp[j]=i;
				found=1;
				break;
			}
			if(j==0 || timestamp[oldest]>timestamp[j]){
				oldest=j;
			}
		}
		if(!found){
			if(sp<frames){
				mem[sp]=ref[i];
				timestamp[sp]=i;
				sp++;
			}
			else{
				mem[oldest]=ref[i];
				timestamp[oldest]=i;
			}
			faults++;
		}
		printf("\nMemory:");
		for(int i=0;i<frames;i++){
			printf("%d ",mem[i]);
		}
	}
	printf("\n\nnumber of page faults:%d\n",faults);
}
int main(){
	int frames,references;
	printf("\nenter number of frames\t");
	scanf("%d",&frames);
	printf("\nenter number of reference string\t");
	scanf("%d",&references);
	int ref[references];
	printf("\nenter the reference string:\n");
	for(int i=0;i<references;i++){
		scanf("%d",&ref[i]);
	}
	printf("\nrefrence string is \n");
	for(int i=0;i<references;i++){
		printf("%d ",ref[i]);
	}
	printf("\n\nLRU implementation");
	lru(frames,references,ref);
	return 0;
}