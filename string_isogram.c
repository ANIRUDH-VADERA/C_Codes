#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
    char arr[50];
    int n,i,j,f=0;
    scanf("%s",&arr);
    n=strlen(arr);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i!=j)
            {
                if(arr[i]==arr[j])
                {
                    f=1;
                }
            }
                
        }
    }
    if(f==1)
    {
        printf("not isogram");

    }
    else
    {
        printf("isogram");
    }
}