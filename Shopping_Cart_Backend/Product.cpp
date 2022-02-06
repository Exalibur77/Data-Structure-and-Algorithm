#include<bits/stdc++.h>
#include"datamodel.h"
using namespace std;

vector <Product> allProducts = {

    Product(1,"apple",26),
    Product(3,"gauva",20),
    Product(2,"mango",10),
    Product(6,"papaya",54),
    Product(4,"cherry",35),
    Product(5,"litchi",40),

};


Product* chooseProduct(){

    // Displaying all products available

    cout << "List of Available Products: " << endl;
    for(auto &p : allProducts){

        cout << p.getDisplayName() << endl;

    }

    cout << "-------------------------" << endl;
    // Choosing the product

    char choice;
    cin >> choice;

    // Iterating and matching the users choice with the product list

    for(auto &p : allProducts){

        if(p.getShortName() == choice){
            return &p;
        }

    }

    // product not found

    cout << "Product Not Found .. !" << endl;
    return NULL;

}

bool checkout(Cart &cart){

    if(cart.isEmpty()){
        return false;
    }


    int total = cart.getTotal();

    cout << "Pay In Cash";

    int paid; cin >> paid;

    if(paid>=total){
        cout << "Change => " << paid-total << endl;
        cout << "Thanks for Shopping .. !" << endl;
        return true;
    }

    else{
        cout << "Insufficient Cash" << endl;
        return false;
    }


}


int main(){

    char action;
    Cart cart;

    while(true){
        cout << "Select an action --  (a)dd item , (v)iew cart , (c)heckout " << endl;

        cin >> action;

        if(action == 'a'){

            // 1. View Products.
            // 2 . Choose product.
            // 3. Add to cart. 


            Product *product = chooseProduct();

            if(product != NULL){
                // Product is added to the cart
                cout << product->getName() << " added to the cart " << endl;
                // to do

                cart.addProduct(*product);

            }

            


        }

        else if(action == 'v'){
            // View the cart.

            cout << "======================" << endl;

            cout << cart.ViewCart() << endl;

            cout << "======================" << endl;
        }

        else if(action == 'c'){
            cart.ViewCart();

            if(checkout(cart)){
                break;
            }

        }

        else{
            cout << "Invalid Action Selected ...! " << endl;
        }


    }


}