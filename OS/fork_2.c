#include<stdio.h>
#include<unistd.h>
int main()
{
  int pid;
  printf("before fork\n");
  pid=fork();
  if(pid==0)
	printf("pid:%d\tI am a child process with Id:\t%d\n",pid,getpid());
  else if(pid>0)
	printf("pid:%d\tI am a parent process with Id:\t%d\n",pid,getpid());
  else
	printf("fork failed\n");

  return 0;
}


