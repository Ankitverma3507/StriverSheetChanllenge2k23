#include <bits/stdc++.h> 
using namespace std;
struct Node{
    Node *links[26];
    bool flag= false;
    
    bool containKey(char ch){
        return (links[ch-'a'] !=NULL);
    }

    void put(char ch, Node * node){
        links[ch-'a']= node;
    }

    Node* get(char ch){
        return  links[ch-'a'];
    }

    void setEnd(){ //used in insert function
        flag= true;
    }

    bool isEnd(){  //used in search function
        return flag;
    }
};



class Trie {
    private: Node*root;
public:
    Trie() {
        root= new Node();
    }
    
        //TC will be O(len of word)
    void insert(string word) {
        Node *node= root;
        for(int i=0; i<word.size(); i++){
            if(!node->containKey(word[i])){
                node->put(word[i], new Node());
            }
            //now node will move to the reference trie
            node= node->get(word[i]);
        }

        node->setEnd();
    }
        
        
        //TC will be O(len of word)
    bool search(string word) {
        Node *node=  root;
        for(int i=0; i<word.size(); i++){
            if(!node->containKey(word[i]))
            return false;

            node= node->get(word[i]);
        }

        return node->isEnd();
    }
    

        //TC will be O(len of word)
    bool startsWith(string prefix) {
         Node *node=  root;
        for(int i=0; i<prefix.size(); i++){
            if(!node->containKey(prefix[i]))
            return false;

            node= node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */