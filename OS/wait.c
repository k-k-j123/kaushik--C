#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
	int p;
	printf("before fork\n");
	p=fork();
	if(p==0)
		printf("My child id is:%d\n",getpid());
	else
	{
		wait(NULL);
		printf("my parent id is:%d\n",getpid());
	}
	return 0;
	//used to wait until a process is compleated here parent will wait until child gets compleated
}