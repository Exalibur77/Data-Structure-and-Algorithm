#include<iostream>
using namespace std;

// Char array functions to use (strcpy , strlen , strcmp , strcat)
int main(){

    char a[100]="apple";
    char b[100];

    // calc length
    cout << strlen(a) << " " << strlen(b) << endl;// strlen(b) gives undefined results because it is not clear where is '\0' .

    //Strcpy
    strcpy(b,a);// copy a to b

    cout << a << endl;
    cout << b << endl;

    strcat(b," mango");
    //Compare either gives negative , zero , positive
    /*
    strcmp(a,b)
    0 when both are equal
    positive when ASCII of a>b 
    negative whne ASCII of a<b    
    */
    cout << strcmp(a,b) << endl;

    // Strcat (concatenate Strings)

    char f_name[]="sanskar";
    char l_name[]="garg";

    strcat(f_name,l_name);// f_name=f_name+l_name;

    cout << f_name << endl;

    return 0;
}