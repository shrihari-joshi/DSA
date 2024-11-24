#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool recurse(vector<int> &nums, int index, int sum)
{
    if (sum == 0)
        return true;
    if (index == 0)
        return (nums[index] == sum);

    bool nonpick = recurse(nums, index - 1, sum);
    bool pick = false;
    if (sum >= nums[index])
        pick = recurse(nums, index - 1, sum - nums[index]);

    return pick || nonpick;
}
bool memoi(vector<int> &nums, int index, int sum, vector<vector<int>> &dp)
{
    if (sum == 0)
        return true;
    if (index == 0)
        return (nums[index] == sum);

    if (dp[index][sum] != -1)
        return true;

    bool nonpick = memoi(nums, index - 1, sum, dp);
    bool pick = false;
    if (sum >= nums[index])
        pick = memoi(nums, index - 1, sum - nums[index], dp);

    return dp[index][sum] = (pick || nonpick);
}
bool tabulation(vector<int> &nums, int index, int sum)
{
    int n = nums.size();
    vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    if (nums[0] <= sum)
        dp[0][nums[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            bool nonpick = dp[i - 1][j];
            bool pick = false;
            if (j >= nums[i])
                pick = dp[i - 1][j - nums[i]];

            dp[i][j] = pick || nonpick;
        }
    }

    return dp[n - 1][sum];
}
bool space(vector<int> &nums, int index, int sum)
{
    int n = nums.size();
    vector<bool> prev(sum + 1, false), curr(sum + 1, false);

    prev[0] = curr[0] = true;
    prev[nums[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            bool nonpick = prev[j];
            bool pick = false;
            if (j >= nums[i])
                pick = prev[j - nums[i]];

            curr[j] = pick || nonpick;
        }
        prev = curr;
    }

    return prev[sum];
}
bool isSubsetSum(vector<int> &nums, int sum)
{
    int n = nums.size();
    // return recurse(nums, n - 1, sum);
    // vector<vector<int>> dp(100 + 1, vector<int>(1e4 + 1, -1));
    // return memoi(nums, n - 1, sum, dp);
    // return tabulation(nums, n - 1, sum);
    return space(nums, n - 1, sum);
}

int main()
{
    vector<int> nums = {3, 34, 4, 12, 5, 2};

    bool ans = isSubsetSum(nums, 30);
    cout << "\nAnswer: " << ans;

    return 0;
}