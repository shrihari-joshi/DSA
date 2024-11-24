#include<iostream>
#include<vector>
using namespace std;


int MatrixChain(vector<vector<int>> &dp, vector<int> &nums, int i, int j){

    if(i == j)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];

    dp[i][j] = INT16_MAX;
    for(int k=i;k<j;k++)
    {
        dp[i][j] = min(dp[i][j], MatrixChain(dp, nums, i, k) + MatrixChain(dp, nums, k+1, j) + 
                                    nums[i-1]*nums[k]*nums[j]);
    }
    return dp[i][j];
}

int main() {
    vector<int> nums = {1,2,3,4,5};
    int n = nums.size();
    vector<vector<int>> dp (n, vector<int>(n, -1));
    cout<< "Minimum Multiplication required: " << MatrixChain(dp, nums, 1, n-1) << endl<< endl;
}
