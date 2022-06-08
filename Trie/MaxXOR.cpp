#include<bits/stdc++.h>
using namespace std;
class Node{
    vector<Node*> links;
    public:
    Node(){
        links.resize(2,NULL);
    }
    bool containsKey(int bit){
        return links[bit]!=NULL;
    }
    Node *get(int bit){
        return links[bit];
    }
    void put(int bit){
        links[bit] = new Node();
    }
};
class Trie{
    Node *root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(int n){
        Node *node = root;
        for(int i=31; i>=0; i--){
            int bit = (n>>i) & 1;
            if(!node->containsKey(bit))
            node->put(bit);
            node = node->get(bit);
        }
    }
    int getMax(int x){
        Node *node = root;
        int ans = 0;
        for(int i=31; i>=0; i--){
            int bit = (x>>i) & 1;
            if(node->containsKey(1-bit)){
                ans|=(1<<i);
                node = node->get(1-bit);
            }else
            node = node->get(bit);
        }
        return ans;
    }

};
int main(){

}