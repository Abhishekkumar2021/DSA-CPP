#include<bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin>>T;
    int testCaseNum = 1;
    while (T--){
        int r,c;
        cin>>r>>c;
        //actual logic goes here
        int n = 2*r+1;
        int m = 2*c+1;
        char mat[n][m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
               if(i%2==0){
                   if(j%2==0){
                       mat[i][j] = '+';
                   }else{
                        mat[i][j] = '-';
                   }
               }else{
                   if(j%2==0){
                       mat[i][j] = '|';
                   }else{
                        mat[i][j] = '.';
                   }
               }
            }
        }
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                mat[i][j] = '.';
            }
        }
        
        cout << "Case #" << testCaseNum << ":\n";
        testCaseNum++;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
               cout<< mat[i][j];
            }
            cout<<"\n";
        }
    }
    return 0;
}