#include<stdio.h>
#include<string.h>
int main()
{
    char s[20],news[20];
    scanf("%c\n",&s);
    int k=0,sum=0;
    for(int k=0;k<strlen(s);k++)
    {
        int c=0;
        for(int i=k;i<strlen(s);i++)
        {
            for(int j=0;j<(strlen(s)-k);j++)
            {
                strcpy(&news[j],&s[i]);
            }
        }
        for(int m=0;m<strlen(news);m++)
        {
            if(s[m]==news[m])
            {
                c++;
            }
        }
        sum=sum+c;
    }
    printf("%d\n",sum);
    return 0;

}