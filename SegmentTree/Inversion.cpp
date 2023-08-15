#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
    vector<long long> tree;
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
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
    long long query(int start, int end, int node, int l, int r)
    {
        // No overlap
        if (start > r || end < l)
        {
            return 0;
        }

        // Complete overlap
        if (start >= l && end <= r)
        {
            return tree[node];
        }

        // Partial overlap
        int mid = (start + end) / 2;
        long long left = query(start, mid, 2 * node + 1, l, r);
        long long right = query(mid + 1, end, 2 * node + 2, l, r);
        return left + right;
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
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

public:
    void update(int index, int val)
    {
        update(0, n - 1, 0, index, val);
    }
    long long query(int l, int r)
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
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> ans;
    vector<int> vis(n+1, 0);
    SegmentTree st;
    st.build(vis);
    for(int i=0; i<n; i++){
        int count = st.query(arr[i], n);
        ans.push_back(count);
        st.update(arr[i], 1);
    }
    for(int i=0; i<n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}