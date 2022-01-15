#include<bits/stdc++.h>
using namespace std;
// void allSubsets(vector<int> &arr,vector<vector<int>> &subsets) {
//     if(arr.size()==1){
//          vector<int> v;
//         v.push_back(arr[0]);
//         subsets.push_back(v);
//         return;
//     }
//     vector<int> newVector(arr.begin()+1,arr.end());
//     allSubsets(newVector,subsets);
//     for(int i=0; i<subsets.size(); i++){
//         vector<int> v(subsets[i].begin(),subsets[i].end());
//         v.push_back(arr[0]);
//         subsets.push_back(v);
//     }
// }
void search(int k, int n, vector<int> subset)
{
    if (k == n)
    {
        // process subset
        cout << "{ ";
        for (auto x : subset)
            cout << x << " ";
        cout << "}" << endl;
    }
    else
    {
        search(k + 1, n,subset);
        subset.push_back(k);
        search(k + 1, n,subset);
        subset.pop_back();
    }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
//   vector<int> v;
//   vector<vector<int>> subsets;
//   for(int i=0; i<5; i++)
//   v.push_back(i+1);
//   allSubsets(v,subsets);
//   for(int i=0; i<subsets.size(); i++){
//       for(int j=0; j<subsets[i].size(); j++){
//           cout<<subsets[i][j]<<" ";
//       }
//       cout<<endl;
//   }
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
vector<int> v;
search(1,6,v);
  return 0;
}