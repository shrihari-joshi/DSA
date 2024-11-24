#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int recurse(vector<int> &val, vector<int> &wt, int index, int weight)
{
    if (index == 0)
    {
        return (weight / wt[0]) * val[0];
    }
    if (weight == 0)
        return 0;

    int nonpick = recurse(val, wt, index - 1, weight);
    int pick = INT_MIN;
    if (weight >= wt[index])
        pick = val[index] + (val, wt, index, weight - wt[index]);

    return max(pick, nonpick);
}
int tabulation(vector<int> &val, vector<int> &wt, int weight)
{
    int n = val.size();
    vector<vector<int>> dp(n, vector<int>(weight + 1, 0));

    for (int w = 0; w <= weight; w++)
        dp[0][w] = ((int)(w / wt[0])) * val[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int w = 0; w <= weight; w++)
        {
            int nonpick = dp[ind - 1][w];
            int pick = 0;
            if (w >= wt[ind])
                pick = val[ind] + dp[ind][w - wt[ind]];

            dp[ind][w] = max(pick, nonpick);
        }
    }

    return dp[n - 1][weight];
}
int space(vector<int> &val, vector<int> &wt, int weight)
{
    int n = val.size();
    vector<int> prev(weight + 1, 0), curr(weight + 1, 0);

    for (int w = 0; w <= weight; w++)
        prev[w] = ((int)(w / wt[0])) * val[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int w = 0; w <= weight; w++)
        {
            int nonpick = prev[w];
            int pick = 0;
            if (w >= wt[ind])
                pick = val[ind] + curr[w - wt[ind]];

            curr[w] = max(pick, nonpick);
        }
        prev = curr;
    }

    return prev[weight];
}

int knapSack(int W, vector<int> val, vector<int> wt)
{
    int n = val.size();
    // return recurse(val, wt, n - 1, W);
    // return tabulation(val, wt, W);
    return space(val, wt, W);
}

int main()
{
    // vector<int> val = {1, 1};
    // vector<int> wt = {2, 1};

    vector<int> val = {6, 1, 7, 7};
    vector<int> wt = {1, 3, 4, 5};

    int ans = knapSack(8, val, wt);
    cout << "\nAnswer: " << ans;

    return 0;
}