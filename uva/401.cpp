//url:http://uva.onlinejudge.org/external/4/401.pdf
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> table(91, -1);

void init()
{
    table[48] = 48; //0
    table[49] = 49; //1
    table[50] = 83; //2
    table[51] = 69; //3
    table[53] = 90; //5
    table[56] = 56; //8

    table[65] = 65; //A
    table[69] = 51; //E
    table[72] = 72; //H
    table[73] = 73; //I
    table[74] = 76; //L
    table[76] = 74; //J
    table[77] = 77; //M
    table[79] = 48; //O
    table[83] = 50; //S
    table[84] = 84; //T
    table[85] = 85; //U
    table[86] = 86; //V
    table[87] = 87; //W
    table[88] = 88; //X
    table[89] = 89; //Y
    table[90] = 53; //Z
}

int isP(string s)
{
    for (int i=0, j=s.size()-1; i<s.size()/2; ++i, --j)
    {
        if (s[i] != s[j])
            return 0;
    }
    return 1;
}

int isM(string s)
{
    for (int i=0; i<s.size(); ++i)
    {
        if (i<s.size()/2)
        {
            s[i] = table[s[i]];
        }
        else
        {
            if (s[i] == 'O')
                s[i] = table[s[i]];
        }
    }
    if (isP(s))
    {
        if (s.size()%2 == 0)
            return 1;
        else
        {
            if (table[s[s.size()/2]] != -1)
                return 1;
            else
                return 0;
        }
    }
    else
    {
        return 0; 
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    string s;
    init();
    while (cin >>s)
    {
        if (isP(s))
        {
            if (isM(s))
                cout << s << " -- is a mirrored palindrome.\n" << endl;
            else
                cout << s << " -- is a regular palindrome.\n" << endl;
        }
        else
        {
            if (isM(s))
                cout << s << " -- is a mirrored string.\n" << endl;
            else
                cout << s << " -- is not a palindrome.\n" << endl;
        }
    }
    fclose(stdin);
    return 0;
}
