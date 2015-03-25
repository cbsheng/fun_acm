#include <stdio.h >

int main ()
{
        long    ah, am, as, bh, bm, bs;
        int     n;
        scanf("%d%*c", &n);
        while (n--)
        {
            ah = bh = am = bm = as = bs = 0;
            scanf("%ld%ld%ld%ld%ld%ld", &ah, &am, &as, &bh, &bm, &bs);
            am += bm, as += bs, ah += bh;
                am += as / 60;
                as = (as % 60);
                ah += am / 60;
                am = (am % 60);
            printf("%ld %ld %ld\n", ah, am, as);
        }
        return    0;
}