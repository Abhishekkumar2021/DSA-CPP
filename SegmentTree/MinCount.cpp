#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    int count;
    Node(){
        val = INT_MAX;
        count = 0;
    }
    Node(int v, int c){
        val = v;
        count = c;
    }
};

class SegmentTree
{
    vector<Node> tree;
    vector<int> arr;
    int n;

    // Build the tree
    void build(int start, int end, int node)
    {
        if (start == end)
        {
            tree[node].val = arr[start];
            tree[node].count = 1;
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2 * node + 1);
        build(mid + 1, end, 2 * node + 2);
        
        // 3 cases:
        // 1. Both left and right are equal
        // 2. Left is smaller than right
        // 3. Right is smaller than left
        Node left = tree[2*node + 1];
        Node right = tree[2*node + 2];
        if(left.val == right.val){
            tree[node].val = left.val;
            tree[node].count = left.count + right.count;
        }
        else if(left.val < right.val){
            tree[node].val = left.val;
            tree[node].count = left.count;
        }
        else{
            tree[node].val = right.val;
            tree[node].count = right.count;
        }
    }
    Node query(int start, int end, int node, int l, int r)
    {
        // No overlap
        if (start > r || end < l)
        {
            return Node();
        }

        // Complete overlap
        if (start >= l && end <= r)
        {
            return tree[node];
        }

        // Partial overlap
        int mid = (start + end) / 2;
        Node left = query(start, mid, 2 * node + 1, l, r);
        Node right = query(mid + 1, end, 2 * node + 2, l, r);
        Node ans;
        if(left.val == right.val){
            ans.val = left.val;
            ans.count = left.count + right.count;
        }
        else if(left.val < right.val){
            ans.val = left.val;
            ans.count = left.count;
        }
        else{
            ans.val = right.val;
            ans.count = right.count;
        }
        return ans;
    }
    void update(int start, int end, int node, int index, int val)
    {
        if (start == end)
        {
            tree[node].val = val;
            tree[node].count = 1;
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
        Node left = tree[2*node + 1];
        Node right = tree[2*node + 2];
        if(left.val == right.val){
            tree[node].val = left.val;
            tree[node].count = left.count + right.count;
        }
        else if(left.val < right.val){
            tree[node].val = left.val;
            tree[node].count = left.count;
        }
        else{
            tree[node].val = right.val;
            tree[node].count = right.count;
        }
    }

public:
    SegmentTree(int n)
    {
        this->n = n;
        tree.resize(4 * n, Node());
    }
    void update(int index, int val)
    {
        update(0, n - 1, 0, index, val);
    }
    Node query(int l, int r)
    {
        return query(0, n - 1, 0, l, r);
    }
    void build(vector<int> &arr){
        n = arr.size();
        this->arr = arr;
        tree.resize(4*n, Node());
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
            Node ans = t.query(l, r - 1);
            cout << ans.val << " " << ans.count << "\n";
        }
    }
}