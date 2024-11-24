#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int shortestCommonSupersequence(string &s1, string &s2)
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
    for (int ind1 = 0; ind1 <= n; ind1++)
    {
        for (int ind2 = 0; ind2 <= m; ind2++)
        {
            cout << dp[ind1][ind2] << "  ";
        }
        cout << endl;
    }

    string temp = "";

    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            temp += s1[i - 1];
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] >= dp[i][j - 1])
            {
                temp += s1[i - 1];
                i--;
            }
            else if (dp[i - 1][j] < dp[i][j - 1])
            {
                temp += s2[j - 1];
                j--;
            }
        }
    }
    while (i > 0)
    {
        temp += s1[i - 1];
        i--;
    }
    while (j > 0)
    {
        temp += s2[j - 1];
        j--;
    }
    reverse(temp.begin(), temp.end());
    cout << temp << endl;
    return dp[n][m];
}

int main()
{
    // string s1 = "aaaaaaaa";
    // string s2 = "aaaaaaaa";
    string s1 = "abac";
    string s2 = "cab";
    int ans = shortestCommonSupersequence(s1, s2);
    cout << "Answer: " << ans << endl;
    return 0;
}