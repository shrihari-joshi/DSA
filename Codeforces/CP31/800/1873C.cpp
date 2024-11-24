#include <bits/stdc++.h>
using namespace std;

int targetPractice(vector<vector<char>> &adj)
{
    int score = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (adj[i][j] == 'X')
            {
                if (i == 0 || j == 0 || i == 9 || j == 9)
                    score += 1;
                else if (i == 1 || j == 1 || i == 8 || j == 8)
                    score += 2;
                else if (i == 2 || j == 2 || i == 7 || j == 7)
                    score += 3;
                else if (i == 3 || j == 3 || i == 6 || j == 6)
                    score += 4;
                else if (i == 4 || j == 4 || i == 5 || j == 5)
                    score += 5;
            }
        }
    }
    return score;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        vector<vector<char>> adj(10, vector<char>(10));
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                cin >> adj[i][j];
            }
        }
        cout << targetPractice(adj) << endl;
    }
    return 0;
}