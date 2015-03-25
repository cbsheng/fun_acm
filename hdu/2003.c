#include <stdio.h>
#include <math.h>

int main()
{
    double    input;
    while (scanf("%lf", &input) != EOF)
    {
        printf("%0.2f\n", fabs(input));
    }
    return    0;
}