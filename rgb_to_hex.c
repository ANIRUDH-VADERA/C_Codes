#include <stdio.h>

char MainHex[7];
int idx;

char dec_Hexa(int n)
{
    char hexaDeciNum[100];
    int i = 0;
    while (n != 0)
    {
        int temp = 0;
        temp = n % 16;
        if (temp < 10)
        {
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else
        {
            hexaDeciNum[i] = temp + 55;
            i++;
        }
        n = n / 16;
    }
    // storing hexadecimal number array in reverse order
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%c", hexaDeciNum[j]);
    }
    if (i == 0)
    {
        printf("00");
    }
}

int main()
{
    int red, green, blue;
    idx = 0;

    printf("Please enter the value for Red: ");
    scanf("%d", &red);
    printf("Please enter the value for green: ");
    scanf("%d", &green);
    printf("Please enter the value for blue: ");
    scanf("%d", &blue);
    printf("#");
    dec_Hexa(red);
    dec_Hexa(green);
    dec_Hexa(blue);
    return 0;
}