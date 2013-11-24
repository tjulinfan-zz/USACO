/*
ID: pkulinf2
LANG: C++
TASK: barn1
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

const int MAXN = 202;
const int MAXM = 52;
int f[MAXN][MAXM];
bool oc[MAXN];

int min(int a, int b)
{
    if (a == -1) return b;
    return a < b ? a : b;
}

int main()
{
    ifstream fin("barn1.in");
    ofstream fout("barn1.out");
    int m, s, c;
    fin >> m >> s >> c;
    for (int i = 0; i <= s; ++ i)
        oc[i] = false;
    for (int i = 0; i < c; ++ i)
    {
        int oc_stall_num;
        fin >> oc_stall_num;
        oc[oc_stall_num] = true;
    }
    for (int i = 0; i <= s; ++ i)
        for (int j = 0; j <= m; ++ j)
            f[i][j] = -1;
    for (int i = 0; i <= m; ++ i)
        f[0][i] = 0;
    for (int i = 1; i <= s; ++ i)
    {
        if (!oc[i])
        {
            for (int j = 0; j <= m; ++ j)
                f[i][j] = f[i - 1][j];
        }
        else
        {
            for (int j = 1; j <= m; ++ j)
                for (int k = 0; k < i; ++ k)
                    if (f[k][j - 1] != -1)
                        f[i][j] = min(f[i][j], f[k][j - 1] + i - k);
        }
    }
    fout << f[s][m] << endl;
    return 0;
}
