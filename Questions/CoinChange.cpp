 #include<bits/stdc++.h>
long long  f(int idx,int target, int*d,vector<vector<long>> &dp){
    //base case
    if(idx==0){
        if(target%d[idx]==0) return 1;
        else return 0;
    }
    if(dp[idx][target]!=-1) return dp[idx][target];
    // do all stuff
    
    long not_pick = f(idx-1,target,d,dp);
    long pick = 0;
    if(target>=d[idx]) pick = f(idx,target-d[idx],d,dp);
   
    // return count
    return dp[idx][target] = pick+not_pick;
}
long countWaysToMakeChange(int *d, int n, int value)
{
    //Write your code here
    vector<vector<long>> dp(n,vector<long>(value+1,-1));
    return f(n-1,value,d,dp);
}