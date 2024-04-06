#include<iostream>
#include<vector>
using namespace std;

// Using Kadane's Algorithm i.e. if negative rollback to start again (here 0 is start)

int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int cur_sum=0,max=INT32_MIN;
        for(int i=0;i<nums.size();i++)
        {
            cur_sum += nums[i];
            if(cur_sum > max)
                max = cur_sum;
            if(cur_sum < 0)
                cur_sum = 0;
        }
        cout<<"Maximum SubArray: "<<max<<endl;
        return max;
}