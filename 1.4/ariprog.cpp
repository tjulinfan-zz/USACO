/*
ID: pkulinf2
TASK: ariprog
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;

int n, m;
vector<int> s;
vector<pair<int, int> > ans;
bool appear[130000];

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.second < b.second || a.second == b.second && a.first < b.first;
}

bool judge(int a0, int d)
{
    for (int i = 0; i < n; ++ i)
    {
        if (!appear[a0])
            return false;
        a0 += d;
    }
    return true;
}

int main()
{
    ifstream fin("ariprog.in");
    ofstream fout("ariprog.out");

    fin >> n >> m;

    for (int p = 0; p <= m; ++ p)
        for (int q = 0; q <= m; ++ q)
            s.push_back(p * p + q * q);
    sort(s.begin(), s.end());
    vector<int>::iterator it = unique(s.begin(), s.end());
    s.erase(it, s.end());

    for (int i = 0; i < s.size(); ++ i)
        appear[s[i]] = true;

    for (int i = 0; i < s.size(); ++ i)
    {
        int a0 = s[i];
        for (int j = i + 1; j < s.size(); ++ j)
        {
            int d = s[j] - s[i];
            if (a0 + d * (n - 1) > s.back())
                break;
            if (judge(a0, d))
                ans.push_back(make_pair(a0, d));
        }
    }

    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < ans.size(); ++ i)
        fout << ans[i].first << " " << ans[i].second << endl;
    if (ans.size() == 0)
        fout << "NONE" << endl;
    return 0;
}
