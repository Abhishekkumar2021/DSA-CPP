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

        // Merge the children
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
    int query(int start, int end, int node, int k)
    {
        if (start == end)
        {
            return start;
        }
        int mid = (start + end) / 2;
        if (k < tree[2 * node + 1])
        {
            return query(start, mid, 2 * node + 1, k);
        }
        else
        {
            return query(mid + 1, end, 2 * node + 2, k - tree[2 * node + 1]);
        }
    }
    void update(int start, int end, int node, int index)
    {
        if (start == end)
        {
            tree[node] = 1 - tree[node];
            return;
        }
        int mid = (start + end) / 2;
        if (index <= mid)
        {
            update(start, mid, 2 * node + 1, index);
        }
        else
        {
            update(mid + 1, end, 2 * node + 2, index);
        }
        
        // Merge the children
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

public:
    SegmentTree(int n)
    {
        this->n = n;
        tree.resize(4 * n);
    }
    void update(int index)
    {
        update(0, n - 1, 0, index);
    }
    long long query(int k)
    {
        return query(0, n - 1, 0, k);
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
            int index;
            cin >> index;
            t.update(index);
        }
        else
        {
            int k;
            cin >> k;
            cout << t.query(k) << "\n";
        }
    }
}