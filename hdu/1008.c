#include <stdio.h>

#define UP 6;
#define DOWN 4;
#define STAY 5;

int fun(int now, int nt)
{
    int    seconds;
    if (now == nt)
    {
        return 5;
    }
    if (nt > now)
    {
        seconds = (nt - now) * UP;
    }
    else
    {
        seconds = (now - nt) * DOWN;
    }
    return seconds + STAY;
}

int main()
{
    int    N;
    int    nt;
    int    seconds;
    scanf("%d", &N);
    while ( 0 != N )
    {
        int    total = 0;
        int    now = 0;
        while ( N-- )
        {
           scanf("%d", &nt); 
           seconds = fun(now, nt); 
           total += seconds;
           now = nt;
        } 
        printf("%d\n", total);
        scanf("%d", &N);
    }
    return 0;
}