#include<iostream>
#include<map>
#include<vector>
#include<unordered_map>
using namespace std;

int main()
{
        vector<int> nums = {0,1,1,1,2,2,3,3,3};
        vector<int> ansvec;

        unordered_map<int, int> data;
        for(int i=0;i<nums.size();i++)
        {
            data[nums[i]] += 1;
        }
        int n=nums.size() / 3;
        for (auto entry : data)
        {
            if( entry.second > n)
               ansvec.push_back(entry.first);
        }
        // return ansvec;
        
        for (int i=0;i<ansvec.size();i++)
        {
            cout<<"hi";
            cout << ansvec[i] << endl;
        }       
        cout<<"helo"; 
        return 0;
}