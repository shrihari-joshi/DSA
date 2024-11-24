#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int spaceOptimized(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp1(n, 1);
    for (int ind = 0; ind < n; ind++)
    {
        for (int prev = 0; prev < ind; prev++)
        {
            if (nums[prev] < nums[ind])
                dp1[ind] = max(dp1[ind], 1 + dp1[prev]);
        }
    }
    vector<int> dp2(n, 1);
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev = n - 1; prev > ind; prev--)
        {
            if (nums[prev] < nums[ind])
                dp2[ind] = max(dp2[ind], 1 + dp2[prev]);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        cout << dp1[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << dp2[i] << " ";
    cout << endl;

    for (int i = 1; i < n - 1; i++)
    {
        if (dp1[i] > 1 && dp2[i] > 1)
            ans = max(ans, dp1[i] + dp2[i] - 1);
    }

    return ans;
}

int LongestBitonicSequence(vector<int> &nums)
{
    int ans = spaceOptimized(nums);
    return ans;
}

int main()
{
    // vector<int> nums = {1, 2, 5, 3, 2};
    vector<int> nums = {10, 20, 30};
    // vector<int> nums = {1, 11, 2, 10, 4, 5, 2, 1};
    int ans = LongestBitonicSequence(nums);
    cout << "\nAnswer: " << ans;

    return 0;
}