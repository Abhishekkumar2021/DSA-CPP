#include<bits/stdc++.h>
using namespace std;
// void recursionPermute(vector<int> &data,vector<int> &nums,vector<vector<int>>&ans, int freq[]){
//     if(data.size()==nums.size()){
//         ans.push_back(data);
//         return;
//     }
//     for(int i=0; i<nums.size(); i++){
//         if(!freq[i]){
//             data.push_back(nums[i]);
//             freq[i]=1;
//             recursionPermute(data,nums,ans,freq);
//             freq[i]=0;
//             data.pop_back();
//         }
//     }
// }
// vector<vector<int>> permute(vector<int> &nums){
//     vector<vector<int>> ans;
//     vector<int> data;
//     int frequency[nums.size()]={0};
//     recursionPermute(data,nums,ans,frequency);
//     return ans;
// }
void permute(string s,int current_index,int &count){
    if(current_index==s.size()-1){
        cout<<count<<" : "<<s<<"\n";
        count++;
        return;
    }
    for(int i=current_index; i<s.size(); i++){
        swap(s[current_index],s[i]);
        permute(s, current_index + 1, count);
        swap(s[current_index], s[i]);
    }
}
int main(){
    string s="12345";
    int x = 1;
    permute(s,0,x);  
}