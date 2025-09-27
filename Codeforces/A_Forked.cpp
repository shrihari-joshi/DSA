#include <bits/stdc++.h>
using namespace std;

int func(int a, int b, int xk, int yk, int xq, int yq)
{
    if (xk == xq)
    {
        int diff = abs(yk - yq);
        if (2 * a == diff || 2 * b == diff)
            return 2;
        else
            return 0;
    }
    if (yk == yq)
    {
        int diff = abs(xk - xq);
        if (2 * a == diff || 2 * b == diff)
            return 2;
        else
            return 0;
    }
    vector<pair<int, int>> offsets = {
        {-a, -b}, {-a, +b}, {+a, -b}, {+a, +b}, {-b, -a}, {-b, +a}, {+b, -a}, {+b, +a}};

    map<pair<int, int>, int> mp;
    if (a == b)
        offsets.resize(4);
    for (auto it : offsets)
    {
        int nx = xq + it.first;
        int ny = yq + it.second;
        mp[{nx, ny}]++;
    }

    for (auto it : offsets)
    {
        int nx = xk + it.first;
        int ny = yk + it.second;
        mp[{nx, ny}]++;
    }

    int cnt = 0;
    for (auto it : mp)
    {
        if (it.second == 2)
            cnt++;
    }
    return cnt;
}
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int a, b;
        cin >> a >> b;
        int xk, yk;
        cin >> xk >> yk;
        int xq, yq;
        cin >> xq >> yq;
        cout << func(a, b, xk, yk, xq, yq) << endl;
    }
    return 0;
}