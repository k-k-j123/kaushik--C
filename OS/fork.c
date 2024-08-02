#include<stdio.h>
#include<unistd.h>
int main()
{
	printf("\nbefore fork\n");
	fork();
	fork();
	printf("\nafter fork\n");
	return 0;

}
