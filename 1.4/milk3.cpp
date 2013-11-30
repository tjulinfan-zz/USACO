/*
ID: pkulinf2
TASK: milk3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<long long, bool> used;
int CA, CB, CC;
vector<int> ans;

long long encode(int A, int B, int C)
{
    long long ret = 0;
    ret = ret * (CC + 1) + A;
    ret = ret * (CC + 1) + B;
    ret = ret * (CC + 1) + C;
    return ret;
}

void dfs(int A, int B, int C)
{
    if (A == 0)
        ans.push_back(C);
    long long s = encode(A, B, C);
    if (used[s])
        return;
    used[s] = true;

    int TA, TB, TC;
    //A -> B
    TA = A - min(CB - B, A);
    TB = B + min(CB - B, A);
    dfs(TA, TB, C);
    //A -> C
    TA = A - min(CC - C, A);
    TC = C + min(CC - C, A);
    dfs(TA, B, TC);
    //B -> A
    TB = B - min(CA - A, B);
    TA = A + min(CA - A, B);
    dfs(TA, TB, C);
    //B -> C
    TB = B - min(CC - C, B);
    TC = C + min(CC - C, B);
    dfs(A, TB, TC);
    //C -> A
    TC = C - min(CA - A, C);
    TA = A + min(CA - A, C);
    dfs(TA, B, TC);
    //C -> B
    TC = C - min(CB - B, C);
    TB = B + min(CB - B, C);
    dfs(A, TB, TC);
}

int main()
{
    ifstream fin("milk3.in");
    ofstream fout("milk3.out");
    fin >> CA >> CB >> CC;

    dfs(0, 0, CC);

    sort(ans.begin(), ans.end());
    vector<int>::iterator it = unique(ans.begin(), ans.end());
    ans.erase(it, ans.end());

    for(int i = 0 ; i < ans.size(); ++ i)
        fout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
    return 0;
}
