#include<bits/stdc++.h>
using namespace std;
void prob_generator(string s, int n, int m)
{
 unordered_map<char, int> rec;
        rec['A'] = 0;
        rec['B'] = 0;
        rec['C'] = 0;
        rec['D'] = 0;
        rec['E'] = 0;
        rec['F'] = 0;
        rec['G'] = 0;
        for(int i=0;i<s.size();i++)
            rec[s[i]]++;
        int ans=0;
        for(auto entry : rec)
        {
            if(entry.second < m)
                ans += m-entry.second; 
        }
        cout<<ans;
}
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;
        int m;
        cin>>m;
        string s;
        cin>>s;
        prob_generator(s,n,m);
    }
        return 0;
}
