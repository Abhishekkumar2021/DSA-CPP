#include<bits/stdc++.h>
using namespace std;

int underBarrier(int barrier,vector<int> arr){
     int cnt = 1;
     int curr = 0;
     for(int i=0; i<arr.size(); i++){
          if(curr+arr[i]<=barrier) curr+=arr[i];
          else {
               cnt++;
               curr = arr[i];
          }
     }
     return cnt;
}
int main(){
	int n,x;
	cin>>n>>x;
	vector<int> arr(n);
     int high = 0;
     for(int i=0; i<n; i++){
          cin>>arr[i];
          high+=arr[i];
     }
     int low = *max_element(arr.begin(),arr.end()); 

     while(low<=high){
          cout<<"Low = "<<low<<", high = "<<high<<"\n";

          int mid = (low+high)>>1;
          int stu = underBarrier(mid,arr);
          if(stu>=x) low = mid+1;
          else if(stu<x) high = mid-1;
          cout<<"Student passed: "<<stu<<", barrier = "<<mid<<"\n";
     }


}