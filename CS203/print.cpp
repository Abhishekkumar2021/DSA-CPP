#include<bits/stdc++.h>
using namespace std;
int main() {
  for(int i=0; i<100; i++) {
      for(int j=0; j<100; j++) {
          if(i%4==0 ){
              if(j%4==0 ){
                  cout << "("<<i<<", "<<j<<")";
              }
              else 
              cout<<" ";
          }
          
      }
      cout<<"\n";
  }

  return 0;
}