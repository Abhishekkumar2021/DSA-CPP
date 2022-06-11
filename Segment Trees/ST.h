#include<bits/stdc++.h>
using namespace std;

class SGTree{
    vector<int>seg;
    vector<int> arr;
    void build_helper(int idx,int low,int high){
        if(low==high){
            seg[idx] = arr[low];
            return ;

        }
        int mid = (low+high)>>1;
        build_helper(2*idx+1,low,mid);
        build_helper(2*idx+2,mid+1,high);
        seg[idx] = min(seg[2*idx+1],seg[2*idx+2]);
    }
    int query_helper(int idx,int low,int high,int l,int r){
        // no overlap
        if(r<low || l>high) return INT_MAX;

        //complete overlap
        if(l<=low && r>=high) return seg[idx];

        //remains the partial overlap case
        int mid = (low+high)>>1;
        int left = query_helper(2*idx+1,low,mid,l,r);
        int right = query_helper(2*idx+2,mid+1,high,l,r);
        return min(left,right);
    }
    void update_helper(int idx,int low,int high,int x,int val){
        if(low==x){
            seg[idx] = val;
        }
        int mid = (low+high)>>1;
        if(x<=mid) update_helper(2*idx+1,low,mid,x,val);
        else update_helper(2*idx+2,mid,high,x,val);
        seg[idx] = min(seg[2*idx+1],seg[2*idx+2]);
    }
    public:
    SGTree(vector<int> &arr){
        this->arr = arr;
        seg.resize(4*arr.size()+1);
    }
    void build(){
        build_helper(0,0,arr.size()-1);
    }
    void update(int x,int val){
        arr[x] = val;
        update_helper(0,0,arr.size()-1,x,val);
    }
    int query(int l,int r){
        return query_helper(0,0,arr.size()-1,l,r);
    }

};
