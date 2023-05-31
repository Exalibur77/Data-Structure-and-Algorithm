#include<iostream>
#include<string>
#include<set>
#include<vector>
using namespace std;

class TrieNode{

    public:
    // char data;
    TrieNode * children[26];

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
    
    
    void solve(TrieNode * curr , set <string> &suggestion , string prefix){
        
        // base case
        if(curr->isTerminal){
            
            suggestion.insert(prefix);
        }
        
    
        for(char ch = 'a' ; ch <= 'z' ; ch++){
            
            TrieNode * next = curr->children[ch-'a'];
            
            // if next child exsits then add it into prefix string .. ie trie mein is prefix se string aage exsits krta hai
            
            if(next != NULL){
                prefix.push_back(ch);
                
                solve(next , suggestion , prefix);
                
                prefix.pop_back();
            }
            
            
        }
        
        
    }
    

    vector <vector<string>> getSuggestions(string &query){
        
        vector < vector<string> > ans;
        
        string prefix = "";
        
        for(int i=0 ; i<query.size() ; i++){
            
            prefix += query[i];
        
            // Now searching for prefix
            set <string> suggestion;
            bool flag = 1;
            
            TrieNode * curr = root;
            
            for(int j=0 ; j<prefix.size() ; j++){
                
                int index = prefix[j]-'a';
                
                // means not present
                if(curr->children[index] == NULL){
                    flag = 0;
                    break;
                }
                
                curr = curr->children[index];
                
            }
            
            if(flag == 0) ans.push_back({"0"}); // no suggestion exsits since prefix is not found
            
            // if my word ends means we found it
            
            solve(curr,suggestion,prefix);
            
            vector <string> prefixSuggestion = vector<string>(suggestion.begin(),suggestion.end());
            
            if(flag == 1) ans.push_back(prefixSuggestion);
            
        }
        
        return ans;
        
    }
    

    
};

vector<vector<string>> displayContacts(vector <string> contact, string &s){
        
    int n = contact.size();
    Trie * t = new Trie();
        
    // Step : 1
        
    // Add each contact into trie
        
    for(int i=0 ; i<n ; i++){
            
        t->insertWord(contact[i]);
            
    }
        
    // Step 2
        
    return t->getSuggestions(s);
}


int main(){


    int n;
    cin >> n;

    vector <string> arr;

    for(int i=0 ; i<n ; i++){
        string str;
        cin >> str;

        arr.push_back(str);
    }

    string query;
    cin >> query;

    vector<vector<string>> ans = displayContacts(arr,query);

    for(auto &v : ans){

        for(auto & str : v){

            cout << str << " ";

        }

        cout << endl;
    }

    return 0;

}