#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Details
{
    char name[50];
    int age;
    int reg_no;
    char gender;
    char department[50];
    char school[50];
    char state[50];
    char country[50];
};

void swap(struct Details *xp, struct Details *yp)
{
    struct Details temp = *xp;
    *xp = *yp;
    *yp = temp;
}

struct Details *sort(struct Details arr[], int n)
{
    int min_idx;
    for (int i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(arr[j].department, arr[min_idx].department) < 0)
            {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
    return arr;
}

int main()
{
    int n;
    printf("enter number of records\n");
    scanf("%d", &n);
    printf("Enter details of 10 students\n");
    struct Details array[10];
    for (int i = 0; i < n; i++)
    {
        printf("Student %d\n", (i + 1));
        printf("name\n");
        scanf("%s", &array[i].name);
        printf("age\n");
        scanf("%d", &array[i].age);
        printf("regno\n");
        scanf("%d", &array[i].reg_no);
        // printf("gender\n");
        // scanf("%c", &array[i].gender);
        printf("department\n");
        scanf("%s", &array[i].department);
        // printf("school\n");
        // scanf("%s", &array[i].school);
        // printf("state\n");
        // scanf("%s", &array[i].state);
        // printf("country\n");
        // scanf("%s", &array[i].country);
    }
    struct Details *pt = sort(array, n);
    printf("After Sorting : ");
    for (int i = 0; i < n; i++)
    {
        printf("name : ");
        printf("%s", pt[i].name);
        printf("\n");
        printf("age : ");
        printf("%d", pt[i].age);
        printf("\n");
        printf("regno : ");
        printf("%d", pt[i].reg_no);
        printf("\n");
        // printf("gender");
        // printf("%c", pt[i].gender);
        printf("department : ");
        printf("%s", pt[i].department);
        printf("\n");
        // printf("school");
        // printf("%s", pt[i].school);
        // printf("state");
        // printf("%s", pt[i].state);
        // printf("country");
        // printf("%s", pt[i].country);
    }
    return 0;
}