#include<iostream>
#include<cstring>
using namespace std;

// finding subsets using output array which is same for each recursive call hence we require a backtrack step to reach to the original state.

// int i for filling output array
void findSubsets(char input[] , char output[] , int index , int n , int i){

    if(index == n){

        output[i] = '\0';
        cout << output << endl;
        return;
    }

    // recursive step

    // not include
    findSubsets(input,output,index+1,n,i);

    // included
    output[i]=input[index];
    findSubsets(input,output,index+1,n,i+1);

    // Here backtracking step would not affect anything as we are adding data in output array everystep it geting override by the new ans.

    // adding a null character at the i th index of output.

    output[i]='\0';// optional in this question


}


int main(){

    char input[100];
    char output[100];

    cin >> input;

    int n =strlen(input);

    findSubsets(input,output,0,n,0);

    cout << output << endl;


    return 0;
}