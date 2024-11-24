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
        if (nums[0] == sum)
            return 1;
        return 0;
    }
    if (sum == 0)
        return 1;

    int nonpick = recurse(nums, index - 1, sum);
    int pick = 0;
    if (sum >= nums[index])
        pick = recurse(nums, index - 1, sum - nums[index]);

    return pick + nonpick;
}
int tabulation(vector<int> &nums, int index, int sum)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

    for (int j = 0; j <= sum; j++)
    {
        if (j == 0 && nums[0] == 0)
            dp[0][j] = 2;
        else if (nums[0] == j || j == 0)
            dp[0][j] = 1;
    }

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

int perfectSum(vector<int> &nums, int sum)
{
    int n = nums.size();
    // return recurse(nums, n - 1, sum);
    return tabulation(nums, n - 1, sum);
    // return space(nums, n - 1, sum);
}

int main()
{
    // vector<int> nums = {2, 5, 1, 4, 3};
    // vector<int> nums = {2, 5, 1, 4, 3};
    vector<int> nums = {0, 2, 0, 3};

    // vector<int> nums = {9, 7, 0, 3, 9, 8, 6, 5, 7, 6};

    int ans = perfectSum(nums, 5);
    cout << "\nAnswer: " << ans;

    return 0;
}