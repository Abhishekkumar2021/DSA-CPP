#include<bits/stdc++.h>
using namespace std;

int getBit(int n, int i){
    return ((n>>i)&1);
}
void solve(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        bool flag = true;
        for(int i=0; i<31; i++){
            int x1 = getBit(a,i);
            int x2 = getBit(b,i);
            int x3 = getBit(c,i);
            int count = x1+x2+x3;
            if(count==0 || count==3){
                flag = false;
                break;
            }
            if(count==1){
                if(x1==1) a+=(1<<i);
                if(x2==1) b+=(1<<i);
                if(x3==1) c+=(1<<i);
            }
            if(count==2){
                if(x1==0) a+=(1<<i);
                if(x2==0) b+=(1<<i);
                if(x3==0) c+=(1<<i);
            }   
        }
	    if(flag && a==b && b==c) { cout<<"YES"<<endl; }
	    else { cout<<"NO"<<endl; }
    }

}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    solve();
}

// #include <iostream>
// using namespace std;

// int main() {
// 	// your code goes here
// 	int t;
// 	cin>>t;
// 	for(int i=0;i<t;i++)
// 	{
// 	    int a,b,c;
// 	    cin>>a>>b>>c;
// 	    long long bit;
// 	    bool flag = true;
// 	    for(int j=0;j<=30;j++)
// 	    {
// 	        if(a==b && b==c) { break; }
// 	        bit = (1<<j);
// 	        int count;
// 	        count = ((bit&a)!=0) + ((bit&b)!=0) + ((bit&c)!=0);
// 	        if(count==0 || count==3) {
// 	            flag = false;
// 	            break;
// 	        }
// 	        else if(count==1) {
// 	            if(a&bit) { a+=bit; }
// 	            else if(b&bit) { b+=bit; }
// 	            else { c+=bit; }
// 	        }
// 	        else {
// 	            if((a&bit)==0) { a+=bit; }
// 	            else if((b&bit)==0) { b+=bit; }
// 	            else { c+=bit; }
// 	        }
// 	    }
	    // if(flag && a==b && b==c) { cout<<"YES"<<endl; }
	    // else { cout<<"NO"<<endl; }
// 	}
// 	return 0;
// }