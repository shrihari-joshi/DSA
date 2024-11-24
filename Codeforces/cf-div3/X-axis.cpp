#include<bits/stdc++.h>
using namespace std;

int main(){
    int tc;
    cin >> tc;
    while(tc--)
    {
        int x1,x2,x3;
        cin>>x1>>x2>>x3;
        if(x1==x2 && x2 == x3)
            return 0;
        if(x1==x2)
            return abs(x3-x2);
        else if(x1==x3)
            return abs(x3-x2);
        else if(x2==x3)
            return abs(x1-x2);
        else
        {
            int t1 = max(x1,x2);
            int maxi = max(t1,x3);
            int t2 = min(x1,x2);
            int mini = min(t2,x3);
            int arr[3] = {x1, x2, x3};
            int mid=0;
            for(int i=0;i<3;i++)
            {
                if(arr[i] != maxi && arr[i] != mini)
                    mid = arr[i];
            }
            cout<< (maxi-mid)+(mid-mini);
            
        }
    }
    return 0;
}   