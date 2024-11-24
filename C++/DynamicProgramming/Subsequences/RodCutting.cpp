#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int recurse(vector<int> &price, int index, int n)
{
    if (index == 0)
    {
        return n * price[0];
    }
    if (n == 0)
        return 0;

    int nonpick = recurse(price, index - 1, n);
    int pick = INT_MIN;
    if (n >= index + 1)
        pick = price[index] + (price, index, n - index + 1);

    return max(pick, nonpick);
}
int tabulation(vector<int> &price, int len)
{
    int n = price.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));

    for (int l = 0; l <= n; l++)
        dp[0][l] = l * price[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int l = 0; l <= n; l++)
        {
            int nonpick = dp[ind - 1][l];
            int pick = 0;
            if (l >= ind + 1)
                pick = price[ind] + dp[ind][l - ind - 1];

            dp[ind][l] = max(pick, nonpick);
        }
    }

    return dp[n - 1][n];
}
int space(vector<int> &price, int len)
{
    int n = price.size();
    vector<int> prev(n + 1, 0), curr(n + 1, 0);

    for (int l = 0; l <= n; l++)
        prev[l] = l * price[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int l = 0; l <= n; l++)
        {
            int nonpick = prev[l];
            int pick = 0;
            if (l >= ind + 1)
                pick = price[ind] + curr[l - ind - 1];

            curr[l] = max(pick, nonpick);
        }
        prev = curr;
    }

    return prev[n];
}

int knapSack(int n, vector<int> price)
{
    // return recurse(price, s - 1, n);
    // return tabulation(price, n);
    return space(price, n);
}

int main()
{

    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    // vector<int> price = {3, 5, 8, 9, 10, 17, 17, 20};

    int ans = knapSack(8, price);
    cout << "\nAnswer: " << ans;

    return 0;
}