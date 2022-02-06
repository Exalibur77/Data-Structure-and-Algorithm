// Product , Item and Cart Class is implemented over here.

#include<bits/stdc++.h>
using namespace std;


class Item;
class Cart;

class Product{
    int id;
    string name;
    int price;

    public:
    Product(){}
    Product(int id, string name , int price){
        this->id = id;
        this->name = name;
        this->price = price;
    }

    string getDisplayName(){
        return name + " : Rs. " + to_string(price);
    }

    string getName(){
        return name;
    }

    char getShortName(){
        return name[0];
    }

    friend class Item;
    friend class Cart;

};

class Item{

    Product product;
    int quantity;

    public:
    Item(){}
    Item(Product p,int x):product(p),quantity(x){}

    int getItemPrice(){
        // now we can use the price data memeber which is private in our class Item
        return quantity*product.price;
    }

    string getItemInfo(){
        return to_string(quantity) + " x " + product.name + " Rs. " + to_string(quantity*product.price) + '\n';
    }

    friend class Cart;

};

class Cart{

    unordered_map<int,Item> items;

    public:

    void addProduct(Product &p){

        // check if the product's item is present in my given map or not.

        // given product id is not present in the list
        if(items.find(p.id)!=items.end()){
            items[p.id].quantity++;
        }
        else{
            Item newItem(p,1);
            items[p.id] = newItem;
        }


    }

    int getTotal(){

        int total=0;

        for(auto &p : items){
            total += p.second.getItemPrice();
        }

        return total;

    }

    string ViewCart(){

        if(items.empty()){
            return "Cart is Empty.";
        }

        int cart_total = getTotal();
        
        string itemList;

        for(auto &p : items){
            itemList.append(p.second.getItemInfo()+'\n');
        }

        return itemList + "Total Amount ==> " + to_string(cart_total) + '\n';

    }
    
    bool isEmpty(){
        return items.empty();
    }


};