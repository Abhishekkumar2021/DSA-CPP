#include<bits/stdc++.h>
using namespace std;
long int fibonacci(int num){
    if(num==1)
    return 0;
    if (num == 2)
    return 1;
    long int prev = 1;
    long int secondPrev = 0;
    long int ans = 0;
    for(int i=3; i<=num; i++){
         ans = prev + secondPrev;
         secondPrev = prev;
         prev = ans; 
    }
    return ans;
}
void printFibonaacci(int num){
    if (num == 1)
        cout<<0<<" ";
    else if (num >= 2)
    cout<<0<<" "<<1<<" ";
    long int prev = 1;
    long int secondPrev = 0;
    long int ans = 0;
    for (int i = 3; i <= num; i++)
    {
        ans = prev + secondPrev;
        secondPrev = prev;
        prev = ans;
        cout<<ans<<" ";
    }
 
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  clock_t timestamp ;
  double elapsedTime;
  timestamp = clock();
  printFibonaacci(1000);
  timestamp = clock() - timestamp;
  elapsedTime = ((double)timestamp)/CLOCKS_PER_SEC;
  cout<<"Time taken by iterative = "<<elapsedTime<<" s"<<endl;
  return 0;
}