#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int minimumArea(vector<vector<int>> &grid)
{
    int ans = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<int> rowcount;
    vector<int> colcount(m);
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        int row = 0;
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                row++;
                total++;
                colcount[j]++;
            }
        }
        rowcount.push_back(row);
    }
    for (int i = 0; i < n; i++)
    {
        cout << rowcount[i] << " ";
    }
    cout << endl;
    if (total == 1)
        return 1;
    if (n == 1 && rowcount[0] != 0)
        return m;
    for (int j = 0; j < m; j++)
    {
        if (colcount[j] == total)
            return n;
    }
    int start = -1, end = -1;
    int i = 0, j = n - 1;
    while (i < n && j >= 0)
    {
        if (rowcount[i] != 0 && start == -1)
        {
            start = i;
        }
        if (rowcount[j] != 0 && end == -1)
        {
            end = j;
        }
        i++;
        j--;
    }
    cout << start << " " << end << endl;
    ans = (end - start + 1) * m;
    return ans;
}

int main()
{
    vector<vector<int>> grid = {{0, 1, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}, {1, 0, 0, 0}, {0, 0, 0, 1}};
    // vector<vector<int>> grid = {{0,0,0,1}, {0,0,0,1}, {0,0,0,1}, {0,0,0,1}, {0,0,0,1}};
    // vector<vector<int>> grid = {{0,1,0,0}, {0,0,0,1}, {0,0,1,0}};
    // vector<vector<int>> grid = {{1,1}};
    int ans = minimumArea(grid);
    cout << ans;
    return 0;
}