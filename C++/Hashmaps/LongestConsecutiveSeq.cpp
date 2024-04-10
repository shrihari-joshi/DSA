#include<iostream>
#include<map>
#include<vector>
#include<unordered_map>
using namespace std;

int main()
{
        vector<int> nums = {0,1,2,3,4,99};
            unordered_map<int, int> rec;
        for(int i=0;i<nums.size();i++)
        {
            rec[nums[i]]++;
        }
        // int ans=0;max=0;
        for(auto it = rec.begin(); it != rec.end(); ++it)
        {
            cout << it->first  << " ";
            // cout<< rec.find((it->first)+1);
            
        }
        
        return 0;
}