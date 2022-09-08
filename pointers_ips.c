#include<stdio.h>
#include<conio.h>
int main()
{
    int arr[50],arr1[50],sum=0,sum1=0,*p,*p1,n,n1,a,b,c,d;
    scanf("%d",&n);
    scanf("%d",&n1);
    p=arr;
    p1=arr1;
    for(a=0;a<n;a++)
    {
        scanf("%d",&arr[a]);
    }
    for(b=0;b<n1;b++)
    {
        scanf("%d",&arr1[b]);
    }
    for(c=0;c<n;c++)
    {
        sum+=*(p+c);
    }
    for(d=0;d<n1;d++)
    {
        sum1+=*(p1+d);
    }
    

    printf("%d\n",sum);
    printf("%d",sum1);
    return 0;

}