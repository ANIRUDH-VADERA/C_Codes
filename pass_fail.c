#include<stdio.h>
#include<string.h>
int main()
{
    float n;
    int per;
    char s[4];
    scanf("%f",&n);
    scanf("%d",&per);
    scanf("%s",&s);
    printf("%s\n",s);
    if((n>0) && (per>0) && (per<100) && ((s!="yes") || (s!="no")))
    {
        if(!((strcmp(s,"yes"))))
        {
            printf("pass\n");
            if(per>90)
            {
                n=n-((30/100.0)*n);
            }
            else if(per>85)
            {
                n=n-((10/100.0)*n);
            }
        }
        else
        {
            printf("fail\n");
            if(per>90)
            {
                n=n-((20/100.0)*n);
            }

        }
        printf("%.1f",n);
    }
    else
    {
        printf("Invalid input");
    }
        
    return 0;
}