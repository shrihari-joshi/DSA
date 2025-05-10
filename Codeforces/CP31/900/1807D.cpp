#include <bits/stdc++.h>
using namespace std;

bool candivide(vector<int> &nums, int k, vector<int> &perm, vector<bool> &used, long long remain)
{
    if (perm.size() == nums.size())
    {
        return remain == 0;
    }

    for (int i = 0; i < nums.size(); ++i)
    {
        if (!used[i])
        {
            used[i] = true;
            int num = nums[i];
            int len = to_string(num).length();
            long long modk = 1;
            for (int j = 0; j < len; ++j)
            {
                modk = (modk * 10) % k;
            }
            long long nextremain = (remain * modk + num) % k;
            perm.push_back(num);
            if (candivide(nums, k, perm, used, nextremain))
            {
                return true;
            }
            perm.pop_back();
            used[i] = false;
        }
    }
    return false;
}

bool findSmallest(vector<int> &nums, int k, vector<int> &perm, vector<bool> &used, long long remain, vector<int> &smallest)
{
    if (perm.size() == nums.size())
    {
        if (remain == 0)
        {
            smallest = perm;
            return true;
        }
        return false;
    }

    for (int i = 0; i < nums.size(); ++i)
    {
        if (!used[i])
        {
            used[i] = true;
            int num = nums[i];
            int len = to_string(num).length();
            long long modk = 1;
            for (int j = 0; j < len; ++j)
            {
                modk = (modk * 10) % k;
            }
            long long nextremain = (remain * modk + num) % k;
            perm.push_back(num);
            if (findSmallest(nums, k, perm, used, nextremain, smallest))
            {
                return true;
            }
            perm.pop_back();
            used[i] = false;
        }
    }
    return false;
}

vector<int> smallestDivisiblePermutation(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    vector<int> smallest;
    vector<bool> used(nums.size(), false);
    vector<int> perm;

    findSmallest(nums, k, perm, used, 0, smallest);
    return smallest;
}

int main()
{
    //  nums = [10,5], k = 10©leetcode
    vector<int> nums = {10, 5};
    int k = 10;
    vector<int> result = smallestDivisiblePermutation(nums, k);
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
