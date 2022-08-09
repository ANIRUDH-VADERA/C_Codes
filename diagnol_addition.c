#include<stdio.h>
int main()
{
    int arr[50][50],i,j,n1,a=0,b=0,n2;
    scanf("%d",&n1);
    scanf("%d",&n2);
    if(n1==n2 && n1>0 && n2>0)
    {
        for(i=0;i<n1;i++)
        {
            for(j=0;j<n2;j++)
            {
                scanf("%d",&arr[i][j]);
            }
        }
        for(i=0;i<n1;i++)
        {
            for(j=0;j<n2;j++)
            {
                if(i==j)
                {
                    a=a+arr[i][j];
                }


            }
        }
        for(i=0;i<n1;i++)
        {
            for(j=0;j<n2;j++)
            {
                if((i+j)==n1-1)
                {
                    b=b+arr[i][j];
                }

            }
        }
        printf("%d",a+b);
    }
    else
    {
        printf("Invalid input");
    }
    
    return 0;



}