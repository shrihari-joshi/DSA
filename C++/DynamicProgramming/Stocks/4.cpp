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
int tabu(vector<int> &prices, int k)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int t = 1; t <= k; t++)
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
    return dp[0][1][k];
}
int space(vector<int> &prices, int k)
{
    int n = prices.size();
    vector<int> zero(k + 1, 0), one(k + 1, 0);

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int t = 1; t <= k; t++)
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
    return one[k];
}

int maxProfit(vector<int> &prices, int k)
{
    // return recurse(0, 1, k, prices);
    // return tabu(prices, k);
    return space(prices, k);
}

int main()
{
    // vector<int> prices = {2, 4, 1};
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    int ans = maxProfit(prices, 2);
    cout << "Answer: " << ans << endl;
    return 0;
}