#include<iostream>
using namespace std;
int main()
{
    string s;
    int cnt = 1;  
    cin>>s;
    int i=0;
    for(int j=1;j<=s.length();j++)
    {
        if(s[j]==s[i])
        {
            int k=j-i;
            int m = j+k;
            for(j;j<m;j++,i++)
            {
                if(s[i]==s[j])
                 continue;
                else 
                break;
            }
            if(j==m){
                cnt++;
                j--;
            }
            else 
            i = 0;
            
        }
    }
    cout<<cnt;
    return 0;
}