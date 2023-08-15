#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
    vector<int> tree;
    vector<int> arr;
    int n;

    // Build the tree
    void build(int start, int end, int node)
    {
        if (start == end)
        {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2 * node + 1);
        build(mid + 1, end, 2 * node + 2);
        tree[node] = min(tree[2 * node + 1] , tree[2 * node + 2]);
    }
    int query(int start, int end, int node, int l, int r)
    {
        // No overlap
        if (start > r || end < l)
        {
            return INT_MAX;
        }

        // Complete overlap
        if (start >= l && end <= r)
        {
            return tree[node];
        }

        // Partial overlap
        int mid = (start + end) / 2;
        int left = query(start, mid, 2 * node + 1, l, r);
        int right = query(mid + 1, end, 2 * node + 2, l, r);
        return min(left , right);
    }
    void update(int start, int end, int node, int index, int val)
    {
        if (start == end)
        {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (index <= mid)
        {
            update(start, mid, 2 * node + 1, index, val);
        }
        else
        {
            update(mid + 1, end, 2 * node + 2, index, val);
        }
        tree[node] = min(tree[2 * node + 1] , tree[2 * node + 2]);
    }

public:
    SegmentTree(int n)
    {
        this->n = n;
        tree.resize(4 * n);
    }
    void update(int index, int val)
    {
        update(0, n - 1, 0, index, val);
    }
    int query(int l, int r)
    {
        return query(0, n - 1, 0, l, r);
    }
    void build(vector<int> &arr){
        n = arr.size();
        tree.resize(4*n);
        this->arr = arr;
        build(0, n-1, 0);
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    SegmentTree t(n);
    t.build(arr);
    while (m--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int idx, value;
            cin >> idx >> value;
            t.update(idx, value);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << t.query(l, r - 1) << endl;
        }
    }
}