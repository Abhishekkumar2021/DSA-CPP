#include<bits/stdc++.h>
using namespace std;

int sum(int arr[],int n){
  if(n=0)
  return 0;
  int ans = sum(arr+1,n-1);
  return ans+arr[0];
}
int main(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  int n;
  cin>>n;
  int array[n];
  for(int i=0; i<n; i++)
  cin>>array[i];
  cout<<sum(array,n);
}
