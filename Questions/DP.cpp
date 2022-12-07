// #include <bits/stdc++.h>
// #define int long long
// using namespace std;

// int happy(vector<vector<int>> &v, int idx, int prev)
// {
//     if (idx == v.size() - 1)
//     {
//         int ans = INT_MIN;
//         if (prev == -1)
//         {
//             int s1 = max(v[idx][0], v[idx][1]);
//             ans = (s1, v[idx][2]);
//         }
//         else if (prev == 0)
//         {
//             ans = max(v[idx][1], v[idx][2]);
//         }
//         else if (prev == 1)
//         {
//             ans = max(v[idx][0], v[idx][2]);
//         }
//         else if (prev == 2)
//         {
//             ans = max(v[idx][0], v[idx][1]);
//         }
//         return ans;
//     }
//     int ans = INT_MIN;
//     if (prev == -1)
//     {
//         int s1 = max(happy(v, idx + 1, 0) + v[idx][0], happy(v, idx + 1, 1) + v[idx][1]);
//         ans = (s1, happy(v, idx + 1, 2) + v[idx][2]);
//     }
//     else if (prev == 0)
//     {
//         ans = max(happy(v, idx + 1, 1) + v[idx][1], happy(v, idx + 1, 2) + v[idx][2]);
//     }
//     else if (prev == 1)
//     {
//         ans = max(happy(v, idx + 1, 0) + v[idx][0], happy(v, idx + 1, 2) + v[idx][2]);
//     }
//     else if (prev == 1)
//     {
//         ans = max(happy(v, idx + 1, 0) + v[idx][0], happy(v, idx + 1, 1) + v[idx][1]);
//     }
//     return ans;
// }

// int32_t main()
// {
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     int n;
//     cin >> n;
//     vector<vector<int>> v;
//     for (int i = 0; i < n; i++)
//     {
//         vector<int> temp;
//         for (int i = 0; i < 3; i++)
//         {
//             int x;
//             cin >> x;
//             temp.push_back(x);
//         }
//         v.push_back(temp);
//     }

//     cout << happy(v, 0, -1) << endl;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
int main(){
   int t;
   cin>>t;
   while(t--){
      int n;
      cin>>n;
      int a[n];
      int b[n];
      int dif;
      int cnt=0;
      map<int,int> mp;
      for(int i=0;i<n;i++){
         cin>>a[i];
      }
      for(int j=0;j<n;j++){
           cin>>b[j];
      }
      dif=a[0]-b[0];
      if(n==1&&dif>=0){cout<<"YES"<<endl;}
      else if(n==1&&dif<0){cout<<"NO"<<endl;}
      else if(n>1){
           if(dif<0){cout<<"NO"<<endl;}
           else if(dif>=0){
            for(int i=1;i<n;i++){
               if(b[i]!=0){if((a[i]-b[i])!=dif){cout<<"NO"<<endl;
                  break;}
                  else if((a[i]-b[i])==dif){cnt++;
                     continue;
                  }
            }
            else if(b[i]==0&&(a[i]-b[i])<=dif){ cnt++;
               continue;}
               else if(b[i]==0&&(a[i]-b[i])>dif){
                  cout<<"NO"<<endl;
                  break;
               }
         }
            if(cnt==(n-1))cout<<"YES"<<endl;
           }
      }
   }
   return 0;
}