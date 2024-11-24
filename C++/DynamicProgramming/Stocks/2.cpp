#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int algorithm(vector<int> &prices)
{
    int profit = 0;
    for (int i = 0; i < prices.size() - 1; i++)
    {
        int diff = prices[i + 1] - prices[i];
        if (diff > 0)
            profit += diff;
    }
    return profit;
}

int recurse(int ind, int buy, vector<int> &prices)
{
    if (ind == prices.size())
        return 0;

    int profit = 0;
    if (buy)
        profit = max(-prices[ind] + recurse(ind + 1, 0, prices), recurse(ind + 1, 1, prices));
    else
        profit = max(prices[ind] + recurse(ind + 1, 1, prices), recurse(ind + 1, 0, prices));

    return profit;
}
int tabu(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
                profit = max(-prices[ind] + dp[ind + 1][0], dp[ind + 1][1]);
            else
                profit = max(prices[ind] + dp[ind + 1][1], dp[ind + 1][0]);

            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}
int space(vector<int> &prices)
{
    int n = prices.size();
    int zero = 0, one = 0;

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy)
            {
                profit = max(-prices[ind] + zero, one);
                one = profit;
            }
            else
            {
                profit = max(prices[ind] + one, zero);
                zero = profit;
            }
        }
    }
    return one;
}

int maxProfit(vector<int> &prices)
{
    // return recurse(0, 1, prices);
    // return tabu(prices);
    return space(prices);
}

int main()
{
    // vector<int> prices = {7, 1, 5, 3, 6, 4};
    vector<int> prices = {1, 2, 3, 4, 5};
    // vector<int> prices = {7, 6, 4, 3, 1};
    int ans = maxProfit(prices);
    cout << "Answer: " << ans << endl;
    return 0;
}