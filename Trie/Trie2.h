#include<bits/stdc++.h>
using namespace std;

class Node{
    vector<Node*> links;
    int ew;
    int cp;
    public:
    Node(){ 
        links.resize(26,NULL);
        cp = 0;
        ew = 0;
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
    void increasePrefix(){
        cp++;
    }
    void increaseEnd(){
        ew++;
    }
    void deleteEnd(){
        ew--;
    }
    void deletePrefix(){
        cp--;
    }
    int getEnd(){
        return ew;
    }
    int getPrefix(){
        return cp;
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
            node->increasePrefix();
        }
        node->increaseEnd();
    }
    int countWordsEqualsTo(string word){
        Node *node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node = node->get(word[i]);
            
        }
        return node->getEnd();
    }

    int countWordsStartsWith(string word){
        Node *node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node = node->get(word[i]);
        }
        return node->getPrefix();
    }

    void erase(string word){
        Node *node = root;
        for(int i=0; i<word.size(); i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
                node->deletePrefix();
            }
            else{
                return;
            }
            
        }
        return node->deleteEnd();
    }
};