#include<bits/stdc++.h>
using namespace std;

// This takes the O(N^2) time and O(N^2) space
string f(string &s){
    int n = s.length();
    vector<vector<int>> dp(n,vector<int>(n));
    int maxi = INT_MIN;
    int st;
    for(int l = 1; l<=n; l++){
        for(int i=0,j=i + l -1; j<n; j++,i++){
            if(l==1) dp[i][j] = 1;
            else if(l==2) dp[i][j]=(s[i]==s[j])?2:0;
            else dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]>0)?2 + dp[i+1][j-1]:0;
            if(maxi<dp[i][j]){
                st = i;
                maxi = dp[i][j];
            }
        }
    }
    for(auto r:dp){
       for(auto e:r) cout<<e<<" ";
       cout<<"\n"; 
    } 
    return s.substr(st,maxi);
}
// This takes the O(N^2) time and O(1) space

string expand(string str, int low, int high)
{    while (low >= 0 && high < str.length() && (str[low] == str[high])) low--, high++;        
    return str.substr(low + 1, high - low - 1);
}
string LPS(string &str)
{
    // base case
    if (str.length() == 0) {
        return str;
    }
 
    string max_str = "", curr_str;
    int max_length = 0, curr_length;

    for (int i = 0; i < str.length(); i++)
    {
        curr_str = expand(str, i, i);
        curr_length = curr_str.length();
        if (curr_length > max_length)
        {
            max_length = curr_length;
            max_str = curr_str;
        }
        curr_str = expand(str, i, i + 1);
        curr_length = curr_str.length();
        if (curr_length > max_length)
        {
            max_length = curr_length;
            max_str = curr_str;
        }
    }
    return max_str;
}

int main(){ 
    string s;
    cin>>s;
    int size = s.size();

    string ans = LPS(s);
    cout<<ans<<"\n";
    
}