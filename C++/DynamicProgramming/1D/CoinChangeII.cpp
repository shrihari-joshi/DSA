#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int recurse(vector<int> &coins, int amount, int index)
{
    if (index == 0)
    {
        if (amount % coins[index] == 0)
            return 1;
        else
            return 0;
    }

    int notpick = recurse(coins, amount, index - 1);
    int pick = 0;
    if (coins[index] <= amount)
        pick = recurse(coins, amount - coins[index], index);

    return pick + notpick;
}
int memoi(vector<int> &coins, int amount, int index, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (amount % coins[index] == 0)
            return 1;
        else
            return 0;
    }
    if (dp[index][amount] != -1)
        return dp[index][amount];

    int notpick = memoi(coins, amount, index - 1, dp);
    int pick = 0;
    if (coins[index] <= amount)
        pick = memoi(coins, amount - coins[index], index, dp);

    dp[index][amount] = pick + notpick;
    return pick + notpick;
}

int tabulation(vector<int> &coins, int amount)
{
    vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));

    for (int j = 0; j <= amount; j++)
    {
        if (j % coins[0] == 0)
            dp[0][j] = 1;
        else
            dp[0][j] = 0;
    }
    for (int i = 1; i < coins.size(); i++)
    {
        for (int j = 0; j <= amount; j++)
        {

            int notpick = dp[i - 1][j];
            int pick = 0;
            if (coins[i] <= j)
                pick = dp[i][j - coins[i]];

            dp[i][j] = pick + notpick;
        }
    }
    return dp[coins.size() - 1][amount];
}
int space(vector<int> &coins, int amount)
{
    vector<int> prev(amount + 1, -1), curr(amount + 1, -1);

    for (int j = 0; j <= amount; j++)
    {
        if (j % coins[0] == 0)
            prev[j] = 1;
        else
            prev[j] = 0;
    }
    for (int i = 1; i < coins.size(); i++)
    {
        for (int j = 0; j <= amount; j++)
        {

            int notpick = prev[j];
            int pick = 0;
            if (coins[i] <= j)
                pick = curr[j - coins[i]];

            curr[j] = pick + notpick;
        }
        prev = curr;
    }
    return prev[amount];
}
int coinChange(vector<int> &coins, int amount)
{
    if (amount == 0)
        return 0;
    // int ans = recurse(coins, amount, coins.size() - 1);
    // vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
    // int ans = memoi(coins, amount, coins.size() - 1, dp);
    // int ans = tabulation(coins, amount);
    int ans = space(coins, amount);
    return ans;
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    // vector<int> coins = {10};
    // int amount = 10;
    // vector<int> coins = {411, 412, 413, 414, 415, 416, 417, 418, 419, 420, 421, 422};
    // int amount = 9864;
    int ans = coinChange(coins, amount);
    cout << ans;

    return 0;
}