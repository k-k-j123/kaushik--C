//without parameter and with return type
#include<stdio.h>
int max ();
int main()
{
  int big;
  big=max();
  printf("\ngreatest is %d",big);

}
int max()
{
    int a,b;
     printf("\n enter two nos\n");
     scanf("%d%d",&a,&b);
    if(a>b)
    {  return a;
    }
    else
    {  return b;
    }
}