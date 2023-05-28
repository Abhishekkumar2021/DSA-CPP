#include<bits/stdc++.h>
using namespace std;

// No consecutive 1s in binary string of length k
vector<string> generateString(int k) {
    // Write your code here.
    vector<string> ans;

    // Edge Case
    if(k==0){
        return ans;
    }

    // Base Case
    if(k==1){
        ans.push_back("0");
        ans.push_back("1");
        return ans;
    }

    // Recursive Case
    vector<string> temp = generateString(k-1);

    // based on the last character of the string in temp, we will add 0 or 1
    for(int i=0; i<temp.size(); i++){
        string s = temp[i];
        if(s[s.length()-1]=='0'){
            ans.push_back(s+"0");
            ans.push_back(s+"1");
        }else{
            ans.push_back(s+"0");
        }
    }

    return ans;
}