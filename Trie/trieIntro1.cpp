#include<iostream>
#include<string>
using namespace std;

class TrieNode{

    public:

        // char data;
        TrieNode* children[26];
        bool isTerminal;

    TrieNode(){
        // data = ch;

        for(int i=0 ; i<26 ; i++){
            children[i] = NULL;
        }

        isTerminal = false;

    }

};


class Trie{

    public:

        TrieNode * root;

    Trie(){
        root = new TrieNode();
    }

    void insertUtil(TrieNode * root , string &word , int i){

        // base case

        if(i >= word.size()){
            root->isTerminal = true;
            return;
        }

        int index = word[i]-'a';

        // now check whether word[0] already exsits or not

        TrieNode * child;

        // already present hai ye
        if(root->children[index] != NULL){
            child = root->children[index];
        }


        // not found toh insert kro value
        else{

            root->children[index] = new TrieNode();
            child = root->children[index];

        }

        insertUtil(child,word,i+1);

    }

    void insertWord(string word){

        insertUtil(root,word,0);

    }

    bool searchUtil(TrieNode * root , string &word , int i){

        // base case
        if(i >= word.size()){ // means yes we found the whole string

            if(root->isTerminal == true) return true; // last node terminal bhi honi chaiye 

            return false;
        }

        int index = word[i]-'a';

        TrieNode * child;

        // already present at the given index just move forward
        if(root->children[index] != NULL){
            child = root->children[index];
        }

        // not present 
        else{
            return false;
        }

        return searchUtil(child , word , i+1);

    }

    bool searchWord(string word){

        return searchUtil(root,word,0);

    }




};

int main(){

    Trie t;

    // t.insertWord("abcd");
    // t.insertWord("tom");
    // t.insertWord("time");
    // t.insertWord("raj");

    // cout << t.searchWord("abcd") << endl;
    // cout << t.searchWord("t") << endl;
    // cout << t.searchWord("time") << endl;
    // cout << t.searchWord("aj") << endl;


    t.insertWord("njvfmhigcf");

    cout << t.searchWord("orrbynjvfm");

    t.insertWord("higcfjqxfi");
    t.insertWord("orrbynjvfm");

    cout << t.searchWord("higcfjqxfi");

    t.insertWord("jqxfihigcf");

    cout << t.searchWord("njvfmjqxfi");
    cout << t.searchWord("cxkgkorrby");
    cout << t.searchWord("cxkgkhigcf");

    

    return 0;

}