#include<iostream>
#include<vector>
using namespace std;

// Using Kadane's Algorithm again

int main()
{
    vector<int> nums = {2,3,-2,4};
    int maxproduct = INT32_MIN;
        int current=1;

        for(int i=0;i<nums.size();i++)
        {
          current*=nums[i];
          maxproduct=max(current,maxproduct);
          if(current==0)
           current=1;
        }
        current=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
          current*=nums[i];

          maxproduct=max(current,maxproduct);
          if(current==0)
           current=1;
        }
        cout<<"Maximum SubArray Product: "<<maxproduct<<endl;
        return maxproduct;
}