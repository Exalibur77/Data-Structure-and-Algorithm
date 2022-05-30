// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
    
    private:
    
    vector <int> nextSmallerIndex(int * heights , int n){
        
        // int n= heights.size();
        vector<int> ans(n);
        stack<int> stk;
        
        for(int i=n-1 ; i>=0 ; i--){
            
            int curr = heights[i];
            
            while(!stk.empty() and heights[stk.top()] >= curr){
                stk.pop();
            }
            
            if(stk.empty()) ans[i]= -1;
            
            else ans[i] = stk.top();
            
            
            // pushed current index instead of curr element
            stk.push(i);
            
   
        }
        
        return ans;
    }  
    
    
    vector <int> previousSmallerIndex(int * heights , int n){
        
        // int n= heights.size();
        vector<int> ans(n);
        stack<int> stk;
        
        for(int i=0 ; i<n ; i++){
            
            int curr = heights[i];
            
            while(!stk.empty() and heights[stk.top()] >= curr){
                stk.pop();
            }
            
            if(stk.empty()) ans[i]= -1;
            else ans[i] = stk.top();
            
            
            // pushed current index instead of curr element
            stk.push(i);
            
   
        }

        return ans;    
    }

    
    
    int findArea(int *heights , int n) {

        // int n=heights.size();
        
        // next and previous are stroing indeces instead of smaller values
        vector <int> next(n);
        next = nextSmallerIndex(heights,n);
        
        vector <int> previous(n);
        previous = previousSmallerIndex(heights,n);
        
        int ans = -1;
        
        int currArea;
        
        for(int i=0 ; i<n ; i++){
            
            int l = heights[i];
            
            // If next[i] = -1 means no chota towards right ie we can cover all the bars so next[i] =n
            
            if(next[i] == -1) next[i] = n;
            
            int b = next[i]-previous[i]-1;
            
            currArea = l*b;
            
            ans = max(ans,currArea);
            
            
        }
        
        return ans;
        
        // return 0;
    }
    
    
    
    
    public:
    
    // Time Complexity -- O(m*n) and Space Complexity - O(m)
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        
        int area = findArea(M[0],m);
        
        // for remaining rows also calculate the area
        
        for(int i=1 ; i<n ; i++){
            
            
            for(int j=0 ; j<m ; j++){
                
                if(M[i][j]!=0){
                    M[i][j] += M[i-1][j];
                }
            }
            
            
            // calculating area for new row
            
            int newArea = findArea(M[i],m);
            
            area = max(area,newArea);
            
        }
        
        return area;
        
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends