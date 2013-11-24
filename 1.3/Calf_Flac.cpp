/*
ID: pkulinf2
LANG: C++
TASK: calfflac
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <string>
using namespace std;

vector<char> all_chars;
vector<char> alphas;
int maxlen, ansi, ansj;
string ansstr;
int pos[30000];

void findp(int i, int j)
{
    int len = alphas.size();
    while (i >= 0 && j < len && alphas[i] == alphas[j])
    {
        i --;
        j ++;
    }
    i ++; j --;
    if (j - i + 1 > maxlen)
    {
        maxlen = j - i + 1;
        ansi = i;
        ansj = j;
    }
}

int main()
{
    ifstream fin("calfflac.in");
    ofstream fout("calfflac.out");

    char s;
    while (fin.get(s))
    {
        all_chars.push_back(s);
        if (isalpha(s))
        {
            alphas.push_back(toupper(s));
            pos[alphas.size() - 1] = all_chars.size() - 1;
        }
    }

    maxlen = 0;
    for (int i = 0; i < alphas.size(); ++ i)
    {
        findp(i - 1, i + 1);
        findp(i, i + 1);
    }
    fout << maxlen << endl;
    for (int i = pos[ansi]; i <= pos[ansj]; ++ i)
        fout << all_chars[i];
    fout << endl;
    return 0;
}
