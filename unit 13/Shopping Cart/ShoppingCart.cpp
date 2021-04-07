#include "ShoppingCart.h"

ShoppingCart::ShoppingCart(){
    customerName = "default name";
}
ShoppingCart::ShoppingCart(string name){
    customerName = name;
}
string ShoppingCart::getCustomerName() const{
    return customerName;
}
void ShoppingCart::addItem(ItemToPurchase a){
    cartItems.push_back(a);
}
void ShoppingCart::removeItem(string a){
    bool found = false;
    for (size_t i = 0; i <cartItems.size(); i++){
        if (cartItems[i].getName() == a){
             cartItems.erase(cartItems.begin() + i);
             found = true;
        }
    }
    if (!found){
        cout <<"Item not found in cart. Nothing removed." <<endl;
    }
}
void ShoppingCart::changeQuantity(string a, int b){
    bool found = false;
    for (size_t i = 0; i <cartItems.size(); i++){
        if (cartItems[i].getName() == a){
            cartItems[i].setQuantity(b);
            found = true;
        }
    if (!found){
        cout <<"Item not found in cart. Nothing modified." <<endl;
    }
    }
}
double ShoppingCart::getTotalCost(){
    double sum = 0;
    for (size_t i = 0; i < cartItems.size(); i++){
        sum += cartItems[i].getQuantity() * cartItems[i].getPrice();
    }
    return sum;
}
void ShoppingCart::printCart(){
    cout << customerName<< "'s Shopping Cart" <<endl;
    cout << endl;

    for (size_t i = 0; i < cartItems.size(); i++){
        cartItems[i].printItemCost();
    }

    cout << "Total: $" << getTotalCost() <<endl;
}

