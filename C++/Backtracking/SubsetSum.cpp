#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(const vector<int> &v) {
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i != v.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

void findCombinations(int ind, int target, const vector<int> &data, vector<vector<int>> &ans, vector<int> &temp) {
   if(target == 0)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<data.size();i++)
        {
            if(data[i] > target)
                break;
            if(i > ind && data[i] == data[i-1])
                continue; //to exclude repeated pairs of solution
            
            temp.push_back(data[i]);
            findCombinations(i+1, target-data[i], data, ans, temp);
            temp.pop_back();
        }
}

vector<vector<int>> combinationSum(vector<int> &data, int target) {
    vector<vector<int>> ans;
    vector<int> temp;
    sort(data.begin(), data.end());
    findCombinations(0, target, data, ans, temp);
    return ans;
}

int main() {
    vector<int> data = {1,1,1,2};
    int target = 3;
    vector<vector<int>> ans = combinationSum(data, target);
    cout << "Combinations that sum up to " << target << ":" << endl;
    if (ans.empty()) {
        cout << "No combinations found." << endl;
    } else {
        for (int i = 0; i < ans.size(); i++) {
            printVector(ans[i]);
        }
    }
    return 0;
}
