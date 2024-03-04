#include<stdio.h>
#include<stdlib.h>
int i,j,k,a,b,u,v,n,ne=1;
int min,mincost=0,cost[10][10],parent[10];
int find(int i){
    while(parent[i])
        i=parent[i];
    return i;
}
int uni(int i,int j)
{
    if(i!=j)
    {
        parent[j]=i;
        return 1;
    }    
    return 0;
}
int main()
{
    printf("\nimplementation of kruskals algorithm\n");
    printf("\nenter the number of nodes\n");
    scanf("%d",&n);
    printf("\nenter the cost matrix\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    printf("\nthe edges of minimum spanning tree\n");
    while(ne<n)
    {//find minimum cost from each row of cost matrix
        for(i=1,min=99;i<=n;i++)
            for(j=1;j<=n;j++)
                if(cost[i][j]<min)
                {
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
        
        u=find(u);
        v=find(v);
        if(uni(u,v)){
            printf("%d edge (%d %d)=%d\n",ne++,a,b,min);
            mincost+=min;
        }
        cost[a][b]=cost[b][a]=99;
    }
    printf("\nminimum cost:%d\n",mincost);
}
