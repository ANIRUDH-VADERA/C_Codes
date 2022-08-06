#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int n;
    int flag = 0;
    int flag1 = 0;
    scanf("%d", &n);
    // Complete the code to print the pattern.
    int f = 2 * n - 1;
    int x = n;
    int min_value = 0;
    int max_value = 0;
    int temp_arr[10000];
    int temp_idx = 0;
    for (int i = 0; i < n; i++)
    {
        min_value = n - i;
        x = n;
        for (int j = 0; j < n; j++)
        {
            if (x > min_value)
            {
                temp_arr[temp_idx++] = x;
                x = x - 1;
            }
            else
            {
                temp_arr[temp_idx++] = min_value;
            }
        }
        for (int j = 0; j < n; j++)
        {
            printf("%d ", temp_arr[j]);
        }
        for (int j = n - 2; j >= 0; j--)
        {
            printf("%d ", temp_arr[j]);
        }
        printf("\n");
        temp_idx = 0;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        min_value = n - i;
        x = n;
        for (int j = 0; j < n; j++)
        {
            if (x > min_value)
            {
                temp_arr[temp_idx++] = x;
                x = x - 1;
            }
            else
            {
                temp_arr[temp_idx++] = min_value;
            }
        }
        for (int j = 0; j < n; j++)
        {
            printf("%d ", temp_arr[j]);
        }
        for (int j = n - 2; j >= 0; j--)
        {
            printf("%d ", temp_arr[j]);
        }
        printf("\n");
        temp_idx = 0;
    }
    return 0;
}

// 7 7 7 7 7 7 7 7 7 7 7 7 7
// 7 6 6 6 6 6 6 6 6 6 6 6 7
// 7 6 5 5 5 5 5 5 5 5 5 6 7
// 7 6 5 4 4 4 4 4 4 4 5 6 7
// 7 6 5 4 3 3 3 3 3 4 5 6 7
// 7 6 5 4 3 2 2 2 3 4 5 6 7
// 7 6 5 4 3 2 1 2 3 4 5 6 7
// 7 6 5 4 3 2 2 2 3 4 5 6 7
// 7 6 5 4 3 3 3 3 3 4 5 6 7
// 7 6 5 4 4 4 4 4 4 4 5 6 7
// 7 6 5 5 5 5 5 5 5 5 5 6 7
// 7 6 6 6 6 6 6 6 6 6 6 6 7
// 7 7 7 7 7 7 7 7 7 7 7 7 7