#include<bits/stdc++.h>
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
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
    int query(int start, int end, int node, int k)
    {
        // base cases
        if(start == end){
            return start;
        }
        int mid = (start+end)/2;
        // If right child having less than or k ones that that means we have to go to right child
        if(k < tree[2*node+2]){
            return query(mid+1, end, 2*node+2, k);
        }
        // If right child having more than k ones that that means we have to go to left child
        else{
            return query(start, mid, 2*node+1, k-tree[2*node+2]);
        }

    }
    void update(int start, int end, int node, int index)
    {
        if (start == end)
        {
            // Marking it unvisited
            tree[node] = 0;
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
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

public:
    void update(int index)
    {
        update(0, n - 1, 0, index);
    }
    int query(int k)
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

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<int> vis(n, 1);
    vector<int> ans(n);
    SegmentTree st;
    st.build(vis);
    for(int i=n-1; i>=0; i--){
        int index = st.query(arr[i]);
        ans[i] = index+1;
        st.update(index);
    }
    for(int i=0; i<n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}