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
vector<bool> space(vector<int> &nums, int index, int sum)
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
    return prev;
}

int minimumDifference(vector<int> &nums)
{
    int n = nums.size(), sum = 0;
    for (int i = 0; i < n; i++)
        sum += nums[i];

    // int ans = recurse(nums, n - 1, sum / 2);
    // bool ans = tabulation(nums, n - 1, sum / 2);
    int ans = 1e9;
    vector<bool> temp = space(nums, n - 1, sum);
    for (int i = 0; i < sum; i++)
    {
        int s1 = 0, s2 = 0;
        if (temp[i] == true)
        {
            s1 = i;
            s2 = sum - i;
            ans = min(ans, abs(s1 - s2));
        }
    }
    cout << ans << endl;

    return ans;
}

int main()
{
    // vector<int> nums = {1, 2, 3, 4};
    vector<int> nums = {-36, 36};
    // vector<int> nums = {3, 9, 7, 3};
    int ans = minimumDifference(nums);
    cout << "\nAnswer: " << ans;

    return 0;
}