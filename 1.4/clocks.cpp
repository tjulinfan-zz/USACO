/*
ID: pkulinf2
TASK: clocks
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

#pragma comment(linker,"/STACK:102400000,1024000")

int c[9];
vector<int> ans, tmp;
bool findans;
//change table
int ct[9][5] = {{0, 1, 3, 4, 9},
                {0, 1, 2, 9, 9},
                {1, 2, 4, 5, 9},
                {0, 3, 6, 9, 9},
                {1, 3, 4, 5, 7},
                {2, 5, 8, 9, 9},
                {3, 4, 6, 7, 9},
                {6, 7, 8, 9, 9},
                {4, 5, 7, 8, 9}};

bool operator < (const vector<int>& a, const vector<int>& b)
{
    if (a.size() < b.size())
        return true;
    if (a.size() > b.size())
        return false;
    for (int i = 0; i < a.size(); ++ i)
        if (a[i] < b[i])
            return true;
        else
            if (a[i] > b[i])
                return false;
    return false;
}

bool check()
{
    for (int i = 0; i < 9; ++ i)
        if (c[i] != 3)
            return false;
    return true;
}

void dfs(int depth)
{
    if (depth == 9)
    {
        if (check())
        {
            if (!findans || tmp < ans)
                ans = tmp;
        }
        return;
    }
    dfs(depth + 1);
    int bak[9];
    for (int i = 0; i < 9; ++ i)
        bak[i] = c[i];
    for (int i = 1; i < 4; ++ i)
    {
        tmp.push_back(depth);
        for (int j = 0; j < 5; ++ j)
            if (ct[depth][j] < 9)
                c[ct[depth][j]] = (c[ct[depth][j]] + 1) % 4;
        dfs(depth + 1);
    }
    for (int i = 1; i < 4; ++ i)
        tmp.pop_back();
    for (int i = 0; i < 9; ++ i)
        c[i] = bak[i];
}

int main()
{
    ifstream fin("clocks.in");
    ofstream fout("clocks.out");
    for (int i = 0; i < 9; ++ i)
    {
        fin >> c[i];
        c[i] = c[i] / 3 - 1;
    }

    findans = false;
    dfs(0);
    for (int i = 0; i < ans.size(); ++ i)
        fout << ans[i] + 1 << (i == ans.size() - 1 ? '\n' : ' ');
    return 0;
}
