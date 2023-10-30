//program to write perfect number
//perfect number is a number which is equal to addition of its factors
#include<stdio.h>
int main()
{
	int num,res;
	printf("\nenter a number to check\n");
	scanf("%d",&num);
	
	for(int i=1;i<num;i++)
	{
		if(i%num==0)
		{
			res+=i;
		}
	}
	
	if(res==num)
	{
		printf("\nthe number is a perfect number");
	}
	else
	{
		printf("\nthe number is not a perfect number");
	}
	return 0;
}