#include<stdio.h>
#include<conio.h>
int main()
{
    int arr[50],i,n,s=0,*p,j;
    printf("Enter the number of elements");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);

    }
    p=arr;
    for(j=0;j<n;j++)
    {
        s=s+*p;
        p++;
    }
    printf("%d",s);
    return 0;
    
}