#include<bits/stdc++.h>
using namespace std; 
int max(int arr[], int size){
   if(size==0) 
   	return -1;
   if(size==1) 
   	return arr[0];
   int ans = max(arr+1,size-1);
   if(arr[0]>=ans)
   	return arr[0];
   else 
   	return ans;

}
int main(){
	#ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
     #endif
       int x;
       cin>>x;
     int a[x];
     for(int i=0;i<x;i++)
     	cin>>a[i];
     cout<<"Max element = "<<max(a,x)<<endl;
     // int max=0;
     // for(int i=0;i<x;i++){
     // 	if(a[i]>max)
     // 		max=a[i];
     // }
     //  cout<<"Max element = "<<max;	
 }
 #include<bits/stdc++.h>
 using namespace std;
 int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0; i<n; i++)
    cin>>arr[i];

  for(int i=n-1; i>=0; i--)
    cout<<arr[i]<<" ";

 }
