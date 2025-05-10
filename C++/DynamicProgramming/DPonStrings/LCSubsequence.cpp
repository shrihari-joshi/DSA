#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int recurse(int ind1, int ind2, string &s1, string &s2)
{
    if (ind1 < 0 || ind2 < 0)
        return 0;

    if (s1[ind1] == s2[ind2])
        return 1 + recurse(ind1 - 1, ind2 - 1, s1, s2);

    return max(recurse(ind1 - 1, ind2, s1, s2), recurse(ind1, ind2 - 1, s1, s2));
}
int tabu(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
        }
    }
    // for (int ind1 = 0; ind1 <= n; ind1++)
    // {
    //     for (int ind2 = 0; ind2 <= m; ind2++)
    //     {
    //         cout << dp[ind1][ind2] << "  ";
    //     }
    //     cout << endl;
    // }

    // int i = n, j = m, len = dp[n][m], index = len - 1;
    // while (i > 0 && j > 0)
    // {
    //     if (s1[i - 1] == s2[j - 1])
    //     {
    //         temp[index] = s1[i - 1];
    //         index--;
    //         i--;
    //         j--;
    //     }
    //     else
    //     {
    //         if (dp[i - 1][j] > dp[i][j - 1])
    //             i--;
    //         else if (dp[i - 1][j] < dp[i][j - 1])
    //             j--;
    //         else
    //         {
    //             i--;
    //             j--;
    //         }
    //     }
    // }

    // cout << temp << endl;
    return dp[n][m];
}
int space(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                curr[ind2] = 1 + prev[ind2 - 1];
            else
                curr[ind2] = max(prev[ind2], curr[ind2 - 1]);
        }
        prev = curr;
    }

    return prev[m];
}

int longestCommonSubsequence(string s1, string s2)
{
    // return recurse(s1.size() - 1, s2.size() - 1, s1, s2);
    return tabu(s1, s2);
}

int main()
{
    string s1 = "abaaa";
    string s2 = "baabaca";
    int ans = longestCommonSubsequence(s1, s2);
    cout << "Answer: " << ans << endl;
    return 0;
}