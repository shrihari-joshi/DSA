#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int recurse(vector<int> &nums, int index, int prev)
{
    if (index == nums.size())
        return 0;

    int nonpick = recurse(nums, index + 1, prev);
    int pick = 0;

    if (prev == -1 || nums[prev] < nums[index])
        pick = 1 + recurse(nums, index + 1, index);

    return max(pick, nonpick);
}
int tabulation(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev = ind - 1; prev >= -1; prev--)
        {
            int nonpick = dp[ind + 1][prev + 1];
            int pick = 0;

            if (prev == -1 || nums[prev] < nums[ind])
                pick = 1 + dp[ind + 1][ind + 1];

            dp[ind][prev + 1] = max(pick, nonpick);
        }
    }
    return dp[0][0];
}
int space(vector<int> &nums)
{
    int n = nums.size();
    vector<int> next(n + 1, 0), curr(n + 1, 0);

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev = ind - 1; prev >= -1; prev--)
        {
            int nonpick = next[prev + 1];
            int pick = 0;

            if (prev == -1 || nums[prev] < nums[ind])
                pick = 1 + next[ind + 1];

            curr[prev + 1] = max(pick, nonpick);
        }
        next = curr;
    }
    return next[0];
}
int usingBS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> temp;
    temp.push_back(nums[0]);
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > temp.back())
        {
            temp.push_back(nums[i]);
            ans++;
        }
        else
        {
            int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            temp[ind] = nums[i];
        }
    }
    return ans;
}

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    // int ans = recurse(nums, 0, -1);
    // int ans = tabulation(nums);
    // int ans = space(nums);
    int ans = usingBS(nums);
    cout << ans << endl;

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3, 5};
    // vector<int> nums = {1, 5, 11, 5};
    // vector<int> nums = {5, 5, 5};
    int ans = lengthOfLIS(nums);
    cout << "\nAnswer: " << ans;

    return 0;
}