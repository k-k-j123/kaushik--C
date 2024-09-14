#include<stdio.h>
struct process{
	char PName[5];
	int AT,BT,TAT,WT,CT;
	int tempBT;
}p[10],tempStruct;
int N;
int TQ;
void input(){
	int i;
	printf("\nenter number of processes:");
	scanf("%d",&N);
	for(i=0;i<N;i++){
		printf("\nenter details of process %d",i+1);
		printf("\nenter process name\t");
		scanf("%s",p[i].PName);

		printf("\nenter AT\t");
		scanf("%d",&p[i].AT);

		printf("\nenter BT\t");
		scanf("%d",&p[i].BT);
		p[i].tempBT=p[i].BT;
	}
	printf("\nenter time quantum\t");
	scanf("%d",&TQ);
}

void sortProcessAT(){
	int i;
	int j;
	int tval;
	char temp[5];
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(p[i].AT<p[j].AT){
			tempStruct=p[i];
			p[i]=p[j];
			p[j]=tempStruct;
			}
		}

	}
}

void RR(){
	int time=0;
	int finish=0;
	int i;
	int flag=0;
	while(finish!=1){
		flag=0;
		for(i=0;i<N;i++){
			if(p[i].AT<=time && p[i].tempBT!=0){
				flag=1;
				printf("|%d %s",time,p[i].PName);
				if(p[i].tempBT>TQ){
					time=time+TQ;
					p[i].tempBT=p[i].tempBT-TQ;
				}else{
					time=time+p[i].tempBT;
					p[i].tempBT=0;
					p[i].CT=time;
				}
				printf(" %d|",time);
			}
		}
		if(flag==0){
			printf("|%d ##",time);
			time++;
			printf(" %d|",time);
		}

		for(i=0;i<N;i++){
			if(p[i].tempBT==0)
				continue;
			else
				break;
		}
		if(i==N)
			finish=1;
	}
}
void output(){
	int i;
	int totalTAT=0;
	int totalWT=0;
	for(i=0;i<N;i++){
		p[i].TAT=p[i].CT-p[i].AT;
		totalTAT=totalTAT+p[i].TAT;
		p[i].WT=p[i].TAT-p[i].BT;
		totalWT=totalWT+p[i].WT;
	}
	
	printf("\nProcess Details");
	printf("\n************************************");
	printf("\nPname\tAT\tBT\tTAT\tWT");
	printf("\n************************************");
	for(i=0;i<N;i++){
		printf("\n%s\t%d\t%d\t%d\t%d",p[i].PName,p[i].AT,p[i].BT,p[i].TAT,p[i].WT);
	}
	printf("\n************************************");
	printf("\nAvg TAT:%d/%d",totalTAT,N);
	printf("\nAvg WT:%d/%d",totalWT,N);
}
int main(){
	input();
	sortProcessAT();
	RR();
	output();
	return 0;
}
