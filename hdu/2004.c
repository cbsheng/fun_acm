#include <stdio.h>
#include <math.h>

int main()
{
    int    input;
    while (scanf("%d", &input) != EOF)
    {
        if (input > 100 || input < 0)
        {
            printf("Score is error!\n");
        }
        else if (input >= 90 && input <= 100)
            printf("A\n");
        else if (input >= 80 && input < 90)
            printf("B\n");
        else if (input >= 70 && input < 80)
            printf("C\n");
        else if (input >= 60 && input < 70)
            printf("D\n");
        else if (input >= 0 && input < 60)
            printf("E\n");
    }
    return    0;
}