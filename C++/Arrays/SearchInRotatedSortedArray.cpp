#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> nums = {3, 4, 5, 1, 2};
    int k = 4, ans = -1;

    int s = 0, e = nums.size() - 1;
    while (s <= e) {
        int m = (s + e) / 2;
        if (nums[m] == k) {
            ans = m;
            break; 
        }

        if (nums[s] <= nums[m]) {
            if (nums[s] <= k && k < nums[m])
                e = m - 1;
            else
                s = m + 1;
        } else {
            if (nums[m] < k && k <= nums[e])
                s = m + 1;
            else
                e = m - 1;
        }
    }
    cout << ans + 1 << endl;
    return ans;
}
