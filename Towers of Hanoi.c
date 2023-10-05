#include<stdio.h>                                                  
void toh(char a,char b,char c,int n)                      
{                                                                                      
    if(n>=1)                                                                          
    {                                                                                   
        toh(a,c,b,n-1);                                                                  
        printf("Move disl from %c to %c\n",a,b);                                          
        toh(c,b,a,n-1);                                                        
        }                                                                
        }                                                                          
int main()                                                                  
{
    int n;                                                             
    printf("Enter no.of Disks : ");                                       
    scanf("%d",&n);                                                     
    toh('P','Q','R',n);                                               
    }

