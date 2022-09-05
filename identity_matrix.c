#include<stdio.h>
#include<conio.h>
int main()
{
    int arr[50][50],i,j,n,f,f1=1;
    printf("enter the order:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
            {
                if (arr[i][j]==1)
                {
                    f=1;

                }
                else
                {
                    f1=0;
                }
            }
            else
            {
                if(arr[i][j]==0)
                {
                    f=1;
                }
                else
                {
                    f1=0;
                }
            }
                
            


        }
    }
    if (f1==0)
    {
        printf("no");

    }
    else
    {
        printf("identity");
    }
    return 0;
}
    
    