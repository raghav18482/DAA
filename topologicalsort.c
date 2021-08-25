#include<stdio.h>
#include<stdlib.h>
int a[10][10], visited[10],n;
int t[10],h[10];
int tt=0;
void DFS(int source)
{
    int i;
    visited[source]=1;
    for(i=0;i<n;i++){
        if(a[source][i]>0&&visited[i]==0){
            printf("\n%d->%d", source+1, i+1);
            DFS(i); 
            t[tt]=i+1;
            tt++;
        }
    }
}
int main()
{
    int i,j, source;
  printf("Enter n\n");
  scanf("%d",&n);
    printf("\nEnter matrix\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
      scanf("%d",&a[i][j]);
        }

    for(i=0;i<n;i++){
        visited[i]=0;
        t[i]=0;
    }

    for(i=0;i<n;i++)
        if(visited[i]==0){
            DFS(i);
            t[tt]=i+1;
            tt++;
        }

    printf("\n");

    for(i=0;i<tt;i++)
        printf("%d",t[i]);

    printf("\n");

    for(int i=tt-1,j=0;i>=0;i--,j++)
    {
        h[j]=t[i];
    }

    for(i=0;i<tt;i++)
        printf("%d",h[i]);

    return 0;

}
