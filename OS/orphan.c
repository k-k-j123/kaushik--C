#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(){
    int pid=fork();
    if(pid==0){
        printf("\nchild process id\t%d",getpid());
        printf("\nParent process id\t%d",getppid());

        sleep(5);//sleep the program to make sure parent is terminated

        printf("\nafter termination of parent\n");
        printf("\nchild process id\t%d",getpid());
        printf("\nParent process id\t%d",getppid());
        return 0;
    }
}
