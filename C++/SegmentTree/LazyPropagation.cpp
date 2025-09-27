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
        segtree[node] = segtree[2 * node + 1] + segtree[2 * node + 2];
        // this will keep changing acc to max or min, currently it is sum
    }
    int query(int ind, int l, int r, int qstart, int qend)
    {
        if (lazy[ind] != 0)
        {
            segtree[ind] += (r - l + 1) * lazy[ind];
            if (l != r)
            {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        if (qstart > r || qend < l) // no match
            return 0;
        if (qstart <= l && r <= qend) // complete overlap
            return segtree[ind];
        int mid = (l + r) / 2;
        int left = query(2 * ind + 1, l, mid, qstart, qend);
        int right = query(2 * ind + 2, mid + 1, r, qstart, qend);
        return left + right;
    }

    void update(int ind, int l, int r, int qstart, int qend, int val)
    {
        if (lazy[ind] != 0)
        {
            segtree[ind] += (r - l + 1) * lazy[ind];
            if (l != r)
            {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        if (qend < l || qstart > r)
            return;                   // no match
        if (qstart <= l && qend >= r) // complete overlap
        {
            segtree[ind] += (r - l + 1) * val;
            if (l != r)
            {
                lazy[2 * ind + 1] += val;
                lazy[2 * ind + 2] += val;
            }
            return;
        }
        int mid = (l + r) / 2;
        update(2 * ind + 1, l, mid, qstart, qend, val);
        update(2 * ind + 2, mid + 1, r, qstart, qend, val);
        segtree[ind] = segtree[2 * ind + 1] + segtree[2 * ind + 2];
    }
};

int main()
{
    vector<int> arr = {3, 6, 4, 9, 3, 2, 7};
    int n = arr.size();
    SegmentTree st(arr);
    st.build(0, 0, n - 1, arr);
    cout << st.query(0, 0, n - 1, 0, 3) << endl;
    st.update(0, 0, n - 1, 0, 2, 4);
    cout << st.query(0, 0, n - 1, 0, 3) << endl;
}