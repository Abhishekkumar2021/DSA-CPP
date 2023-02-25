/*
Problem
You are given an array AA consisting of NN positive integers and a positive integer KK.

Find whether there exists a subset SS of the elements of AA such that the product of all elements of SS is divisible by KK.

Note that a subset is obtained by deleting some or no elements without changing the order of the remaining elements.

Input Format
The first line of input will contain a single integer TT, denoting the number of test cases.
Each test case consists of multiple lines of input.
The first line of each test case contains two space-separated integers NN and KK — the number of elements of AA and the above mentioned integer KK.
The second line of each test case contains NN space-separated integers A_1,A_2,...,A_NA 
1
​
 ,A 
2
​
 ,…,A 
N
​
  representing the array AA.
Output Format
For each test case, print on a new line the answer: YES if there exists a subset SS and NO otherwise.

Each character of the output may be printed in either uppercase or lowercase, i.e, the strings Yes, YES, yes, yEs` will all be treated as identical.

Constraints
1 <= T <= 100
1 <= N <= 100
1 <= A_i, K <= 10^9
 
Sample 1:
Input
Output
3
2 2
7 8
5 3
1 1 2 1 1
3 6
7 2 3
YES
NO
YES
Explanation:
Test case 11: Consider the subset S = [8]S=[8]. The product of all the elements is 88 which is divisible by K = 2

Test case 22: There exists no subset of AA such that the product of all elements of the subset is divisible by KK.

Test case 33: Consider the subset S = [2, 3]S=[2,3]. The product of all the elements is 66 which is divisible by K = 6

Approach:
1. Find the number of subsets of the array.
2. For each subset, find the product of the elements.
3. If the product is divisible by K, then print YES.
4. Else, print NO.

Time Complexity: O(2^N)
Space Complexity: O(1)

*/

#include<bits/stdc++.h>
using namespace std;

bool isExist2(int a[], int n, int k){
    for(int i=0; i<(1<<n); i++){
        int prod = 1;
        for(int j=0; j<n; j++){
            if(i & (1<<j)){
                prod *= a[j];
            }
        }
        if(prod % k == 0){
            return true;
        }
    }
    return false;
}

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a%b);
}

bool isExist(int a[], int n, int k){
    for(int i=0; i<n; i++){
        k = k/gcd(a[i], k);
        if(k == 1) return true;
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        if(isExist(a,n,k)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}