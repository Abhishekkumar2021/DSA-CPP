#include<bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    int n = s.size();
    int m = t.size();
    if(n < m) return "";
    unordered_map<char, int> mp;
    for(auto c : t) mp[c]++;
    int count = mp.size();
    int i = 0, j = 0;
    int ans = INT_MAX;
    int start = 0;
    while(j < n){
        if(mp.find(s[j]) != mp.end()){
            mp[s[j]]--;
            if(mp[s[j]] == 0) count--;
        }
        while(count == 0){
            if(ans > j - i + 1){
                ans = j - i + 1;
                start = i;
            }
            if(mp.find(s[i]) != mp.end()){
                mp[s[i]]++;
                if(mp[s[i]] == 1) count++;
            }
            i++;
        }
        j++;
    }
    if(ans == INT_MAX) return "";
    return s.substr(start, ans);
}