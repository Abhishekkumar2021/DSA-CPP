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
    void insert(string word){
        Node *node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i]);
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    bool search(string word){
        Node *node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string word){
        Node *node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return true;
    }
    bool ifPrefixExist(string word){
        Node *node = root;
        for(int i=0; i<word.size(); i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
                if(node->isEnd()==false)
                    return false;
            }else
            return false;
        }
        return true;
    }
};