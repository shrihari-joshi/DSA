#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
// 0 - even, 1 - odd
// parity = cnt*10 + prevparirty, -1 = empty
int recurse(int i, vector<int> &nums, int parity)
{
    if (i == nums.size())
        return 1;

    int notPick = recurse(i + 1, nums, parity);
    int pick = 0;

    if (parity == -1)
        pick = recurse(i + 1, nums, 10 + nums[i] % 2);

    else
    {
        int curr = parity % 10, cnt = parity / 10;
        if (nums[i] % 2 == curr)
        {
            if (cnt < 2)
                pick = recurse(i + 1, nums, (cnt + 1) * 10 + curr);
        }
        else
            pick = recurse(i + 1, nums, 10 + nums[i] % 2);
    }

    return (pick + notPick) % mod;
}
int countStableSubsequencesTabulation(vector<int> &nums)
{
    int n = nums.size();
    vector<int> states = {-1, 10, 20, 11, 21};
    unordered_map<int, int> mp;
    for (int i = 0; i < states.size(); i++)
        mp[states[i]] = i;

    vector<vector<int>> dp(n + 1, vector<int>(states.size(), 0));

    for (int si = 0; si < states.size(); si++)
        dp[n][si] = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        int currp = nums[i] % 2;
        for (int si = 0; si < states.size(); si++)
        {
            int state = states[si];
            long long ways = 0;

            ways += dp[i + 1][si];

            if (state == -1)
                ways += dp[i + 1][mp[10 + currp]];

            else
            {
                int cnt = state / 10, par = state % 10;
                if (currp == par)
                {
                    if (cnt < 2)
                        ways += dp[i + 1][mp[(cnt + 1) * 10 + par]];
                }
                else
                    ways += dp[i + 1][mp[10 + currp]];
                        }

            dp[i][si] = ways % mod;
        }
    }

    return (dp[0][mp[-1]] - 1 + mod) % mod;
}

int countStableSubsequences(vector<int> &nums)
{
    long long res = recurse(0, nums, -1);
    return (res - 1 + mod) % mod;
}

int main()
{
    // vector<int> nums = {2, 3, 4, 2};
    vector<int> nums = {1, 3, 5};
    // cout << countStableSubsequences(nums) << endl;
    cout << countStableSubsequencesTabulation(nums) << endl;
    return 0;
}
