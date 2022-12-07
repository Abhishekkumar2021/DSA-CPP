#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	string output = "";
	int in = 0;
	for(int i=0; i<s.length(); i++){
		if(s[i]=='{' || s[i]=='['){
			output+=s[i];
			output+='\n';
			in++;
			for(int j=0; j<in; j++)
				output+='\t';
		}else if(s[i]==','){
			output+=s[i];
			output+='\n';
			for(int j=0; j<in; j++)
				output+='\t';
		}else if(s[i]==']' || s[i]=='}'){
			output+='\n';
			in--;
			for(int j=0; j<in; j++)
				output+='\t';	
			output+=s[i];
		}else if(s[i]==':' && (s[i+1]=='{' || s[i+1]=='[')){
			output+=s[i];
			output+='\n';
			for(int j=0; j<in; j++)
				output+='\t';

		}else{
			output+=s[i];
		}
	}
	// vector<string> v;
	// string temp = "";
	// for(int i=0; i<output.size(); i++){
	// 	if(output[i]=='\n' && i!=output.size()-1){
	// 		v.push_back(temp);
	// 		temp = "";
	// 		continue;
	// 	}
	// 	temp+=output[i];
	// }
	// v.push_back(temp);
	// for(auto e:v) cout<<e<<"\n";
	cout<<output<<"\n";
}