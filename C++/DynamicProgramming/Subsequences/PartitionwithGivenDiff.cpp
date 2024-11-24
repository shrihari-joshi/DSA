#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int recurse(vector<int> &nums, int index, int sum)
{
    if (index == 0)
    {
        if (nums[0] == 0 && sum == 0)
            return 2;
        if (nums[0] == sum || sum == 0)
            return 1;
        return 0;
    }

    int nonpick = recurse(nums, index - 1, sum);
    int pick = 0;
    if (sum >= nums[index])
        pick = recurse(nums, index - 1, sum - nums[index]);

    return pick + nonpick;
}
int tabulation(vector<int> &nums, int sum)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

    if (nums[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;

    if (nums[0] != 0 && nums[0] <= sum)
        dp[0][nums[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            int nonpick = dp[i - 1][j];
            int pick = 0;
            if (j >= nums[i])
                pick = dp[i - 1][j - nums[i]];

            dp[i][j] = pick + nonpick;
        }
    }
    return dp[n - 1][sum];
}
int space(vector<int> &nums, int sum)
{
    int n = nums.size();
    vector<int> prev(sum + 1, 0), curr(sum + 1, 0);

    if (nums[0] == 0)
        prev[0] = 2;
    else
        prev[0] = 1;

    if (nums[0] != 0 && nums[0] <= sum)
        prev[nums[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            int nonpick = prev[j];
            int pick = 0;
            if (j >= nums[i])
                pick = prev[j - nums[i]];

            curr[j] = pick + nonpick;
        }
        prev = curr;
    }
    return prev[sum];
}

int perfectSum(vector<int> &nums, int sum)
{
    int n = nums.size();
    // return recurse(nums, n - 1, sum);
    // return tabulation(nums, sum);
    return space(nums, sum);
}

int main()
{
    vector<int> nums = {1, 1, 1, 1};
    // vector<int> nums = {1, 3, 3, 2, 1};
    // vector<int> nums = {5, 2, 6, 4};

    int sum = 0, diff = 0;
    for (int i = 0; i < nums.size(); i++)
        sum += nums[i];

    if (sum - diff < 0 || (sum - diff) % 2)
    {
        cout << "\nAnswer: 0";
        return 0;
    }

    int ans = perfectSum(nums, (sum - diff) / 2);
    cout << "\nAnswer: " << ans;

    return 0;
}