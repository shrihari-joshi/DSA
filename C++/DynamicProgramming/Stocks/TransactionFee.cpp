#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int recurse(int ind, int buy, int fee, vector<int> &prices)
{
    if (ind == prices.size())
        return 0;

    int profit = 0;
    if (buy)
        profit = max(-prices[ind] + recurse(ind + 1, 0, fee, prices), recurse(ind + 1, 1, fee, prices));
    else
        profit = max(prices[ind] - fee + recurse(ind + 1, 1, fee, prices), recurse(ind + 1, 0, fee, prices));

    return profit;
}
int tabu(vector<int> &prices, int fee)
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
                profit = max(prices[ind] - fee + dp[ind + 1][1], dp[ind + 1][0]);

            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}
int space(vector<int> &prices, int fee)
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
                profit = max(prices[ind] - fee + one, zero);
                zero = profit;
            }
        }
    }
    return one;
}

int maxProfit(vector<int> &prices, int fee)
{
    // return recurse(0, 1, fee, prices);
    // return tabu(prices, fee);
    return space(prices, fee);
}

int main()
{
    vector<int> prices = {1, 3, 7, 5, 10, 3};
    // vector<int> prices = {1, 3, 2, 8, 4, 9};
    int ans = maxProfit(prices, 3);
    cout << "Answer: " << ans << endl;
    return 0;
}