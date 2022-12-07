#include<bits/stdc++.h>
using namespace std;
int f(int idx1,int idx2, string &s1, string &s2){
	// base case
	if(idx1<0) return idx2+1;
	if(idx2<0) return idx1+1;


	//Explore all the possbility
	if(s1[idx1]==s2[idx2]){
		return 0 + f(idx1-1,idx2-1,s1,s2); 
	}else{
		/*  There are three possibility
			a) Delete the current character in s1
			b) Replace the current character in s1
			c) Insert the character in s1
		*/

		int del = 1 + f(idx1-1,idx2,s1,s2);
		int ins = 1 + f(idx1,idx2-1,s1,s2);
		int rep = 1 + f(idx1-1,idx2-1,s1,s2);
		return min(del,min(ins,rep));
	}
}

int main(){
	string s1,s2;
	cin>>s1>>s2;
	cout<<f(s1.size()-1,s2.size()-1,s1,s2);

}