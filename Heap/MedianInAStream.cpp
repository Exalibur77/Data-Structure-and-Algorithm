#include<iostream>
#include<queue>
using namespace std;

class MedianFinder {
public:

    priority_queue <int> maxHeap;
	priority_queue<int , vector<int> , greater<int>> minHeap;

    MedianFinder() {

    }
    
    // LogN for push

    void addNum(int num) {
        
        // if both are empty push into any one of them
		if(maxHeap.empty() and minHeap.empty()){
			maxHeap.push(num);
		}

		// any one of them or both have them some values
		else{
			
			if(maxHeap.top() < num){
				minHeap.push(num);
			}

			else{
				maxHeap.push(num);
			}
			
		}

		// STEP 2 : Balancing 
	
		// Now balancing both the heaps to have equal or only 1 greater element than each other

		int n = maxHeap.size();
		int m = minHeap.size();

		// Unbalanced hai ek mein ek so 2 zyada elements hai 
		if(n-m == 2 or n-m == -2){

			// maxHeap mein zyada element hai toh uska top utha ke minHeap mein daal do
			if(n > m){
				int ele = maxHeap.top();
				maxHeap.pop();
				minHeap.push(ele);

			}

			// agar minHeap mein zyada ho toh uska top utha ke maxHeap mein
			else{
				
				int ele = minHeap.top();
				minHeap.pop();
				maxHeap.push(ele);
				
			}
				
		}

    }
    
    // T.C - O(1)

    double findMedian() {

        // STEP : 3 Finding median from the balanced min and max Heaps

		int n = maxHeap.size();
		int m = minHeap.size();

		// total even number of elements
		if((n+m)%2 == 0){
			
			return (double)((maxHeap.top()+minHeap.top())/2.0);
			
		}
		
		// maxHeap bda hai
		if(n>m){
			return (double)maxHeap.top();
		}

		
		return (double)minHeap.top();
			
	}
		
};

// T.C- O(N*LOGN)

int main(){

    
    int n; cin >>n;
    vector <int> arr(n);
   
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }

    vector <double> ans;

    MedianFinder* obj = new MedianFinder();

    for(int i=0 ; i<n ; i++){

        int num = arr[i];

        obj->addNum(num);
        double param_2 = obj->findMedian();

        ans.push_back(param_2);

    }

    for(auto &val : ans){
        cout << val << " ";
    }

    return 0;


}



  
 
 