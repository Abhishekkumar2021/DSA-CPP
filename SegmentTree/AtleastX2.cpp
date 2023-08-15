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
        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }
    int query(int start, int end, int node, int x, int l)
    {
        if(tree[node] < x){
            return -1;
        }
        if(end < l){
            return -1;
        }
        if (start == end)
        {
            return start;
        }
        int mid = (start + end) / 2;
        
        int left = query(start, mid, 2 * node + 1, x, l);
        if(left != -1){
            return left;
        }
        else{
            return query(mid + 1, end, 2 * node + 2, x, l);
        }
    }
    void update(int start, int end, int node, int index, int value)
    {
        if (start == end)
        {
            tree[node] = value;
            arr[index] = value;
            return;
        }
        int mid = (start + end) / 2;
        if (index <= mid)
        {
            update(start, mid, 2 * node + 1, index, value);
        }
        else
        {
            update(mid + 1, end, 2 * node + 2, index, value);
        }
        
        // Merge the children
        tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    }

public:
    SegmentTree(int n)
    {
        this->n = n;
        tree.resize(4 * n);
    }
    void update(int index, int value)
    {
        update(0, n - 1, 0, index, value);
    }
    int query(int x, int l)
    {
        return query(0, n - 1, 0, x, l);
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
            int index, value;
            cin >> index >> value;
            t.update(index, value);
        }
        else
        {
            int x, l;
            cin >> x >> l;
            int ans = t.query(x, l);
            cout << ans << "\n";
        }
    }
}