#include<stdio.h>
#include<unistd.h>
int main()
{
  //char *temp[4];
  //temp[0]="ls";
  //temp[1]="-l";
  //temp[2]="/usr/bin";
  //temp[3]=NULL;
  //execv("/bin/ls",temp);
  execlp("/bin/ls" ,"ls //bin",NULL);
  printf("After exec Bad Command");
  return 0;
}
