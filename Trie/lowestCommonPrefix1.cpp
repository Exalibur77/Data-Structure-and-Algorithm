#include<iostream>
#include<vector>
#include<string>

using namespace std;


class TrieNode{

    public:
    char data;
    TrieNode * children[26];
    int childCnt;
    bool isTerminal;
    
    TrieNode(char ch){
        
        data = ch;

        for(int i=0 ; i<26 ; i++){
            children[i] = NULL;
        }

        isTerminal = false;
        childCnt = 0;
    }
    
};

class Trie{

public:
    
    TrieNode * root;

    Trie(){
        root = new TrieNode('\0');
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

            root->children[index] = new TrieNode(word[i]);
            root->childCnt++;
            child = root->children[index];

        }

        insertUtil(child,word,i+1);

    }

    void insertWord(string word){

        insertUtil(root,word,0);

    }

    
    void lcp(string str , string &ans){

        TrieNode * ptr = root;

        for(int i=0 ; i<str.size() ; i++){

            char ch = str[i];

            // if ek hi child hai toh character add krdo
            if(ptr->childCnt == 1){

                ans += ch;

                // aage bdo
                int index = ch-'a';

                ptr = ptr->children[index];


            }

            else{

                break;

            }

            // last element tk phoch gya 
            if(ptr->isTerminal){
                break;
            }

        }

        delete ptr;

    }

    
};


string longestCommonPrefix(vector<string> &arr, int n)
{
    
    
    Trie t;

    for(auto &word : arr){
        t.insertWord(word);
    }

    string ans;

    string str = arr[0]; // random used in traversal

    // now making answer

    t.lcp(str , ans);

    return ans;


    
}


int main(){

    int n;
    cin >> n;

    vector <string> arr(n);

    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }

    string ans = longestCommonPrefix(arr,n);

    cout << ans << endl;

    return 0;

}
