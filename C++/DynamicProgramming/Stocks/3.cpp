#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int recurse(int ind, int buy, int t, vector<int> &prices)
{
    if (t == 0)
        return 0;
    if (ind == prices.size())
        return 0;

    int profit = 0;
    if (buy)
        profit = max(-prices[ind] + recurse(ind + 1, 0, t, prices), recurse(ind + 1, 1, t, prices));
    else
        profit = max(prices[ind] + recurse(ind + 1, 1, t - 1, prices), recurse(ind + 1, 0, t, prices));

    return profit;
}
int tabu(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int t = 1; t <= 2; t++)
            {
                int profit = 0;
                if (buy)
                    profit = max(-prices[ind] + dp[ind + 1][0][t], dp[ind + 1][1][t]);
                else
                    profit = max(prices[ind] + dp[ind + 1][1][t - 1], dp[ind + 1][0][t]);

                dp[ind][buy][t] = profit;
            }
        }
    }
    return dp[0][1][2];
}
int space(vector<int> &prices)
{
    int n = prices.size();
    vector<int> zero(3, 0), one(3, 0);

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int t = 1; t <= 2; t++)
            {
                int profit = 0;
                if (buy)
                {
                    profit = max(-prices[ind] + zero[t], one[t]);
                    one[t] = profit;
                }
                else
                {
                    profit = max(prices[ind] + one[t - 1], zero[t]);
                    zero[t] = profit;
                }
            }
        }
    }
    return one[2];
}

int maxProfit(vector<int> &prices)
{
    // return recurse(0, 1, 2, prices);
    // return tabu(prices);
    return space(prices);
}

int main()
{
    // vector<int> prices = {7, 1, 5, 3, 6, 4};
    // vector<int> prices = {1, 2, 3, 4, 5};
    // vector<int> prices = {7, 6, 4, 3, 1};
    // vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int ans = maxProfit(prices);
    cout << "Answer: " << ans << endl;
    return 0;
}