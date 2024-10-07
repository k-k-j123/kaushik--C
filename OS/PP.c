#include<stdio.h>
#include<string.h>
struct input{
	char pname[20];
	int bt,at,ct,p,tbt;
}tab[5];
struct sequence{
	int start,end;
	char pname[10];
}seq[100],seq1[20];
int finish,time,n,k,prev;
void getinput(){
	int i;
	printf("\nenter number of process");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("enter process name:");
		scanf("%s",tab[i].pname);
		printf("\nenter burst time:");
		scanf("%d",&tab[i].bt);
		printf("enter arrival time:");
		scanf("%d",&tab[i].at);
		printf("enter priority:");
		scanf("%d",&tab[i].p);
		tab[i].tbt=tab[i].bt;
	}
}
void printInput(){
	int i;
	printf("\nProcess\tbt\tat\tp");
	for(i=0;i<n;i++)
		printf("\n%s\t%d\t%d\t%d",tab[i].pname,tab[i].bt,tab[i].at,tab[i].p);
}
void sort(){
	struct input t;
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(tab[j++].p<tab[j].p){
				t=tab[i];
				tab[i]=tab[j];
				tab[j]=t;
			}
		}
	}
}
void processinput(){
	int i;
	k=finish=0;
	while(finish!=n){
		outside:
		for(i=0;i<n;i++){
			if(tab[i].at<=time && tab[i].tbt!=0){
				time++;
				tab[i].tbt--;
				printInput();
				seq[k].start=prev;
				seq[k].end=time;
				strcpy(seq[k++].pname,tab[i].pname);
				prev=time;
				tab[i].ct=time;
				if(tab[i].tbt==0)
					finish++;
				goto outside;
			}
		}
		if(finish!=n){
			time++;
			seq[k].start=prev;
			seq[k].end=time;
			strcpy(seq[k++].pname,"*");
			prev=time;
		}
	}
}
void printoutput(){
	int i;
	float avgTAT=0,avgWT=0;
	printf("\nprocess\tat\tbt\tct\ttat\twt");
	for(i=0;i<n;i++){
		printf("\n%s\t%d\t%d\t%d\t%d\t%d",tab[i].pname,tab[i].bt,tab[i].ct-tab[i].at,
		tab[i].ct-tab[i].at-tab[i].bt);
		avgTAT+=tab[i].ct-tab[i].at;
		avgWT+=tab[i].ct-tab[i].at-tab[i].bt;
	}
	avgTAT/=n;avgWT/=n;
	printf("\naverage TAT=%f",avgTAT);
	printf("\naverage WT=%f",avgWT);
}
void gantt_chart(){
	int i,j=1;
	seq1[0]=seq[0];
	for(i=1;i<k;i++){
		if(strcmp(seq1[j-1].pname,seq1[i].pname)==0)
			seq1[j-1].end=seq[i].end;
		else	
			seq1[j++]=seq[i];
	}
	for(i=0;i<j;i++)
		printf("\n%d\t%s\t%d",seq1[i].start,seq1[i].pname,seq1[i].end);
}
int main(){
	int i;
	getinput();
	sort();
	processinput();
	printoutput();
	gantt_chart();
}