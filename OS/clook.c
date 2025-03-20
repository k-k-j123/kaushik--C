#include <stdio.h>
#include <stdlib.h>
int main()
{

	int n;
	int disk_size;
	int choice;
	printf("\nenter disk size\t");
	scanf("%d", &disk_size);
	printf("\nenter the number of request\t");
	scanf("%d", &n);
	printf("\nenter the request\n");
	int request[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &request[i]);
	}
	int head;
	printf("\nenter the head position\t");
	scanf("%d", &head);
	printf("\nenter the direction\n0.left\n1.right\n");
	scanf("%d", &choice);
	int seek = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n - i - 1; j++)
		{
			if (request[i] > request[j])
			{
				int temp = request[i];
				request[i] = request[j];
				request[j] = temp;
			}
		}
	}
    if(choice==0){
        seek+=abs(head-request[0]);
        seek+=abs(request[n-1]-request[0]);
        int toservice = 0, i = 0;
		while (request[i] <= head)
		{
			i++;
		}
        seek+=abs(request[n-1]-request[i]);
    }else{
        seek+=abs(head-request[n-1]);
        seek+=abs(request[n-1]-request[0]);
        int toservice = 0, i = 0;
		while (request[i] < head)
		{
			i++;
		}
        i--;
        seek+=abs(request[i]-request[0]);
    }
    printf("\nseek time is %d\n",seek);
    return 0;
}   