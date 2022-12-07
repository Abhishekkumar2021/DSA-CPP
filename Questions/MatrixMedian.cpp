#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> v(n,vector<int>(m));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>v[i][j];
		}
	}
	int num_req = (n*m+1)/2;
	int low = 0,high = 10;
	while(high>=low){
		int sum = 0;
		int mid = (low+high)/2;
		for(int i=0; i<n; i++) sum += upper_bound(v[i].begin(),v[i].end(),mid) - v[i].begin();
		
		if(sum==num_req){
			return mid;
		}
		else if(sum<num_req) low = mid;
		else high = mid;
	
	}

}