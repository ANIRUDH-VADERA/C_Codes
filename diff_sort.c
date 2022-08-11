#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char *a, const char *b)
{
    if (strcmp(a, b) > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int lexicographic_sort_reverse(const char *a, const char *b)
{
    if (strcmp(a, b) > 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int sort_by_number_of_distinct_characters(const char *a, const char *b)
{
    int no_of_diff_1 = 0;
    int no_of_diff_2 = 0;
    int flag1 = 0;
    for (int i = 0; i < strlen(a) - 1; i++)
    {
        flag1 = 0;
        for (int j = i + 1; j < strlen(a); j++)
        {
            if (a[i] == a[j])
            {
                flag1 = 1;
            }
        }
        if (flag1 == 0)
        {
            no_of_diff_1++;
        }
    }
    no_of_diff_1++;
    flag1 = 0;
    for (int i = 0; i < strlen(b) - 1; i++)
    {
        flag1 = 0;
        for (int j = i + 1; j < strlen(b); j++)
        {
            if (b[i] == b[j])
            {
                flag1 = 1;
            }
        }
        if (flag1 == 0)
        {
            no_of_diff_2++;
        }
    }
    no_of_diff_2++;
    if (no_of_diff_1 > no_of_diff_2)
    {
        return 1;
    }
    else if (no_of_diff_1 < no_of_diff_2)
    {
        return 0;
    }
    else
    {
        if (strcmp(a, b) > 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int sort_by_length(const char *a, const char *b)
{
    if (strlen(a) > strlen(b))
    {
        return 1;
    }
    else if (strlen(b) > strlen(a))
    {
        return 0;
    }
    else
    {
        if (strcmp(a, b) > 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

void string_sort(char **arr, const int len, int (*cmp_func)(const char *a, const char *b))
{

    int min_idx = 0;
    char *temp;
    for (int i = 0; i < len - 1; i++)
    {
        min_idx = i;
        for (int j = i + 1; j < len; j++)
        {
            if (cmp_func(arr[min_idx], arr[j]))
            {
                min_idx = j;
            }
        }
        char *temp;
        if (min_idx != i)
        {
            temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
            // strcpy(temp, arr[min_idx]);
            // strcpy(arr[min_idx], arr[i]);
            // strcpy(arr[i], temp);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    char **arr;
    arr = (char **)malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++)
    {
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }

    string_sort(arr, n, lexicographic_sort);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");
}