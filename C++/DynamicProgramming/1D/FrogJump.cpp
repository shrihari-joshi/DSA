#include <iostream>
#include <map>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;

int recurse(vector<int> height, int n)
{
    if (n == 0)
        return 0;
    int left = recurse(height, n - 1) + abs(height[n] - height[n - 1]);
    int right = INT_MAX;
    if (n > 1)
        right = recurse(height, n - 2) + abs(height[n] - height[n - 2]);

    return min(left, right);
}
int memoisation(vector<int> height, int n, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int left = memoisation(height, n - 1, dp) + abs(height[n] - height[n - 1]);
    int right = INT_MAX;
    if (n > 1)
        right = memoisation(height, n - 2, dp) + abs(height[n] - height[n - 2]);

    return min(left, right);
}

int Tabulation(vector<int> &height, int n)
{
    vector<int> dp(n, 0);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int a = dp[i - 1] + abs(height[i] - height[i - 1]);
        int b = INT_MAX;
        if (i > 1)
            b = dp[i - 2] + abs(height[i] - height[i - 2]);

        dp[i] = min(a, b);
    }
    return dp[n - 1];
}
int main()
{
    vector<int> nums = {10, 50, 10};
    int n = nums.size();
    vector<int> dp(n + 1, -1);
    int ans = memoisation(nums, n - 1, dp);
    // int ans = Tabulation(nums, n - 1);
    cout << ans;
    return 0;
}