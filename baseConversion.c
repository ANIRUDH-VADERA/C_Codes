#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int check(char num[])
{
    if (num[0] >= '0' && num[0] <= '9')
    {
        if (num[1] == 'x' || num[1] == 'X')
        {
            for (int i = 2; num[i] != '\0'; i++)
            {
                if (num[i + 1] == '\0' && num[i - 1] == 'U' && num[i] == 'L')
                {
                    return 1;
                }
                if (!(num[i] >= '0' && num[i] <= '9') && !(num[i] >= 'A' && num[i] <= 'F'))
                    return 0;
            }
            return 1;
        }
        else if ((num[1] >= '0' && num[1] <= '9') || num[1] == '\0')
        {
            for (int i = 1; num[i] != '\0'; i++)
            {
                if (num[i + 1] == '\0' && num[i - 1] == 'U' && num[i] == 'L')
                {
                    return 1;
                }
                if (!(num[i] >= '0' && num[i] <= '9'))
                    return 0;
            }
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}

int type(char input[])
{
    if (input[0] == '0')
    {
        if (input[1] == 'X' || input[1] == 'x')
        {
            return 3;
        }
        else
        {
            return 2;
        }
    }
    else
    {
        return 1;
    }
}

int convert_to_base3(int input)
{
    int x = 0;
    int f = 0;
    while (input > 0)
    {
        int r = input % 3;
        x = pow(10, f) * r + x;
        f++;
        input = input / 3;
    }
    return x;
}

int convert_to_base5(int input)
{
    int x = 0;
    int f = 0;
    while (input > 0)
    {
        int r = input % 5;
        x = pow(10, f) * r + x;
        f++;
        input = input / 5;
    }
    return x;
}

int convert_to_base7(int input)
{
    int x = 0;
    int f = 0;
    while (input > 0)
    {
        int r = input % 7;
        x = pow(10, f) * r + x;
        f++;
        input = input / 7;
    }
    return x;
}

int convert_to_base9(int input)
{
    int x = 0;
    int f = 0;
    while (input > 0)
    {
        int r = input % 9;
        x = pow(10, f) * r + x;
        f++;
        input = input / 9;
    }
    return x;
}

int add(int o1, int o2)
{
    int result = convert_to_base3(o1 + o2);
    return result;
}

int subtract(int o1, int o2)
{
    int result = convert_to_base3(o1 - o2);
    return result;
}

int multiply(int o1, int o2)
{
    int result = convert_to_base9(o1 + o2);
    return result;
}

int divide(int o1, int o2)
{
    int result = convert_to_base5(o1 / o2);
    return result;
}

int rem(int o1, int o2)
{
    int result = convert_to_base7(o1 % o2);
    return result;
}

int hex_to_dec(char hex[], int end)
{
    int decimal = 0;
    int base = 1;
    int length = end - 1;
    for (int i = length; i >= 0; i--)
    {
        if (hex[i] >= '0' && hex[i] <= '9')
        {
            decimal += (hex[i] - 48) * base;
            base *= 16;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F')
        {
            decimal += (hex[i] - 55) * base;
            base *= 16;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f')
        {
            decimal += (hex[i] - 87) * base;
            base *= 16;
        }
    }
    return decimal;
}

int oct_to_dec(int octalNumber)
{
    int decimalNumber = 0, i = 0;
    while (octalNumber != 0)
    {
        decimalNumber += (octalNumber % 10) * pow(8, i);
        ++i;
        octalNumber /= 10;
    }
    i = 1;
    return decimalNumber;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int x = 0; x < n; x++)
    {
        char input[50];
        scanf("%s", &input);
        char op;
        int breaking_index = 0;
        int last = -1;
        for (int i = 0; input[i] != '\0'; i++)
        {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '%' || input[i] == '/')
            {
                op = input[i];
                breaking_index = i;
            }
            last = i;
        }
        char operand1[25];
        char operand2[25];
        int idx1 = 0;
        int idx2 = 0;
        for (int j = 0; j < breaking_index; j++)
        {
            if (input[j] != '(' && input[j] != ')' && input[j] != 'L' && input[j] != 'U')
            {
                operand1[idx1++] = input[j];
            }
        }
        for (int j = breaking_index + 1; j < last; j++)
        {
            if (input[j] != '(' && input[j] != ')' && input[j] != 'L' && input[j] != 'U')
            {
                operand2[idx2++] = input[j];
            }
        }
        operand1[idx1++] = '\0';
        operand2[idx2++] = '\0';
        int res1 = check(operand1);
        int res2 = check(operand2);
        int type1 = 0;
        int type2 = 0;
        int o1;
        int o2;
        if (res1 == 0 && res2 == 0)
        {
            printf("(error)%c(error)", op);
        }
        else if (res1 == 0)
        {
            type2 = type(operand2);
            if (type2 == 1)
            {
                o2 = atoi(operand2);
            }
            else if (type2 == 2)
            {
                int end = idx2;
                idx2 = 0;
                for (int j = 0; j < end; j++)
                {
                    operand2[idx2++] = operand2[j + 1];
                }
                o2 = oct_to_dec(atoi(operand2));
            }
            else
            {
                idx2 = 0;
                for (int j = 0; operand2[j + 2] != '\0'; j++)
                {
                    operand2[idx2++] = operand2[j + 2];
                }
                o2 = hex_to_dec(operand2, idx2);
            }
            printf("(error)%c(%d)", op, o2);
        }
        else if (res2 == 0)
        {
            type1 = type(operand1);
            if (type1 == 1)
            {
                o1 = atoi(operand1);
            }
            else if (type1 == 2)
            {
                int end = idx1;
                idx1 = 0;
                for (int j = 0; j < end; j++)
                {
                    operand1[idx1++] = operand1[j + 1];
                }
                o1 = oct_to_dec(atoi(operand1));
            }
            else
            {
                idx1 = 0;
                for (int j = 0; operand1[j + 2] != '\0'; j++)
                {
                    operand1[idx1++] = operand1[j + 2];
                }
                o1 = hex_to_dec(operand1, idx1);
            }
            printf("(%d)%c(error)", o1, op);
        }
        else
        {
            type1 = type(operand1);
            type2 = type(operand2);
            if (type1 == 1)
            {
                o1 = atoi(operand1);
            }
            else if (type1 == 2)
            {
                int end = idx1;
                idx1 = 0;
                for (int j = 0; j < end; j++)
                {
                    operand1[idx1++] = operand1[j + 1];
                }
                o1 = oct_to_dec(atoi(operand1));
            }
            else
            {
                idx1 = 0;
                for (int j = 0; j < operand1[j + 2] != '\0'; j++)
                {
                    operand1[idx1++] = operand1[j + 2];
                }
                o1 = hex_to_dec(operand1, idx1);
            }
            if (type2 == 1)
            {
                o2 = atoi(operand2);
            }
            else if (type2 == 2)
            {
                int end = idx2;
                idx2 = 0;
                for (int j = 0; j < end; j++)
                {
                    operand2[idx2++] = operand2[j + 1];
                }
                o2 = oct_to_dec(atoi(operand2));
            }
            else
            {
                idx2 = 0;
                for (int j = 0; j < operand2[j + 2] != '\0'; j++)
                {
                    operand2[idx2++] = operand2[j + 2];
                }
                o2 = hex_to_dec(operand2, idx2);
            }
            int result;
            if (op == '+')
            {
                result = add(o1, o2);
            }
            else if (op == '-')
            {
                result = subtract(o1, o2);
            }
            else if (op == '*')
            {
                result = multiply(o1, o2);
            }
            else if (op == '/')
            {
                result = divide(o1, o2);
            }
            else if (op == '%')
            {
                result = rem(o1, o2);
            }
            printf("%d", result);
        }
    }
    return 0;
}