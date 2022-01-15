#include<bits/stdc++.h>
#include "Array_as_ADT_template.h"
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  ArrayADT<string> Array;
  Array.createNewArray(10);
  for(int i=0; i<10; i++){
    string s;
  getline(cin,s);
    Array.storeValue(s,i);
    cout<<"The value at index "<<i<<" is "<<Array.accessValue(i)<<endl;
  }
  cout << "sdg is present at index = "<<Array.searchValue("sdg"); 
  return 0;
}