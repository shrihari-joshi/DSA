#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> computePrefixFunction(const string& pattern) {
    int m = pattern.size();
    int q=0;
    vector<int> temp(m,0);
    for(int i=1;i<m;i++)
    {
        while(q>0 && pattern[q] != pattern[i])
            q = temp[q-1];
        if(pattern[q] == pattern[i])
            q++;
        temp[i] = q;
    }
    return temp;
}

void kmpSearch(const string& text, const string& pattern) {
    int m = pattern.size();
    int n = text.size();
    vector<int> prefix = computePrefixFunction(pattern);
    int q=0;
    for(int i=0;i<n;i++)
    {
        while(q>0 && pattern[q] != text[i])
            q = prefix[q-1];
        if(pattern[q] == text[i])
            q++;
        if(q==m){
            cout<< "found at " << i - m + 1 << endl ;
        }
    }

}

int main() {
    string text = "lalitlalitlalitlalitlalitlalitlalit";
    string pattern = "lalit";
    kmpSearch(text, pattern);
    return 0;
}