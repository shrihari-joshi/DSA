#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool recurse(vector<int> &nums, int index, int sum)
{
    if (sum == 0)
        return true;

    if (index == 0)
        return (nums[0] == sum);

    bool nonpick = recurse(nums, index - 1, sum);
    bool pick = false;
    if (sum >= nums[index])
        pick = recurse(nums, index - 1, sum - nums[index]);

    return (pick || nonpick);
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

            dp[i][j] = (pick || nonpick);
        }
    }
    return dp[n - 1][sum];
}
bool space(vector<int> &nums, int index, int sum)
{
    int n = nums.size();
    vector<bool> prev(sum + 1, false), curr(sum + 1, false);

    prev[0] = curr[0] = true;

    if (nums[0] <= sum)
        prev[nums[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {

            bool nonpick = prev[j];
            bool pick = false;
            if (j >= nums[i])
                pick = prev[j - nums[i]];

            curr[j] = (pick || nonpick);
        }
        prev = curr;
    }
    return prev[sum];
}

bool canPartition(vector<int> &nums)
{
    int n = nums.size(), sum = 0;
    for (int i = 0; i < n; i++)
        sum += nums[i];
    if (sum % 2 != 0)
        return false;
    // int ans = recurse(nums, n - 1, sum / 2);
    // bool ans = tabulation(nums, n - 1, sum / 2);
    bool ans = space(nums, n - 1, sum / 2);
    cout << ans << endl;

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 5};
    // vector<int> nums = {1, 5, 11, 5};
    bool ans = canPartition(nums);
    cout << "\nAnswer: " << ans;

    return 0;
}