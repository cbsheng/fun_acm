#include <stdio.h>
#include <math.h>

int main()
{
    int     m;
    int     i, j;
    double    result = 1.0; 
    double  k;
    scanf("%d", &m);
        while (m--)
        {
            scanf("%d", &j);
            result = 1.0;
            for (k = 2.0; (int)k <= j; k+=1.0)
            {
                if ((int)k % 2 == 0)
                {
                    result -= 1.0/k;    
                }
                else
                {
                    result += 1.0/k;
                }
            }
            printf("%.2f\n", result);
        }
    return    0;
}