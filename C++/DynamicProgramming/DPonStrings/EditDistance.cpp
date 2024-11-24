#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int recurse(int ind1, int ind2, string &s1, string &s2)
{
    if (ind2 < 0)
        return ind1 + 1;
    if (ind1 < 0)
        return ind2 + 1;

    if (s1[ind1] == s2[ind2])
        return recurse(ind1 - 1, ind2 - 1, s1, s2);
    else
    {
        int x = 1 + recurse(ind1 - 1, ind2, s1, s2);
        int y = 1 + recurse(ind1, ind2 - 1, s1, s2);
        int z = 1 + recurse(ind1 - 1, ind2 - 1, s1, s2);
        return min(x, min(y, z));
    }
    return 0;
}
int tabu(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    for (int j = 0; j <= m; j++)
        dp[0][j] = j;
    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = dp[ind1 - 1][ind2 - 1];
            else
            {
                int x = 1 + dp[ind1 - 1][ind2];
                int y = 1 + dp[ind1][ind2 - 1];
                int z = 1 + dp[ind1 - 1][ind2 - 1];
                dp[ind1][ind2] = min(x, min(y, z));
            }
        }
    }

    return dp[n][m];
}
int space(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);
    for (int j = 0; j <= m; j++)
        prev[j] = j;
    curr[0] = 1;
    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                curr[ind2] = prev[ind2 - 1];
            else
            {
                int x = 1 + prev[ind2];
                int y = 1 + curr[ind2 - 1];
                int z = 1 + prev[ind2 - 1];
                curr[ind2] = min(x, min(y, z));
            }
        }
        prev = curr;
    }
    return prev[m];
}

int minDistance(string s1, string s2)
{
    // return recurse(s1.size() - 1, s2.size() - 1, s1, s2);
    // return tabu(s1, s2);
    return space(s1, s2);
}

int main()
{
    // string s1 = "horse";
    // string s2 = "ros";
    string s1 = "intention";
    string s2 = "execution";
    int ans = minDistance(s1, s2);
    cout << "Answer: " << ans << endl;
    return 0;
}