#include<bits/stdc++.h>
using namespace std;
/*
You are at (1,1) of NxM matrix. From a point (i, j) you can only move to (i+j, j) or (i, j+i). Find the minimum number of moves to reach (N, M).
return -1 if you can't reach there.

*/

int getMin(int i, int j, int n, int m, vector<vector<int>> &dp){
    if(i == n && j == m){
        return 0;
    }
    if(i > n || j > m){
        return INT_MAX;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int right = getMin(i, j+1, n, m, dp);
    int down = getMin(i+1, j, n, m, dp);
    if(right == INT_MAX && down == INT_MAX){
        return dp[i][j] = INT_MAX;
    }
    return dp[i][j] = min(right, down) + 1;
}

int minSteps(int input1, int input2){
    vector<vector<int>> dp(input1+1, vector<int>(input2+1, -1));
    int ans = getMin(1, 1, input1, input2, dp);
    if(ans == INT_MAX){
        return -1;
    }
    return ans;
}



