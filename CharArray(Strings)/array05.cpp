#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

// Shortest Route problem by calculating displacement


int main(){

    char str[1000];

    cin.getline(str,1000);

    int n=strlen(str);

    int x=0,y=0;

    for (int i = 0; i < n; i++)
    {
        if(str[i]=='N'){
            y++;
        }
        else if(str[i]=='S'){
            y--;
        }
        else if(str[i]=='E'){
            x++;
        }
        else if(str[i]=='W'){
            x--;
        }
    }


    if(x>0 && y>0){// First Quad
        while(y--){
            cout << "N";
        }

        while (x--)
        {
            cout << "E";
        }
    }
    else if(x<0 && y>0){// Second Quad
        while(y--){
            cout << "N";
        }
        while (x++)
        {
            cout << "W";
        }
        
    }
    else if(x<0 && y<0){// Third Quad
        while(y++){
            cout << "S";
        }

        while (x++)
        {
            cout << "W";
        }
        
    }
    else if(x>0 && y>0){// Fourth Quad
        while(y++){
            cout << "S";
        }

        while (x--)
        {
            cout << "E";
        }
        
    }


    cout << endl;

    return 0;
}