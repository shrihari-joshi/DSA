#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int tabu(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();
    int ans = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];

            ans = max(ans, dp[ind1][ind2]);
        }
    }

    return ans;
}
int space(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();
    int ans = 0;
    vector<int> prev(m + 1, 0), curr(m + 1, 0);

    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (s1[ind1 - 1] == s2[ind2 - 1])
            {
                curr[ind2] = 1 + prev[ind2 - 1];
                ans = max(ans, curr[ind2]);
            }
            else
                curr[ind2] = 0;
        }
        prev = curr;
    }

    return ans;
}

int longestCommonSubstr(string s1, string s2)
{
    return space(s1, s2);
}

int main()
{
    string s1 = "ABCDGH";
    string s2 = "ACDGHR";
    int ans = longestCommonSubstr(s1, s2);
    cout << "Answer: " << ans << endl;
    return 0;
}