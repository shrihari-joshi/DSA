#include <bits/stdc++.h>
using namespace std;

int calc(long long n)
{
    int count = 0;
    while (n > 0)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
int magicalSum(int M, int K, vector<int> &nums)
{
    vector<int> prod;
    int mod = 1e9 + 7;
    for (int i = 0; i < nums.size(); i++)
    {
        long long seq = 0;
        for (int j = i; j < nums.size() && j < i + M; j++)
            seq += pow(2, nums[j]);

        int bits = calc(seq);
        if (bits == K)
            prod.push_back(seq);
    }
    for (int i = 0; i < prod.size(); i++)
        cout << prod[i] << " ";
    cout << endl;
    int ans = 0;
    for (int i = 0; i < prod.size(); i++)
    {
        ans += prod[i] % mod;
    }
    return ans;
}

int main()
{
    // M = 5, K = 5, nums = [1,10,100,10000,1000000]
    int M = 5, K = 5;
    vector<int> nums = {1, 10, 100, 10000, 1000000};
    int result = magicalSum(M, K, nums);
    cout << "The magical sum is: " << result << endl;
    return 0;
}
