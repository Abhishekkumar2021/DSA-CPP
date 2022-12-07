#include<bits/stdc++.h>
using namespace std;
int f(int n, int m, int row,int col,vector<char> path){
	if(row==n && col==m){
		for(auto c : path)cout<<c;
		cout<<"\n";
		return 1;
	}
	if(row>n || col>m) return 0;

    path.push_back('R');
	int right = f(n,m,row,col+1,path);
	path.pop_back();

	path.push_back('D');
	int down = f(n,m,row+1,col,path);
	

	return right+down;

}
int main(){
	vector<char> path;
	cout<<"\nNumber of paths = "<<f(3,3,1,1,path);
	 
}