#include<stdio.h>
int main()
{
	int num,orig,rem,res;
	printf("enter the number to check:\n");
	scanf("%d",&num);
	orig=num;
	while(num!=0)
	{
		rem=num%10;
		res+=rem*rem*rem;
		num/=10;
	}
	if(orig==res)
	{
		printf("the number %d is a armstrong number",orig);
	}
	else
	{
		printf("the number %d is not a armstrong number",orig);
	}
	return 0;
}