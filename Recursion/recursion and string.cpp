#include<bits/stdc++.h>
using namespace std;
int arraylength(char arr[]){
  if(arr[0]=='\0')
  return 0;
  int ans = arraylength(arr+1);
  return ans+1;
}
int main(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  char str[100];
  cin>>str;
  cout<<arraylength(str);
}
