#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int    n, j, i, min;
    int    data[100];
    while (scanf("%d", &n) && n)
    {
        j = 0;
        min = 0;
        for (i = 0; i < n; i++)
        {
            scanf("%d", &data[i]);
            if (data[i] < data[min]) min = i; 
        }
        swap(data[0], data[min]);
        for (i = 0; i < n; i++) 
            printf(j++ ? " %d" : "%d", data[i]);
        printf("\n");
    }
    return    0;
}