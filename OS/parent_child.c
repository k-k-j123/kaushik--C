#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
int main(){
	int pid=fork();
	if(pid>0){
		//wait(NULL);
		printf("parent process\n");
		printf("ID:%d\n\n",getpid());
	}
	else if(pid==0){
		printf("\nchild process");
		printf("Id:%d\n",getpid());
		sleep(10);
		printf("\nchild process");
		printf("Id;%d\n",getpid());
		printf("Parent terminated then P-ID:%d\n",getppid());
		//orphan process are always adopted by init process whose pid is always 1
	}
	else{
		printf("failed to create a child process\n");
	}
	return 0;
}

