#include<stdio.h>
#include<stdlib.h>
int n,x[100];
int place(int k,int i)
{
    for(int j=1;j<k;j++)
    {
        if((x[j]==i)||(abs(k-j)==abs(i-x[j])))
            return 0;
    }
    return 1;
}
void nqueen(int k)
{
    for(int i=1;i<=n;i++)
    {
        if(place(k,i))
        {
            x[k]=i;
            if(k==n)
            {
                for(int j=1;j<=n;j++)
                    printf("%d ",x[j]);
                printf("\n");
            }
            else nqueen(k+1);
        }
    }
}
int main()
{
    printf("N= ");
    scanf("%d",&n);
    printf("%d Queens problem solutions are\n",n);
    nqueen(1);
}
