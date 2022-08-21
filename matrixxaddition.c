#include<stdio.h>
#include<conio.h>
int main()
{
    int arr1[50][50],arr2[50][50],i,j,m,n,arr3[50][50];
    printf("enter value of m");
    scanf("%d",&m);
    printf("enter value of n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&arr1[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&arr2[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            arr3[i][j]=arr1[i][j]+arr2[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d\t",arr3[i][j]);
        }
        printf("\n");
    }

}