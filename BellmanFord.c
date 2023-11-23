#include <stdio.h>
#include<stdlib.h>
int n;
int check(int c[][n],int u){
  int Incoming_edge=0;
  for(int i=0;i<n;i++){
    if(i!=u && c[i][u]!=999){
      Incoming_edge=1;
      break;
    }
  }
  return Incoming_edge;
}
void Bellman_Ford(int c[][n],int v,int d[]){
  for(int i=0;i<n;i++){
    d[i]=c[v][i];
  }
  for(int k=1;k<n-1;k++){
    for(int u=0;u<n;u++){
        if(u!=v && check(c,u)==1){
          for(int i=0;i<n;i++){
            if(i!=u && d[u]>d[i]+c[i][u]){
              d[u]=d[i]+c[i][u];
            }
          }
        }
    }
  }
}
int main(){
    int v;
  printf("n=");
  scanf("%d",&n);
  printf("v=");
  scanf("%d",&v);
  int cost[7][7],d[7];
  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        scanf("%d",&cost[i][j]);
  Bellman_Ford(cost,v-1,d);
  printf("shortest path from %d\n",v);
  for(int i=0;i<n;i++){
    printf("%d ",d[i]);
  }
}
