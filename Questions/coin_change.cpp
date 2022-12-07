#include<bits/stdc++.h>
using namespace std;
/*
    Problem link->
        https://practice.geeksforgeeks.org/problems/coin-change2448/1
    
    Tested on GFG
    Code: https://ideone.com/9Z9Q9T
    Video: https://youtu.be/1R0_7HqNaW0
    Pseudo Code: https://youtu.be/1R0_7HqNaW0?t=100
    Example: https://youtu.be/1R0_7HqNaW0?t=200
    Complexity: https://youtu.be/1R0_7HqNaW0?t=300
    Code: https://youtu.be/1R0_7HqNaW0?t=400
    Code: https://youtu.be/1R0_7HqNaW0?t=500
    Code: https://youtu.be/1R0_7HqNaW0?t=600
    Code: https://youtu.be/1R0_7HqNaW0?t=700
    Code: https://youtu.be/1R0_7HqNaW0?t=800
    Code: https://youtu.be/1R0_7HqNaW0?t=900
    Code: https://youtu.be/1R0_7HqNaW0?t=1000
    Code: https://youtu.be/1R0_7HqNaW0?t=1100
    Code: https://youtu.be/1R0_7HqNaW0?t=1200
    Code: https://youtu.be/1R0_7HqNaW0?t=1300
    Code: https://youtu.be/1R0_7HqNaW0?t=1400
    Code: https://youtu.be/1R0_7HqNaW0?t=1500
    Code: https://youtu.be/1R0_7HqNaW0?t=1600
    Code: https://youtu.be/1R0_7HqNaW0?t=1700
    Code: https://youtu.be/1R0_7HqNaW0?t=1800
    Code: https://youtu.be/1R0_7HqNaW0?t=1900
    Code: https://youtu.be/1R0_7HqNaW0?t=2000

    Leetcode: https://leetcode.com/problems/coin-change/
    InterviewBit: https://www.interviewbit.com/problems/coin-sum-infinite/
    Codeforces: https://codeforces.com/problemset/problem/706/C
    CodeChef: https://www.codechef.com/problems/COINS
    CodeChef: https://www.codechef.com/problems/COINFLIP
    CodeChef: https://www.codechef.com/problems/COINFLIP2
    CodeChef: https://www.codechef.com/problems/COINFLIP3
    CodeChef: https://www.codechef.com/problems/COINFLIP4
    CodeChef: https://www.codechef.com/problems/COINFLIP5
    CodeChef: https://www.codechef.com/problems/COINFLIP6
    CodeChef: https://www.codechef.com/problems/COINFLIP7
    CodeChef: https://www.codechef.com/problems/COINFLIP8
    CodeChef: https://www.codechef.com/problems/COINFLIP9

    Topcoder: https://community.topcoder.com/stat?c=problem_statement&pm=13609
    Topcoder: https://community.topcoder.com/stat?c=problem_statement&pm=13610

    SPOJ: https://www.spoj.com/problems/COINS/

    HackerEarth: https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/coin-change-8/

    HackerRank: https://www.hackerrank.com/challenges/coin-change/problem

    AtCoder: https://atcoder.jp/contests/dp/tasks/dp_i

    CodeForces: https://codeforces.com/problemset/problem/706/C

    CodeChef: https://www.codechef.com/problems/COINFLIP

    CodeChef: https://www.codechef.com/problems/COINFLIP2

    CodeChef: https://www.codechef.com/problems/COINFLIP3

    Example:
        Input: 4 3
               1 2 3
        Output: 4
        Explanation: There are four ways to make 4.
                     {1,1,1,1}, {1,1,2}, {2,2}, {1,3}
    
    Example:
        Input: 10 4
               2 5 3 6
        Output: 5
        Explanation: There are five ways to make 10.
                     {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5}, {5,5}

    



*/
int coinChange(int coins[], int n, int sum){
    int dp[n + 1][sum + 1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= sum; j++){
            if(i == 0){
                dp[i][j] = 0;
            }
            if(j == 0){
                dp[i][j] = 1;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            if(coins[i - 1] <= j){
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}
signed main(){
    int n,sum;
    cin >> n >> sum;
    int coins[n];
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    cout << coinChange(coins,n,sum) << endl;
    return 0;
}

