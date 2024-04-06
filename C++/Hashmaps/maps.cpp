#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main()
{
    string s = "egg";
    string t = "abb";

   unordered_map<char, int> s_map, t_map;
        for (auto& c : s) {
            if (s_map.count(c) != 0) continue;
            s_map[c] = s_map.size();
        }
        for (auto& c : t) {
            if (t_map.count(c) != 0) continue;
            t_map[c] = t_map.size();
        }


        for (int i = 0; i < s.size(); i++) {
            if (s_map[s[i]] != t_map[t[i]]) 
            {
            cout << "False";
            return 0;
            }
        }
        cout << "True";
        return 1;
}