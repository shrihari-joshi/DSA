#include <iostream>
#include <vector>
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
void printLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1), hash(n);

    int ans = 0, lastInd = 0;
    for (int ind = 0; ind < n; ind++)
    {
        hash[ind] = ind;
        for (int prev = 0; prev < ind; prev++)
        {
            if (nums[prev] < nums[ind] && dp[ind] < 1 + dp[prev])
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
}

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    int ans = spaceOptimized(nums);
    cout << "LIS: ";
    printLIS(nums);

    return ans;
}

int main()
{
    // vector<int> nums = {1, 2, 3, 5};
    // vector<int> nums = {1, 5, 11, 5};
    vector<int> nums = {5, 5, 5};
    int ans = lengthOfLIS(nums);
    cout << "\nAnswer: " << ans;

    return 0;
}