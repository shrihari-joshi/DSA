#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
public:
    int n;
    vector<int> segtree;
    vector<int> lazy;
    SegmentTree(vector<int> &arr)
    {
        n = arr.size();
        segtree.resize(4 * n);
        lazy.resize(4 * n, 0);
    }
    void build(int node, int l, int r, vector<int> &arr)
    {
        if (l == r)
        {
            segtree[node] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node + 1, l, mid, arr);
        build(2 * node + 2, mid + 1, r, arr);
        segtree[node] = max(segtree[2 * node + 1], segtree[2 * node + 2]);
        // this will keep changing acc to max, min or sum and currently it is MAX
    }
    int query(int ind, int l, int r, int qstart, int qend)
    {
        if (qstart > r || qend < l) // no match
            return -1;
        if (qstart <= l && r <= qend) // partial overlap
            return segtree[ind];
        int mid = (l + r) / 2;
        int left = query(2 * ind + 1, l, mid, qstart, qend);
        int right = query(2 * ind + 2, mid + 1, r, qstart, qend);
        return max(left, right);
    }
    void update(int ind, int l, int r, int index, int val)
    {
        if (l == r)
        {
            tree[ind] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (index <= mid)
            update(2 * ind + 1, l, mid, index, val);
        else
            update(2 * ind + 2, mid + 1, r, index, val);

        tree[ind] = tree[2 * ind + 1] + tree[2 * ind + 2];
    }
};

int main()
{
    vector<int> arr = {3, 6, 4, 9, 3, 2, 7};
    int n = arr.size();
    SegmentTree st(arr);
    st.build(0, 0, n - 1, arr);
    cout << st.query(0, 0, n - 1, 0, 2);
}