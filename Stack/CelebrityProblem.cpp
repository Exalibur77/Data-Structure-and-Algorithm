#include<bits/stdc++.h>
using namespace std;

// O(n) solution and O(N) Space Complexity
class Solution 
{
    private:
    
    bool knows(int a, int b , vector<vector<int> >& M , int n){
        
        // a knows b or not 
        
        if(M[a][b] == 1) return 1;
        
        return 0;
    }
    
    
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        
        stack <int> stk;
        
        for(int i=0 ; i<n ; i++){
            stk.push(i);
        }
        
        // 
        while(stk.size() >1){
            
            int a = stk.top();
            stk.pop();
            
            int b = stk.top();
            stk.pop();
            
            // a does not know b && b also does not know a  .. both cant be celebrity
            if(!knows(a,b,M,n) and !knows(b,a,M,n)){
                continue;
            }
            
            // if a knows b ... a is not celebrity
            else if(knows(a,b,M,n)){
                stk.push(b);
            }
            
            // else b knows a .. b is not celebrity
            else{
                stk.push(a);
            }
            
        }

        // since last two elements could also not be celeb and stack could be empty
        if(stk.size() == 0) return -1;
        
        
        int celeb = stk.top();
        
        // check whether it is a celebrity
        
        for(int i=0 ; i<n ; i++){
            if(M[celeb][i] == 1) return -1;
        }
        
        for(int i=0 ; i<n ; i++){
            
            if(i!=celeb and M[i][celeb] == 0) return -1;
            
        }
        
        return celeb;
        
    }

// Brute force approach -- O(n^2)
    int celebrity02(vector<vector<int> >& M, int n) 
    {
        
        for(int i=0 ; i<n ; i++){
            
            int cnt0 = count(M[i].begin(),M[i].end(),0);
            
            // cout << cnt0 << " ";
            
            // Might be a possibilty ki ye ek celebrity ho i
            if(cnt0 == n){
                
            
                bool flag = 1;
                
                for(int j=0 ; j<n ; j++){
                    
                    // j the row ka bnda i th wala ko nhi janta matlab celebrity nhi hai 
                    if(j!=i and M[j][i] != 1){
                        flag =0;
                    }
                }
           
            
                if(flag) return i;
            
            }
        }
        
        return -1;

        
    }



};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends