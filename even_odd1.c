#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct result
{
    int odd;
    int even;
};
int count_even_odd(struct result* res,int n,int i,int* p)
{
    int even=0,odd=0;
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
    res->even=even;
    res->odd=odd;
    return 0;

}
int main()
{
    int arr[50],n,i,*a,*ptr;
    struct result *pointer;
    pointer=(struct result*) calloc(2,2*sizeof(struct result));
    scanf("%d",&n);
    ptr=arr;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    count_even_odd(pointer,n,i,ptr);
    printf("even %d\n",pointer->even);
    printf("odd %d\n",pointer->odd);

    return 0;
}
