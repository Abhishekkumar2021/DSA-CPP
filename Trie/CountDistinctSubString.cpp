#include<bits/stdc++.h>
using namespace std;
class Node{
    vector<Node*> links;
    bool flag;
    public:
    Node(){ 
        links.resize(26,NULL);
        flag = false;
    }
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch){
        links[ch-'a'] = new Node();
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag==true;
    }
};

class Trie{
    Node *root;
    public:
    Trie(){
        root = new Node();
    }
    int insert(string word){
        int cnt = 0;
        Node *node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                cnt++;
                node->put(word[i]);
            }
            node = node->get(word[i]);
        }
        node->setEnd();
        return cnt;
    }
};
int main(){
    string s = "abab";
    int cnt = 0;
    Trie t;
    for(int i=0; i<s.size(); i++){
        cnt+=t.insert(s.substr(i));
    }
    cout<<cnt+1<<"\n";
}