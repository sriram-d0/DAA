#include<stdio.h>
#include<stdlib.h>
void merge(int a[],int l,int mid,int h)
{
        int i,j,k;
        i=l;
        j=mid+1;
        k=l;
        int b[20];
        while(i<=mid && j<=h)
        {
                if(a[i]<=a[j])
                {
                        b[k]=a[i];
                        i++;
                        k++;
                }
                else
                {
                 b[k]=a[j];
                        j++;
                        k++;
                }
        }
        while(i<=mid)
        {
                b[k]=a[i];
                i++;
                k++;
        }
        while(j<=h)
        {
                b[k]=a[j];
                j++;
                k++;
        }
        for(k=l;k<=h;k++)
        {
        a[k]=b[k];
        }
}
void mergesort(int a[],int l,int h)
{
        if(l<h)
        {
                int mid;
                mid=(l+h)/2;
                mergesort(a,l,mid);
                mergesort(a,mid+1,h);
                merge(a,l,mid,h);
        }
}
int  main()
{
        int a[20],i,j,n,l;
        printf("Enter range ");
        scanf("%d",&n);
         for(i=0;i<n;i++)
        {
                printf("Enter %d element ",i+1);
                scanf("%d",&a[i]);
        }
        printf("Before Sorting\n");
        for(i=0;i<n;i++)
        {
                printf("a[%d] : %d\n",i,a[i]);
        }
        mergesort(a,0,n-1);
        printf("After Sorting\n");
        for(i=0;i<n;i++)
        {
                printf("a[%d] : %d\n",i,a[i]);
        }
}
