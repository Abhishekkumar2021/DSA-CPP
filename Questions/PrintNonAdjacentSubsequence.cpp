#include<bits/stdc++.h>
using namespace std;
void f(string s,string sub,int idx){
	if(idx<0){
		cout<<sub<<"\n";
		return;
	} 
	f(s,sub+s[idx],idx-2);
	f(s,sub,idx-1);
}


int main(){
	string s;
	cin>>s;
	string sub = "";
	f(s,sub,s.size()-1);
}