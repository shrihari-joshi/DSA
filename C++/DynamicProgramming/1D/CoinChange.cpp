#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int recurse(vector<int> &coins, int amount, int index)
{
	if (amount == 0)
		return 0;
	if (index == coins.size())
		return INT_MAX - 1;

	int notpick = recurse(coins, amount, index + 1);
	int pick = INT_MAX;
	if (coins[index] <= amount)
		pick = recurse(coins, amount - coins[index], index) + 1;

	return min(pick, notpick);
}

int coinChange(vector<int> &coins, int amount)
{
	if (amount == 0)
		return 0;
	// int ans = recurse(coins, amount, 0);
	vector<int> dp(amount + 1, -1);
	int ans = memoisation(coins, amount, 0, dp);
	if (ans == INT_MAX - 1)
		return -1;
	return ans;
}

int main()
{
	vector<int> coins = {1, 2, 3};
	int amount = 11;
	// vector<int> coins = {2};
	// int amount = 3;
	// 	vector<int> coins = {411,412,413,414,415,416,417,418,419,420,421,422};
	// 	int amount = 9864;
	int ans = coinChange(coins, amount);
	cout << ans;

	return 0;
}