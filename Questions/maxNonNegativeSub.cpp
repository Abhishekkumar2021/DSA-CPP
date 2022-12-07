#include <bits/stdc++.h>
using namespace std;

vector<int> maxset(vector<int> &A)
{
    vector<int> result;
    int n = A.size();
    int s = -1, l = -1,si = -1,ei = -1;
    long sum = -1 ,temp= -1; 
    for (int i = 1; i < n; i++)
    {
        if (A[i] < 0)
        {
            temp = -1;
            s = -1;
        }
        else
        {
            if(temp==-1){
                si = i;
                temp=A[i];
            }else{
                temp+=A[i];
            }
            if(temp>sum){
                l = i-s+1;
                si = s;
                ei = i;
                sum = temp;
            }
            if(temp==sum && i-s+1>l){
                l=i -s+1;
                si= s;
                ei = i;
            }
           
        }
    }
    if(si==-1)
    return result;
    for(int i=0; i<l; i++){
        result.push_back(A[si+i]);
    }
    return result;
}
int main(){
    vector<int> A = {2,3,-2,1,1,3,-2,1,3,1,-3,4,2};
    vector<int> result = maxset(A);
    for(auto e: result){
        cout<<e<<" ";
    }
}
