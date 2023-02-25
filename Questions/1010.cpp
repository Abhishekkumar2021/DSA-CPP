#include <bits/stdc++.h>
using namespace std;
int main(){
    int n1=0,n0=0,n=0;
    queue<int> q;
    vector<int> v1;
    while(n==1||n==0){
        cin>>n;
        if(n1+n0>3){
            q.push(n);
            q.pop();
            if(n==0){
            queue<int> q2;
            if(q.front()==1){
                q.pop();
                if(q.front()==0){
                    q.pop();
                    if(q.front()==1){
                        v1.push_back(n1+n0-2);
                        q.push(1);
                        q.push(0);
                    }
                    else{
                        while(!q.empty()){
                            q.pop();
                        }
                        q.push(1);
                        q.push(0);
                        q.push(0);
                        q.push(0);
                    }
                }
                else{
                int b1=q.front(),b2;
                q.pop();
                b2=q.front();
                q.pop();q.pop();
                q.push(1);q.push(b1);q.push(b2);q.push(0);}
            }
        }
        }
        else{
            q.push(n);
        }
        if(n==0)n0++;
        else n1++;
    }
    cout<<v1.size()<<endl<<"1->"<<n1-1<<" 0->"<<n0<<endl;
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;
}