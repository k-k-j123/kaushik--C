#include<stdio.h>
#include<unistd.h>
int main()
{
	int pid,retnice;
	printf("press DEL to stop process\n");
	pid=fork();
	for(;;){
		if(pid==0){
			retnice=nice(-5);//positive means lower priority
			printf("child gets higher priority %d\n",retnice);
			sleep(1);
		}
		else{
			retnice=nice(5);//lower means higher priority
			printf("parent gets lower priority %d\n",retnice);
			sleep(1);
		}
	}
}