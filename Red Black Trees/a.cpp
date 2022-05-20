#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int x,y,a = 0;
        cin>>x>>y;
        cin.ignore();
        string s;
        getline(cin,s);
        int m = 0 ;
        int count=0;
        for (int i = 0; i < 30; i++)
        {
           
            if (s[i]=='1' )
            {
               a += x ;
               count++;
               m = max(m,count);
            }
            else {
                count = 0;
            }
        }
        cout<<(a+(m*y))<<endl;        
    }
    
    return 0 ;
}