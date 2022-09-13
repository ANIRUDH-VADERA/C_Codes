#include <stdio.h>
#include <stdlib.h>

int *getUniqueReg(int *arr, int *n)
{
    for (int i = 0; i < *n; i++)
    {
        for (int j = i + 1; j < *n; j++)
        {
            if (arr[i] == arr[j])
            {
                for (int k = j; k < (*n - 1); k++)
                {
                    arr[k] = arr[k + 1];
                }
                j--;
                *n = *n - 1;
            }
        }
    }
    arr = realloc(arr, *n * sizeof(int));
    return arr;
}

int main()
{
    int n;
    printf("Enter the number of entries : \n");
    scanf("%d", &n);
    int *uniqueReg = (int *)malloc((n) * sizeof(int));
    printf("Enter the registeration numbers : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &uniqueReg[i]);
    }
    uniqueReg = getUniqueReg(uniqueReg, &n);
    printf("The uniqueReg entries are : \n");
    printf("[ ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", uniqueReg[i]);
    }
    printf("]\n");
    free(uniqueReg);
    return 0;
}