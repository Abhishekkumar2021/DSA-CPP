#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	string s;
	cin>>s;
	int n = s.length();
	vector<int> indexOfW;
	for(int i=0; i<n; i++)
		if(s[i]=='W')
			indexOfW.push_back(i);
	if(indexOfW.size()==0 || indexOfW.size()==n){
		cout<<0<<"\n";
		return 0;
	}
	int mid = (indexOfW.size()-1)/2;
	int ans = 0;
	

}