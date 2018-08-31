//My first work of C.
#include <stdio.h>
#include <ctype.h>
char get_choice(void);
char get_first(void);
void add(void);
void subtract(void);
void multiply(void);
void divide(void);
float get_number1(void);
float get_number2(void);
int main(void)
{
    char choice;
    while ((choice = get_choice()) != 'q')
    {
        switch (choice)
        {
        case 'a':
            add();
            break;
        case 'b':
            subtract();
            break;
        case 'c':
            multiply();
            break;
        case 'd':
            divide();
            break;
        case 'p':
            break;
        default:
            printf("Program error!\n");
            break;
        }
    }
    printf("Bye.\n");
    return 0;
}
char get_choice(void)
{
    char ch;
    printf("Enter the letter of your choice.\n");
    printf("a. add             b. subtract\n");
    printf("c. multiply        d. divide\nq. quit\n");
    ch = get_first();
    while ((ch < 'a' || ch > 'd') && ch != 'q')
    {
        printf("Please response with an a, b, c, d, or q.\n");
        ch = get_first();
    }
    return ch;
}
char get_first(void)
{
    char ch;
    while (isspace(ch = getchar()))
        continue;
    while (getchar() != '\n')
        continue;
    return ch;
}
float get_number1(void)
{
    char ch;
    float x;
    printf("Please enter the first number: ");
    while (scanf("%f", &x) != 1)
    {
        while ((ch = getchar()) != '\n')
            putchar(ch);
        printf(" is not a number.\n");
        printf("Please enter a number, such as 2.5, -1.78E8, or 3: \n");
    }
    return x;
}
float get_number2(void)
{
    char ch;
    float y;
    printf("Please enter the second number: ");
    while (scanf("%f", &y) != 1)
    {
        while ((ch = getchar()) != '\n')
            putchar(ch);
        printf(" is not a number.\n");
        printf("Please enter a number, such as 2.5, -1.78E8, or 3: \n");
    }
    return y;
}
void add(void)
{
    float x, y;
    x = get_number1();
    y = get_number2();
    printf("%g + %g = %g\n", x, y, x + y);
}
void subtract(void)
{
    float x, y;
    x = get_number1();
    y = get_number2();
    printf("%g - %g = %g\n", x, y, x - y);
}
void multiply(void)
{
    float x, y;
    x = get_number1();
    y = get_number2();
    printf("%g * %g = %g\n", x, y, x * y);
}
void divide(void)
{
    float x, y;
    char ch;
    x = get_number1();
    y = get_number2();
    while (y == 0)
    {
        printf("Please enter a number other than 0: ");
        while (scanf("%f", &y) != 1)
        {
            while ((ch = getchar()) != '\n')
                putchar(ch);
            printf(" is not a number.\n");
            printf("Please enter a number, such as 2.5, -1.78E8, or 3: ");
        }
    }
    printf("%g / %g = %g\n", x, y, x / y);
}
