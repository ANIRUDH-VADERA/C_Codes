#include<conio.h>
#include<stdio.h>
int* count_even_odd(int arr1[],int n,int i,int* p)
{
    int even=0,odd=0;
    int *ptr2;
    ptr2=arr1;
    for(i=0;i<n;i++)
    {
        if (*(p+i)%2==0)
        {
            even=even+1;
        }
        else
        {
            odd+=1;

        }
    }
    arr1[0]=even;
    arr1[1]=odd;
    return ptr2;

}
int main()
{
    int arr[50],n,i,*a,*ptr,arr1[2];
    scanf("%d",&n);
    ptr=arr;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    a=count_even_odd(arr1,n,i,ptr);
    printf("even %d\n",*a);
    printf("odd %d\n",*(a+1));

    return 0;
}