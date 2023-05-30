//{ Driver Code Starts
//Initial Template for C++

#include <iostream>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class TrieNode{
    
public:
    TrieNode * children[2];
    
    TrieNode(){
        
        for(int i=0 ; i<2 ; i++){
            children[i] = NULL;
        }
    }
    
};

// T.C - O(N*32)
// S.C - O(N*32)

class Solution
{
    public:
    
    TrieNode * root = new TrieNode();
    
    void insert(TrieNode * root , int val){
        
        TrieNode * curr = root;
        
        for(int i=31 ; i>=0 ; i--){
            
            int bit = (val >> i) & 1;
            
            // here index is equivalent to the bit
            
            if(curr->children[bit] == NULL){ // previously ye bit exsits nhinkrti
                
                curr->children[bit] = new TrieNode();
                
                
            }
            
            // move to next if exsits or not
            curr = curr->children[bit];
        }
        
    }
    
    
    int solve(TrieNode * root , int val){
        
        int ans = 0;
        
        TrieNode * curr = root;;
        
        for(int i=31 ; i>=0 ; i--){
            
            int bit = (val >> i) & 1;
            
            // bit is equivalent to the index
            
            // agr bit 1 hai toh mujhe 0 ki khuj krni hai 
            // aur agr bit 0 hai toh mujhe 1 ki khuj hai
            
            if(bit == 1){ // bit 1 hai num ki
                
                if(curr->children[0] != NULL){ // trie mein 0 available hai
                    
                    ans += (1<<i);
                    
                    curr = curr->children[0];
                    
                }
                
                else{
                    curr = curr->children[1];
                }
                
            }
            
            else{ // bit 0
                
                if(curr->children[1] != NULL){ // 1 present hai trie mein
                    
                    ans += (1<<i);
                    
                    curr = curr->children[1];
                }
                
                else{ // 1 bit available hi nhi
                    
                    curr = curr->children[0];
                    
                }
                
            }
            
            
        }
        
        return ans;  
        
        
    }
    
    int max_xor(int arr[] , int n)
    {
        // Insert all the numbers binary representation into the trie
        
        for(int i=0 ; i<n ; i++){
            
            insert(root , arr[i]);
            
        }
        
        
        int maxAns = 0;
        
        for(int i=0 ; i<n ; i++){
            
            maxAns = max(maxAns , solve(root , arr[i]));
            
        }
        
        return maxAns;
        
    }
    
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

        Solution ob;
		cout << ob.max_xor(a, n) << endl;

	}
}



// } Driver Code Ends