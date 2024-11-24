#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int recurse(int ind1, int ind2, string &s, string &p)
{
    if (ind1 < 0 && ind2 < 0)
        return true;
    if (ind1 < 0 && ind2 >= 0)
        return 0;
    if (ind2 < 0 && ind1 >= 0)
    {
        for (int i = 0; i <= ind1; i++)
            if (s[i] != '*')
                return 0;

        return 1;
    }
    if (s[ind1] == p[ind2] || s[ind1] == '?')
        return recurse(ind1 - 1, ind2 - 1, s, p);
    else
    {
        if (s[ind1] == '*')
            return recurse(ind1 - 1, ind2, s, p) | recurse(ind1, ind2 - 1, s, p);
        else
            return 0;
    }
}
bool isAllStars(string &s, int i)
{
    for (int j = 1; j <= i; j++)
    {
        if (s[j - 1] != '*')
            return false;
    }
    return true;
}
int tabu(string &s, string &p)
{
    int m = p.size(), n = s.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++)
    {
        if (p[i - 1] == '*')
            dp[i][0] = dp[i - 1][0];
        else
            break;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (p[i - 1] == s[j - 1] || p[i - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];

            else if (p[i - 1] == '*')
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];

            else
                dp[i][j] = 0;
        }
    }
    return dp[m][n];
}
int space(string &s, string &p)
{
    int n = s.size();
    int m = p.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);
    prev[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        curr[0] = isAllStars(s, i);
        for (int j = 1; j <= m; j++)
        {
            if (p[i - 1] == s[j - 1] || p[i - 1] == '?')
                curr[j] = prev[j - 1];

            else if (p[i - 1] == '*')
                curr[j] = prev[j] || curr[j - 1];

            else
                curr[j] = 0;
        }
        prev = curr;
    }
    return prev[m];
}

bool isMatch(string s, string p)
{
    // return recurse(p.size() - 1, s.size() - 1, p, s);
    // return tabu(s, p);
    return space(s, p);
}

int main()
{
    // string s = "aa";
    // string p = "a";
    string s = "aa";
    string p = "*";
    bool ans = isMatch(s, p);
    if (ans)
        cout << "True";
    else
        cout << "False";
    return 0;
}