#include <bits/stdc++.h> 
using namespace std;
struct Node{
    Node * links[26];
    bool flag= false;

    bool containkey(char ch){
        return links[ch-'a'] !=NULL;
    }

    Node * get(char ch){
        return links[ch-'a'];
    }

    void put(char ch, Node *node){
        links[ch-'a']= node;
    }

    void setend(){
        flag= true;
    }

    bool isend(){
        return flag;
    }
};

class Trie{
    private: Node *root;

    public:
    Trie(){
        root= new Node();
    }

    void insert(string word){
        Node * node= root;
        for(int i=0; i<word.size(); i++){
            if(!node->containkey(word[i])){
                node->put(word[i], new Node());
            }
            node= node->get(word[i]);
        }
        node->setend();
    }

    bool checkIfprefixExhist(string word){
        bool fl= true;
        Node *node= root;
        for(int i=0; i<word.size();i++){
            if(node->containkey(word[i])){
                node= node->get(word[i]);
                if(node->isend()==false) return false;
            }
            return false;
        }
        return true;
    }
};
string completeString(int n, vector<string> &a){
    // Write your code here.

    Trie trie;
    for(auto &it: a){
        trie.insert(it);
    }

    string longest= "";

    for(auto &it: a){
        if(trie.checkIfprefixExhist(it)){
            if(it.length() > longest.length())
            longest= it;

            else if(it.length()== longest.length() and it<longest)
            longest= it;
        }

    }


    if(longest=="") return "None";
    return longest;
}











