#include<iostream>
#include<vector>
using namespace std;


int Sub_Sequence_recursion(string A, string B, int i, int j){

    if(A[i] == '\0' || B[j] == '\0')
        return 0;
    else if(A[i] == B[j])
        return 1 + Sub_Sequence_recursion(A,B,i+1,j+1);
    else 
        return max(Sub_Sequence_recursion(A,B,i+1,j), Sub_Sequence_recursion(A,B,i,j+1));
        
}
int Sub_Sequence_DP(vector<vector<int>> &dp, string A, string B, int i, int j)
{
    if(i == A.size() || j == B.size())
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    int ans=0;
    if(A[i]==B[j])
        ans=1+Sub_Sequence_DP(dp,A,B,i+1,j+1);

    else
        ans=max(Sub_Sequence_DP(dp,A,B,i+1,j),Sub_Sequence_DP(dp,A,B,i,j+1));

dp[i][j]=ans;
return dp[i][j];
}

int main() {
    string A = "abcd";
    string B = "abcd";
    // cout<< "Longest Common Sub-Sequence: " << Sub_Sequence_recursion(A,B,0,0) << endl<< endl;
    vector<vector<int>> dp (A.size(), vector<int>(B.size(),-1));
    cout<< "Longest Common Sub-Sequence: " << Sub_Sequence_DP(dp,A,B,0,0) << endl<< endl;

}
