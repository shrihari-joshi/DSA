#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int recurse(int ind, int buy, vector<int> &prices)
{
    if (ind >= prices.size())
        return 0;

    int profit = 0;
    if (buy)
        profit = max(-prices[ind] + recurse(ind + 1, 0, prices), recurse(ind + 1, 1, prices));
    else
        profit = max(prices[ind] + recurse(ind + 2, 1, prices), recurse(ind + 1, 0, prices));

    return profit;
}
int tabu(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
                profit = max(-prices[ind] + dp[ind + 1][0], dp[ind + 1][1]);
            else
                profit = max(prices[ind] + dp[ind + 2][1], dp[ind + 1][0]);

            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}
int tabulationOptimized(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        dp[ind][1] = max(-prices[ind] + dp[ind + 1][0], dp[ind + 1][1]);

        dp[ind][0] = max(prices[ind] + dp[ind + 2][1], dp[ind + 1][0]);
    }
    return dp[0][1];
}
int space(vector<int> &prices)
{
    int n = prices.size();
    vector<int> front2(2, 0), front1(2, 0), curr(2, 0);

    for (int ind = n - 1; ind >= 0; ind--)
    {
        curr[1] = max(-prices[ind] + front1[0], front1[1]);
        curr[0] = max(prices[ind] + front2[1], front1[0]);
        front2 = front1;
        front1 = curr;
    }
    return curr[1];
}

int maxProfit(vector<int> &prices)
{
    // return recurse(0, 1, prices);
    // return tabu(prices);
    return space(prices);
}

int main()
{
    vector<int> prices = {1, 2, 3, 0, 2};
    // vector<int> prices = {1};
    int ans = maxProfit(prices);
    cout << "Answer: " << ans << endl;
    return 0;
}