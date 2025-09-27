#include <bits/stdc++.h>
using namespace std;

vector<int> computeLPS(string pattern)
{
    int m = pattern.size();
    int len = 0, i = 1;
    vector<int> LPS;
    LPS[0] = 0;
    for (int i = 0; i < m; i++)
}

vector<int> KMP(string text, string pattern)
{
    vector<int> LPS = computeLPS(pattern);
    vector<int> res;
    int n = text.size(), m = pattern.size();
    int i = 0, j = 0;
    while (i < n)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }
        else if (j > 0)
            j = LPS[j - 1];
        else
            i++;

        if (j == m)
        {
            res.push_back(i - j);
            j = LPS[j - 1];
        }
    }
    return res;
}

int main()
{
    string text = "abcabcdabcd";
    string pattern = "abcd";
    vector<int> res = KMP(text, pattern);
    cout << "Indices: ";
    for (auto it : res)
        cout << it << " ";
}