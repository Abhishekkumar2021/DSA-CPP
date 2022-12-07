#include<bits/stdc++.h>
using namespace std;
/*
Huffman Coding
--------------
Time: O(NlogN)
Space: O(N)

Huffman coding is a data compression algorithm. The idea is to assign variable-length codes to input characters, lengths of the assigned codes 
are based on the frequencies of corresponding characters. The most frequent character gets the smallest code and the least frequent character 
gets the largest code.

Pseudocode: https://en.wikipedia.org/wiki/Huffman_coding#Pseudocode
Code: https://en.wikipedia.org/wiki/Huffman_coding#C++
Image: https://upload.wikimedia.org/wikipedia/commons/3/38/Huffman_coding_example.svg
Video: https://www.youtube.com/watch?v=dM6us854Jk0

*/

int main(){
    int n;
    cin>>n;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        pq.push(x);
    }
    int ans=0;
    while(pq.size()>1){
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();
        ans+=a+b;
        pq.push(a+b);
    }
    cout<<ans;
}
