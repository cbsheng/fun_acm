#include <stdio.h>
#include <math.h>

#define   PI 3.1415927

int main()
{
    double     r;
    double     result;
    while (scanf("%lf", &r) != EOF)
    {
        result = 4.0 / 3.0  * PI * pow(r, 3);
        printf("%.3f\n", result);
    }
    return    0;
}