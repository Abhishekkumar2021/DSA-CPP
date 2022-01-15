#include<bits/stdc++.h>
using namespace std;

int ways(int row,int col,string output[]){
  if(row==1){
    output[0]="";
    for(int i=0; i<col-1; i++){
      output[0]+='H';
    }
    return 1;
  }
  if(col==1){
    output[0]="";
    for(int i=0; i<row-1; i++){
      output[0]+='V';
    }
    return 1;
  }

  string temp[1000];
  int ansH = ways(row,col-1,output);
  int k=0;
  for(int i=0; i<ansH; i++){
    temp[k] = output[i]+'H';
    k++;
  }
  int ansV = ways(row-1,col,output);
  for(int i=0; i<ansV; i++){
    temp[k] = output[i]+'V';
    k++;
  }
  for(int i=0; i<ansV+ansH; i++){
    output[i] = temp[i];
  }
 return ansV+ansH;
}

int main(){
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  string output[1000];
  int res = ways(4,4,output);
  for(int i=0; i<res; i++)
  cout<<output[i]<<endl;
}
