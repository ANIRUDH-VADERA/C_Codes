#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *str1;
    char *str2;
    str1 = (char *)calloc(10, sizeof(char));
    str2 = (char *)calloc(10, sizeof(char));
    printf("Enter String 1");
    scanf("%s", str1);
    printf("Enter String 2");
    scanf("%s", str2);
    str1 = realloc(str1, sizeof(char) * strlen(str1));
    str2 = realloc(str2, sizeof(char) * strlen(str2));
    printf("%s", str1);
    printf("%s", str2);
    return 0;
}