#include<iostream>
using namespace std;

int main(){

    char sentence[1000];

    // Inputting the sentence using cin.get()

    char temp=cin.get();

    int i=0;

    while (temp!='\n')// until user does not hit enter keeps inputting the character.
    {
        sentence[i]=temp;
        i++;
        //Update value of temp
        temp=cin.get();
    }
    sentence[i]='\0';

    cout << i  << " " << strlen(sentence) << endl;
    cout << sentence << endl;



    return 0;
}