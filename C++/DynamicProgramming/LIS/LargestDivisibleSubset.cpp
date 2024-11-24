#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int spaceOptimized(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);

    int ans = 0;
    for (int ind = 0; ind < n; ind++)
    {
        for (int prev = 0; prev < ind; prev++)
        {
            if (nums[prev] < nums[ind])
                dp[ind] = max(dp[ind], 1 + dp[prev]);
        }
        ans = max(ans, dp[ind]);
    }
    return ans;
}
vector<int> printLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1), hash(n);
    sort(nums.begin(), nums.end());
    int ans = 0, lastInd = 0;
    for (int ind = 0; ind < n; ind++)
    {
        hash[ind] = ind;
        for (int prev = 0; prev < ind; prev++)
        {
            if (nums[ind] % nums[prev] == 0 && dp[ind] < 1 + dp[prev])
            {
                dp[ind] = 1 + dp[prev];
                hash[ind] = prev;
            }
        }
        if (dp[ind] > ans)
        {
            ans = dp[ind];
            lastInd = ind;
        }
    }
    vector<int> temp;
    temp.push_back(nums[lastInd]);
    while (hash[lastInd] != lastInd)
    {
        lastInd = hash[lastInd];
        temp.push_back(nums[lastInd]);
    }
    for (int i = temp.size() - 1; i >= 0; i--)
        cout << temp[i] << " ";

    cout << endl;
    return temp;
}

vector<int> largestDivisibleSubset(vector<int> &nums)
{
    vector<int> ans = printLIS(nums);
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 4, 5};
    // vector<int> nums = {1, 5, 11, 5};
    // vector<int> nums = {5, 5, 5};
    vector<int> ans = largestDivisibleSubset(nums);

    return 0;
}