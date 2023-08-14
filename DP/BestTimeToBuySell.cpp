#include<iostream>
#include<vector>

using namespace std;


int maximumProfit1(vector<int> &prices){
    
    int n = prices.size();

    int ans = 0 ;

    for(int i=0 ; i<n ; i++){

        for(int j= i+1 ; j<n ; j++){

            ans = max(ans , prices[j]-prices[i]);
            
        }
        
    }


    return ans;
}

 
int maximumProfit2(vector<int> &prices){
    
    int n = prices.size();

    vector <int> minPrice(n);

    minPrice[0] = prices[0];

    for(int i=1 ; i<n ; i++){

        minPrice[i] = min(minPrice[i-1] , prices[i]);
        
    }

    int ans = 0;

    for(int i=0 ; i<n ; i++){

        ans = max(ans , prices[i] - minPrice[i]);
        
    }
    


    return ans;
}


int maximumProfit3(vector<int>& prices) {
    
    int n = prices.size();

    int minPrice = prices[0];

    int maxi = 0;

    for(int i=0 ; i<n ; i++){
        maxi = max(maxi, prices[i]- minPrice);

        minPrice = min(minPrice , prices[i]);

    }

    return maxi;
}



int main() {

  vector<int> Arr  ={7,1,5,3,6,4};

  cout<<"The maximum profit by selling the stock is "<<maximumProfit1(Arr) << endl;
  cout<<"The maximum profit by selling the stock is "<<maximumProfit2(Arr) << endl;
  cout<<"The maximum profit by selling the stock is "<<maximumProfit3(Arr) << endl;
}