#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

void p(vector<int> &v){
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<" ";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	vi arr(n);
	vi f(1e6+1,0);
	for(int i=0; i<n; i++){
		cin>>arr[i];
		f[arr[i]]++;
	}
	map<int, int> m;
	for(int i=1; i<=1e6; i++){
		m[f[i]]+=i;
	}
	vi sum(1e6+1);
	sum[0]=0;
	for(int i=1; i<=1e6; i++){
		sum[i]+=sum[i-1]+m[i];
	}
	int q;
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		cout<<sum[r]-sum[l-1]<<endl;
	}
	return 0;
}
