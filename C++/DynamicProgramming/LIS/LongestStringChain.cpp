#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

bool check(string &s1, string &s2)
{
    if (s1.size() != s2.size() + 1)
        return false;

    int first = 0, sec = 0;
    while (first < s1.size())
    {
        if (sec < s2.size() && s1[first] == s2[sec])
        {
            first++;
            sec++;
        }
        else
            first++;
    }
    if (first == s1.size() && sec == s2.size())
        return true;
    return false;
}
bool comp(string &s1, string &s2)
{
    return s1.size() < s2.size();
}
int printLIS(vector<string> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    sort(nums.begin(), nums.end(), comp);
    int ans = 1;
    for (int ind = 0; ind < n; ind++)
    {
        for (int prev = 0; prev < ind; prev++)
        {
            if (check(nums[ind], nums[prev]) && dp[ind] < 1 + dp[prev])
                dp[ind] = 1 + dp[prev];
        }
        ans = max(ans, dp[ind]);
    }
    return ans;
}
int longestStrChain(vector<string> &nums)
{
    int ans = printLIS(nums);
    return ans;
}

int main()
{
    // vector<string> nums = {"a", "b", "ba", "bca", "bda", "bdca"};
    vector<string> nums = {"xbc", "pcxbcf", "xb", "cxbc", "pcxbc"};
    // vector<string> nums = {"abcd", "dbqca"};
    int ans = longestStrChain(nums);
    cout << "\nAnswer: " << ans;

    return 0;
}