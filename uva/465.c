//Url : http://uva.onlinejudge.org/external/4/465.pdf

#include <stdio.h>

long int_max = 4294967296;

int main()
{
    freopen("testdata/465.in", "r", stdin);
    char f[1000], s[1000], o;
    double df, ds;
    while (scanf("%s %c %s", f, &o, s) != EOF)
    {
        sscanf(f, "%lf", &df);
        sscanf(s, "%lf", &ds);
        printf("%s %c %s\n", f, o, s);
        if (df > int_max)
            printf("first number too big\n");
        if (ds > int_max)
            printf("second number too big\n");
        if (o == '+' && df + ds > int_max)
            printf("result too big\n");
        if (o == '*' && df * ds > int_max)
            printf("result too big\n");

    }
    fclose(stdin);
    return 0;
}
