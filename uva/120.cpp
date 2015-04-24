//Url:http://uva.onlinejudge.org/external/1/120.pdf

#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;

void swap(int *beg, int *end)
{
    int  tmp;
    for (; beg < end; ++beg, --end)
    {
        tmp = *beg;
        *beg = *end;
        *end = tmp;
    }
}

void turn(int *st, char *input, int *len)
{
    int  num = 0;
    char  *p=strtok(input, " ");
    while (p)
    {
        st[num++] = atoi(p);
        p = strtok(NULL, " ");
    }
    *len = num;
}

int cmp(const void *e1, const void *e2)
{
    return *(int*)e2 - *(int*)e1;
}

int get_index(int v, int *st, int len)
{
    for (int i=0; i<len; ++i)
        if (st[i] == v)
            return i;
    return -1;
}

char input[300];
int  st[31];
int  sst[31];

int main()
{
    //freopen("testdata/120.in", "r", stdin);
    string s;
    int len;
    while (fgets(input, sizeof(input), stdin) != NULL)
    {
        input[strlen(input)-1] = '\0';
        if (input[0] == '\0') break;
        turn(st, input, &len);
        for (int i=0; i<len; ++i)
            printf("%d ", st[i]);
        printf("\n");
        memcpy(sst, st, len*sizeof(int));
        qsort(sst, len, sizeof(int), cmp);

        int index;
        for (int i=0; i<len; ++i)
        {
            index = get_index(sst[i], st, len);
            if (index == -1)
            {
                puts("index error");
                return 0;
            }
            if (index == len-1-i) continue;
            else
            {
                if (index == 0)
                {
                    swap(st+0, st+(len-1-i));
                    printf("%d ", i+1);
                }
                else
                {
                    swap(st+0, st+index);
                    swap(st+0, st+(len-1-i));
                    printf("%d %d ", len-index, i+1);
                }
            }
        }
        printf("0\n");

    }
    return 0;
}
