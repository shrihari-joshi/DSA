#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int recurse(vector<int> &coins, int amount)
{
	if (amount == 0)
		return 0;
	if (amount < 0)
		return INT_MAX;
	int res = INT_MAX;
	for (int i = 0; i < coins.size(); i++)
	{
		int ans = recurse(coins, amount - coins[i]) + 1;
		if (ans != INT_MAX)
			res = min(res, ans);
	}
	return res;
}
int memoisation(vector<int> &coins, int amount, vector<int> &dp)
{
	if (amount == 0)
		return 0;
	if (amount < 0)
		return INT_MAX;

	if (dp[amount] != -1)
		return dp[amount];

	int res = INT_MAX;
	for (int i = 0; i < coins.size(); i++)
	{
		int ans = memoisation(coins, amount - coins[i], dp);
		if (ans != INT_MAX)
			res = min(res, ans + 1);
	}
	dp[amount] = res;
	return res;
}
int tabulation(vector<int> &coins, int amount)
{
	vector<int> dp(amount + 1, -1);
	dp[0] = 0;
	for (int i = 1; i <= amount; i++)
	{
		dp[i] = INT_MAX;
		for (int j = 0; j < coins.size(); j++)
		{
			if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX)
				dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
		}
	}

	return dp[amount];
}

int coinChange(vector<int> &coins, int amount)
{
	if (amount == 0)
		return 0;
	// 	int ans = recurse(coins, amount);
	vector<int> dp(amount + 1, -1);
	int ans = memoisation(coins, amount, dp);
	// int ans = tabulation(coins, amount);
	if (ans == INT_MAX)
		return -1;
	return ans;
}

int main()
{
	vector<int> coins = {1, 2, 3};
	int amount = 11;
	// 	vector<int> coins = {2};
	// 	int amount = 3;
	// vector<int> coins = {411, 412, 413, 414, 415, 416, 417, 418, 419, 420, 421, 422};
	// int amount = 9864;
	int ans = coinChange(coins, amount);
	cout << ans;

	return 0;
}