#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <unordered_map>
using namespace std;

bool canAliceWin(vector<int> &nums)
{
        int n = nums.size(), one = 0, two = 0;
        for (int i = 0; i < n; i++)
        {
                if (nums[i] > 9)
                        two += nums[i];
                else
                        one += nums[i];
        }
        if (one == two)
                return false;
        return true;
}

int main()
{
        vector<int> nums = {1, 2, 3, 4, 5};
        int ans = canAliceWin(nums);
        cout << "Answer: " << ans;
        return 0;
}
