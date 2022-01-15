#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    for (int b = 0; b < (1<<5); b++) {
    vector<int> subset;
      for (int i = 0; i < 5; i++) {
          if (b&(1<<i)) 
          subset.push_back(i);
      }
      cout << "{ ";
      for (auto x : subset)
          cout << x << " ";
      cout << "}" << endl;
      cout<<endl;
    }


  return 0;
}