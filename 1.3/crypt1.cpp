/*
ID: pkulinfa2
TASK: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;

int n, ans;
int a[20], p[5];
bool in[20];

ifstream fin("crypt1.in");
ofstream fout("crypt1.out");

bool check_digit(int num)
{
    while (num)
    {
        if (!in[num % 10])
            return false;
        num /= 10;
    }
    return true;
}

bool check()
{
    int a = p[0] * 100 + p[1] * 10 + p[2];
    int b = p[3] * 10 + p[4];
    if (a * b < 1000 || a * b > 9999 || !check_digit(a * b))
        return false;
    if (a * p[4] < 100 || a * p[4] > 999 || !check_digit(a * p[4]))
        return false;
    if (a * p[3] < 100 || a * p[3] > 999 || !check_digit(a * p[3]))
        return false;
    return true;
}

void dfs(int depth)
{
    if (depth == 5)
    {
        if (check())
            ans ++;
        return;
    }
    for (int i = 0; i < n; ++ i)
    {
        p[depth] = a[i];
        dfs(depth + 1);
    }
}

int main()
{


    fin >> n;
    for (int i = 0; i < 10; ++ i)
        in[i] = false;
    for (int i = 0; i < n; ++ i)
    {
        fin >> a[i];
        in[a[i]] = true;
    }

    ans = 0;
    dfs(0);
    fout << ans << endl;
    return 0;
}
