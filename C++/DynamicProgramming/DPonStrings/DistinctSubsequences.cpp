#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int recurse(int ind1, int ind2, string &s1, string &s2)
{
    if (ind2 < 0)
        return 1;
    if (ind1 < 0)
        return 0;

    if (s1[ind1] == s2[ind2])
        return recurse(ind1 - 1, ind2, s1, s2) + recurse(ind1 - 1, ind2 - 1, s1, s2);
    else
        return recurse(ind1 - 1, ind2, s1, s2);
}
int tabu(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = dp[ind1 - 1][ind2] + dp[ind1 - 1][ind2 - 1];
            else
                dp[ind1][ind2] = dp[ind1 - 1][ind2];
        }
    }

    return dp[n][m];
}
int space(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);
    prev[0] = 1;
    curr[0] = 1;
    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                curr[ind2] = prev[ind2] + prev[ind2 - 1];
            else
                curr[ind2] = prev[ind2];
        }
        prev = curr;
    }
    return prev[m];
}

int numDistinctSubsequence(string s1, string s2)
{
    // return recurse(s1.size() - 1, s2.size() - 1, s1, s2);
    // return tabu(s1, s2);
    return space(s1, s2);
}

int main()
{
    string s1 = "babgbag";
    string s2 = "bag";
    int ans = numDistinctSubsequence(s1, s2);
    cout << "Answer: " << ans << endl;
    return 0;
}