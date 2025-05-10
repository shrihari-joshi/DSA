#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    unordered_set<string> set(wordList.begin(), wordList.end());
    set.erase(beginWord);

    while (!q.empty())
    {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        if (word == endWord)
            return steps;
        for (int i = 0; i < word.size(); i++)
        {
            char og = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (set.find(word) != set.end())
                {
                    set.erase(word);
                    q.push({word, steps + 1});
                }
            }
            word[i] = og;
        }
    }
    return 0;
}

int main()
{
    string start = "hit", end = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log"};
    int ans = ladderLength(start, end, wordList);
    cout << "Ans: " << ans << endl;
    return 0;
}