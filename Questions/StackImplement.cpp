#include<bits/stdc++.h>
using namespace std;

const int m = 998244353;

int f(vector<int> A, vector<int> B){
    int ans = 0;
    for(int i=1; i<=A.size(); i++){
        for(int j=1; j<=B.size(); j++){
            ans+=(A[i-1]*B[j-1]*(i+j))%m;
        }
    }
    return (ans+m)%m;
}
vector<int> array_queries (int N, int M, vector<int> A, vector<int> B, int Q, vector<vector<int> > queries) {
   // Write your code here
   vector<int> ans;
   int initial = f(A,B);
   int temp=initial; 
   ans.push_back(initial);
   for(int i=0; i<Q; i++){
       int a = queries[i][0];
       int b = queries[i][1];
       int c = queries[i][2];
       switch(a){
           case 1:{
               for(int j=0;j<M;j++){
                   temp-=A[b-1]*B[j]*(b+1+j);
               }
               for(int j=0;j<N;j++){
                   temp-=B[c-1]*A[j]*(c+1+j);
               }
               swap(A[b-1],B[c-1]);
               for(int j=0;j<M;j++){
                   temp+=A[b-1]*B[j]*(b+1+j);
               }
               for(int j=0;j<N;j++){
                   temp+=B[c-1]*A[j]*(c+1+j);
               }
               ans.push_back(temp);
               swap(A[b-1],B[c-1]);
               temp=initial;
           }
           break;
           case 2:{
           	   for(int j=0;j<M;j++){
                   temp-=A[b-1]*B[j]*(b+1+j);
               }
               for(int j=0;j<M;j++){
                   temp-=A[c-1]*B[j]*(c+1+j);
               }
               swap(A[b-1],A[c-1]);
               for(int j=0;j<M;j++){
                   temp+=A[b-1]*B[j]*(b+1+j);
               }
               for(int j=0;j<M;j++){
                   temp+=A[c-1]*B[j]*(c+1+j);
               }
               ans.push_back(temp);
               swap(A[b-1],A[c-1]);
               temp=initial; 
           }
           break;
           case 3:{
               for(int j=0;j<N;j++){
                   temp-=B[b-1]*A[j]*(b+1+j);
                   temp-=B[c-1]*A[j]*(c+1+j);
               }
               swap(B[b-1],B[c-1]);
               for(int j=0;j<N;j++){
                   temp+=B[b-1]*A[j]*(b+1+j);
                   temp+=B[c-1]*A[j]*(c+1+j);
               }
               ans.push_back(temp);
               swap(B[b-1],B[c-1]);
               temp=initial; 
           }
           break;
       }
       
   }
   return ans;
   
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        int M;
        cin >> M;
        vector<int> A(N);
        for(int i_A = 0; i_A < N; i_A++)
        {
        	cin >> A[i_A];
        }
        vector<int> B(M);
        for(int i_B = 0; i_B < M; i_B++)
        {
        	cin >> B[i_B];
        }
        int Q;
        cin >> Q;
        vector<vector<int> > queries(Q, vector<int>(3));
        for (int i_queries = 0; i_queries < Q; i_queries++)
        {
        	for(int j_queries = 0; j_queries < 3; j_queries++)
        	{
        		cin >> queries[i_queries][j_queries];
        	}
        }

        vector<int> out_;
        out_ = array_queries(N, M, A, B, Q, queries);
        cout << out_[0];
        for(int i_out_ = 1; i_out_ < out_.size(); i_out_++)
        {
        	cout << " " << out_[i_out_];
        }
        cout << "\n";
    }
}