#include<bits/stdc++.h>
using namespace std;
int seats(string A) {
    int n=A.size();
    int total=0;
    int last = 0;
    int start = 0;
    int best = INT_MIN;
    int curr = 0;
    vector<int>temp;
    int mod=10000003;
    for(int i=0;i<n;i++)
    {
        if(A[i]=='x'){
            curr++;
            if(curr>best){
                best = curr;
                last = i;
                start = i - best;
            }
            temp.push_back(i);
        }else{
            curr = 0;
        }
    }
    last++;
    int m=temp.size();
    for(int i=0; i<m; i++){
        if(temp[i]<=start){
            while(A[start]!='.')
            start--;
            total+=(start-temp[i])%mod;
            A[temp[i]]= '.';
        }
        if(temp[i]>=last){
            while(A[last]!='.')
            last++;
            total+=(temp[i] - last)%mod;
            A[temp[i]]= '.';
        }
    }
    return total;
}

int main(){
    string A = "....x..xx...x..";
    cout<<seats(A);
}