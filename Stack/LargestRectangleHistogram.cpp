#include<bits/stdc++.h>
using namespace std;


class Solution {

private:

    vector <int> nextSmallerIndex(vector<int>& heights){
        
        int n= heights.size();
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
    
    
    vector <int> previousSmallerIndex(vector<int>& heights){
        
        int n= heights.size();
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


public:
    int largestRectangleArea01(vector<int>& heights) {
        
        // Brute Force Approach --- O(n^2)
        
        int n=heights.size();
        int cntLeft,cntRight;
        int currArea;
        
        int ans = -1;
        
        for(int i=0 ; i<n ; i++){
            
            int currLen = heights[i];
            
            int j =i-1;
            
            cntLeft=0;
            // goinf uptill previous smaller element
            while(j>=0 and heights[j] >= currLen){
                cntLeft++;
                j--;
            }
            
            j = i+1 ;
            cntRight=0;
            // going uptill next smaller element
            while(j<n and heights[j] >= currLen){
                cntRight++;
                j++;
            }
            
            
            currArea = currLen*(cntLeft+cntRight+1);
            ans = max(ans,currArea);
        }
        
        
        return ans;
        
    }


    int largestRectangleArea01(vector<int>& heights) {

        int n=heights.size();
        
        // next and previous are stroing indeces instead of smaller values
        vector <int> next(n);
        next = nextSmallerIndex(heights);
        
        vector <int> previous(n);
        previous = previousSmallerIndex(heights);
        
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











    }
};