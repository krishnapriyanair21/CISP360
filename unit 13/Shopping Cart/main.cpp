#include "ShoppingCart.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>


int main(){
    cout << fixed << setprecision(2);
    string name;
    int price;
    int qty;

    cout << "Name:  ";
    getline(cin, name);


    ShoppingCart peep(name);
    ItemToPurchase object;


    for (int i = 0; i < 3; i++){
        cout << "Enter the item name: " <<endl;
        getline(cin, name);
        cout << "Enter the item price: " <<endl;
        cin >> price;
        cout << "Enter the item quantity: " <<endl;
        cin >> qty;

        cin.ignore();
        cout << endl;

        object.setName(name);
        object.setPrice(price);
        object.setQuantity(qty);

        peep.addItem(object);

    }
    peep.printCart();

    return 0;
}
