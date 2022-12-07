#include<bits/stdc++.h>
using namespace std;

string solution(string &s){
	int n = s.length();
	string ans = "";
	for(int i=0; i<n;){
		if(s[i]=='A' && i+1<n && s[i+1]=='B'){
			i+=2;
		} 
		else if(s[i]=='B' && i+i<n && s[i+1]=='A'){
			i+=2;
		} 
		else if(s[i]=='C' && i+i<n && s[i+1]=='D'){
			i+=2;
		} 
		else if(s[i]=='D' && i+i<n && s[i+1]=='C'){
			i+=2;
		} 
		else{
			ans+=s[i];
			i++;
		} 
	}
	return ans;
}

void solve(){
	string s;
	cin>>s;
	string ans = solution(s);
	cout<<ans<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}