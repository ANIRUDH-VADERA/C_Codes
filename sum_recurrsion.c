#include<stdio.h>

int addnumber(int n)
{
    if (n!=0)
    {
        return n+addnumber(n-1);
    }
    else
    {
        return n;
    }
        
}
int main()
{
    int n,s;
    printf("Enter the number:");
    scanf("%d",&n);
    s=addnumber(n);
    printf("sum of numbers is:%d",s);
    return 0;
}


