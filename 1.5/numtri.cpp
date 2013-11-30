/*
ID: pkulinf2
TASK: numtri
LANG: C++
*/
#include <fstream>
using namespace std;

int f[1001][1001];
int a[1001][1001];

int main()
{
    ifstream fin("numtri.in");
    ofstream fout("numtri.out");

    int n;
    fin >> n;
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j <= i; ++ j)
            fin >> a[i][j];

    f[0][0] = a[0][0];
    for (int i = 1; i < n; ++ i)
    {
        f[i][0] = f[i - 1][0] + a[i][0];
        for (int j = 1; j <= i; ++ j)
            f[i][j] = max(f[i - 1][j - 1], f[i - 1][j]) + a[i][j];
    }

    int ans = 0;
    for (int i = 0; i < n; ++ i)
        ans = max(ans, f[n - 1][i]);

    fout << ans << endl;
    return 0;
}
