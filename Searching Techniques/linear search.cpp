#include<bits/stdc++.h>
using namespace std; 
// int linearsearch(int arr[],int size,int x){
//     if(size==0)
//     	return -1;
//     if(arr[0]==x)
//     	return 0;
//     int ans = linearsearch(arr+1,size-1,x);
//     if(ans==-1)
//     	return -1;
//     else
//     	return ans+1;
// }
int main(){
	#ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
     #endif
       int x,element;
       cin>>x>>element;
     int a[x];
     for(int i=0;i<x;i++)
     	cin>>a[i];
     // cout<<linearsearch(a,x,element)<<endl;
     int temp=-1;
     for(int i=0;i<x;i++){
     	if(a[i]==element){
          temp=i;
          break;
        }
     }
     cout<<temp;
 }
