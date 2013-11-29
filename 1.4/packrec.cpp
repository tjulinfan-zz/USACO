/*
ID: pkulinf2
TASK: packrec
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

const int INF = 1000000;

typedef struct _Rec
{
    int l, w;

    bool operator == (const struct _Rec& rhf)
    {
        return rhf.l == l && rhf.w == w;
    }
} Rec;

bool cmp(const Rec& a, const Rec& b)
{
    return a.l < b.l;
}

Rec recs[4], a[4];
int ans;
vector<Rec> ansRecs;
bool used[5];

void update(int l, int w)
{
    if (l > w)
        swap(l, w);
    if (l * w == ans)
        ansRecs.push_back(Rec {l, w});
    if (l * w < ans)
    {
        ans = l * w;
        ansRecs.clear();
        ansRecs.push_back(Rec {l, w});
    }
}

void area1()
{
    int l = 0, w = 0;
    for (int i = 0; i < 4; ++ i)
    {
        w += recs[i].w;
        l = max(l, recs[i].l);
    }
    update(l, w);
}

void area2()
{
    int l = 0, w = 0;
    for (int i = 0; i < 3; ++ i)
    {
        w += recs[i].w;
        l = max(l, recs[i].l);
    }
    w = max(w, recs[3].w);
    l += recs[3].l;
    update(l, w);
}

void area3()
{
    int l = max(max(recs[0].l, recs[1].l) + recs[3].l, recs[2].l);
    int w = max(recs[0].w + recs[1].w, recs[3].w) + recs[2].w;
    update(l, w);
}

void area4()
{
    int w = recs[0].w + max(recs[1].w, recs[2].w) + recs[3].w;
    int l = max(max(recs[0].l, recs[3].l), recs[1].l + recs[2].l);
    update(l, w);
}

void area5()
{
    int w = max(recs[0].w, recs[1].w) + recs[2].w + recs[3].w;
    int l = max(recs[0].l + recs[1].l, max(recs[2].l, recs[3].l));
    update(l, w);
}

void area6()
{
    int w = max(recs[0].w + recs[2].w, recs[1].w + recs[3].w);
    int l;
    if (recs[1].l > recs[3].l && recs[2].w > recs[3].w || recs[0].w > recs[1].w && recs[1].l < recs[3].l)
        l = max(recs[0].l, recs[2].l) + max(recs[1].l, recs[3].l);
    else
        l = max(recs[0].l + recs[1].l, recs[2].l + recs[3].l);
    update(l, w);
}

void dfs(int depth)
{
    if (depth == 4)
    {
        area1(); area2(); area3(); area4(); area5(); area6();
        return;
    }
    for (int i = 0; i < 4; ++ i)
        if (!used[i])
        {
            used[i] = true;
            recs[depth] = a[i];
            dfs(depth + 1);
            swap(recs[depth].l, recs[depth].w);
            dfs(depth + 1);
            used[i] = false;
        }
}

int main()
{
    ifstream fin("packrec.in");
    ofstream fout("packrec.out");
    for (int i = 0; i < 4; ++ i)
    {
        Rec rd;
        fin >> rd.l >> rd.w;
        a[i] = rd;
    }
    ans = INF;
    for (int i = 0; i < 4; ++ i)
        used[i] = false;
    dfs(0);
    fout << ans << endl;
    sort(ansRecs.begin(), ansRecs.end(), cmp);
    vector<Rec>::iterator it = unique(ansRecs.begin(), ansRecs.end());
    for (vector<Rec>::iterator i = ansRecs.begin(); i != it; ++ i)
        fout << i -> l << " " << i -> w << endl;
    return 0;
}
