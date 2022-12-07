#include<bits/stdc++.h>
using namespace std;

void f(int idx, string &s, string sub){
	if(idx==s.size()-1){
		cout<<sub<<"\n";
		return;
	}

	//consider adding
	f(idx+1,s,sub+s[idx]);

	//not adding
	f(idx+1,s,sub);

}

int main(){
	string s;
	cin>>s;
	string sub = "";
	f(0,s);
}