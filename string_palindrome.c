#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
    char arr1[50],arr2[50];
    int n,i,f=0;
    scanf("%s",&arr1);
    n=strlen(arr1);
    for(i=n-1;i>=0;i--)
    {
        arr2[n-i-1]=arr1[i];
    }
    for(i=0;i<n;i++)
    {
        if(arr1[i]!=arr2[i])
        {
            f=1;
        }
    }
    printf("%s",arr1);
    printf("%s",arr2);
    if(f==1)
    {
        printf("not");
    }
    else
    {
        printf("palindrome");
    }
    return 0;



}