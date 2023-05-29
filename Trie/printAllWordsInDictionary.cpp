#include<iostream>
#include<string>
using namespace std;

// T.C - O(N) for all insertion , deletion and searching

class TrieNode{

    public:

        char data;
        TrieNode* children[26];
        bool isTerminal;

    TrieNode(char ch){
        data = ch;

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
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode * root , string word){

        // base case

        if(word.size() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0]-'a';

        // now check whether word[0] already exsits or not

        TrieNode * child;

        // already present hai ye
        if(root->children[index] != NULL){
            child = root->children[index];
        }


        // not found toh insert kro value
        else{

            root->children[index] = new TrieNode(word[0]);
            child = root->children[index];

        }

        insertUtil(child,word.substr(1));

    }

    void insertWord(string word){

        insertUtil(root,word);

    }

    bool searchUtil(TrieNode * root , string word){

        // base case
        if(word.size() == 0){ // means yes we found the whole string

            if(root->isTerminal == true) return true; // last node terminal bhi honi chaiye 

            return false;
        }

        int index = word[0]-'a';

        TrieNode * child;

        // already present at the given index just move forward
        if(root->children[index] != NULL){
            child = root->children[index];
        }

        // not present 
        else{
            return false;
        }

        return searchUtil(child , word.substr(1));

    }

    bool searchWord(string word){

        return searchUtil(root,word);

    }

    // very similar to searching
    void deleteUtil(TrieNode * root , string word){

        // REACHED the end of the word
        if(word.size() == 0){

            // word exsits
            if(root->isTerminal == true){
                root->isTerminal = false;
            }

            // word does not exists
            else{
                cout << "Word Does not exsits" << endl;
            }
            
            return;
        }

        int index = word[0]-'a';

        TrieNode * child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }

        // if not found then just return
        else{

            cout << "Word Does not exsits" << endl;
            return;
        }

        deleteUtil(child , word.substr(1));


    }

    void deleteWord(string word){

        deleteUtil(root,word);

    }

    void printUtil(TrieNode * root , string str){

        // base case
        if(root->isTerminal == true){
            

            cout << str << endl;
            return;
        }

        for(int i=0 ; i<26 ; i++){

            // i th index wala exsits krta hai 
            if(root->children[i]){
                str += ('a' + i);

                printUtil(root->children[i] , str);
            }

        }

    }


    void printAll(){

        string ans;
        printUtil(root , ans);

    }



};

int main(){

    Trie t;

    t.insertWord("abcd");
    t.insertWord("tom");
    t.insertWord("time");
    t.insertWord("raj");

    // cout << t.searchWord("abcd") << endl;
    // cout << t.searchWord("t") << endl;
    // cout << t.searchWord("time") << endl;
    // cout << t.searchWord("raj") << endl;

    // t.deleteWord("raj");
    // cout << t.searchWord("raj") << endl;

    // t.deleteWord("tommy");
    // t.deleteWord("to");

    // t.deleteWord("tom");
    // cout << t.searchWord("tom") << endl;

    t.printAll();

    return 0;

}