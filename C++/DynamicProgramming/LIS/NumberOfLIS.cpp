#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int spaceOptimized(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1), cnt(n, 1);
    int ans = 1;
    for (int ind = 0; ind < n; ind++)
    {
        for (int prev = 0; prev < ind; prev++)
        {
            if (nums[prev] < nums[ind] && 1 + dp[prev] > dp[ind])
            {
                dp[ind] = 1 + dp[prev];
                cnt[ind] = cnt[prev];
            }
            else if (nums[prev] < nums[ind] && 1 + dp[prev] == dp[ind])
                cnt[ind] += cnt[prev];
        }
        ans = max(ans, dp[ind]);
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == ans)
            res += cnt[i];
    }
    return res;
}

int findNumberOfLIS(vector<int> &nums)
{
    int n = nums.size();
    int ans = spaceOptimized(nums);

    return ans;
}

int main()
{
    vector<int> nums = {1, 3, 5, 4, 7};
    // vector<int> nums = {1, 5, 11, 5};
    // vector<int> nums = {2, 2, 2, 2, 2};
    int ans = findNumberOfLIS(nums);
    cout << "\nAnswer: " << ans;

    return 0;
}