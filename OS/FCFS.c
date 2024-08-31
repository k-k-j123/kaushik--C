#include<stdio.h>
#include<string.h>
struct process{
	char PName[5];
	int AT,BT,TAT,WT,CT;
	int tempBT;
}P[10],tempStruct;
int N;

void Input(){
	int i;
	printf("\nenter number of process:");
	scanf("%d",&N);
	for(i=0;i<N;i++){
		printf("\nenter details of process %d",i+1);
		printf("\nenter process name:");
		scanf("%s",P[i].PName);
		printf("enter AT:");
		scanf("%d",&P[i].AT);
		printf("enter BT:");
		scanf("%d",&P[i].BT);
		P[i].tempBT=P[i].BT;
	}
}

void sortProcessAT(){
	int i;
	int j;
	int tval;
	char temp[5];
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			tempStruct=P[i];
			P[i]=P[j];
			P[j]=tempStruct;
		}

	}
}

void output(){
	int i;
	int totalTAT=0;
	int totalWT=0;
	for(i=0;i<N;i++){
		P[i].TAT=P[i].CT-P[i].AT;
		totalTAT=totalTAT+P[i].TAT;

		P[i].WT=P[i].TAT-P[i].BT;
		totalWT=totalWT+P[i].WT;
	}
	printf("\nProcess Details");
	printf("\n************************************");
	printf("\nPname\tAT\tBT\tTAT\tWT");
	printf("\n************************************");
	for(i=0;i<N;i++){
		printf("\n%s\t%d\t%d\t%d\t%d",P[i].PName,P[i].AT,P[i].BT,P[i].TAT,P[i].WT);
	}
	printf("\n************************************");
	printf("\nAvg TAT:%d/%d",totalTAT,N);
	printf("\nAvg WT:%d/%d",totalWT,N);
}

void FCFS(){
	int time=0;
	int finish=0;
	int i;
	int flag=0;
	while(finish!=1){
		flag=0;
		for(i=0;i<N;i++){
			if(P[i].AT<=time && P[i].tempBT!=0)
			{
				printf("|%d %s",time,P[i].PName);
				time=time+P[i].tempBT;
				printf(" %d|",time);
				P[i].tempBT=0;
				P[i].CT=time;
				flag=1;
			}
		}
		if(flag==0){
			printf("|%d # ",time);
			time++;
			printf(" %d|",time);
		}
		for(i=0;i<N;i++){
			if(P[i].tempBT==0)
				continue;
			else
				break;
		}
		if(i==N)
			finish=1;
	}
}

int main(){
	Input();
	sortProcessAT();
	FCFS();
	output();
	return 0;
}
