#include<stdio.h>
#include<conio.h>
int main()
{
    int arr[50][50],i,j,n,a=0,b=0;
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
                printf("i=%d",i);
                printf("j=%d",j);
                a=a+arr[i][j];
            }


        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if((i+j)==n-1)
            {
                printf("i=%d",i);
                printf("j=%d",j);
                b=b+arr[i][j];
            }

        }
    }
    printf("a=%d\n",a);
    printf("b=%d\n",b);
    if(a>b)
    {
        printf("%d",a-b);

    }
    else if(b>a)
    {
        printf("%d",b-a);

    }
    else
    {
        printf("%d",a-b);
    }
    return 0;



}