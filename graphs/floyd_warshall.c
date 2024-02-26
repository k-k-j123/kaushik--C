#include<stdio.h>
int i,j,k,n,d[10][10],a[10][10];
int min(int a,int b){
    return (a<b)?a:b;
}
void path()
{
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
int main(){
    printf("\nenter the number of vertices\t");
    scanf("%d",&n);
    printf("\nenter adjacency matrix\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            d[i][j]=a[i][j];
        }
    
    path();
    printf("\nresultant matrix is\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
            printf("%d ",d[i][j]);
        printf("\n");
    }
}