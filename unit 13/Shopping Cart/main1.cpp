#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "ItemToPurchase.h"

int main1()
{
    cout << fixed << setprecision(2);
    ItemToPurchase objectA;
    ItemToPurchase objectB;
    string name;
    int price;
    int qty;
    int total;

    cout << "Enter the item name: " <<endl;
    getline(cin, name);
    cout << "Enter the item price: " <<endl;
    cin >> price;
    cout << "Enter the item quantity: " <<endl;
    cin >> qty;

    objectA.setName(name);
    objectA.setPrice(price);
    objectA.setQuantity(qty);
    cin.ignore();
    cout<<endl;

    cout << "Enter the item name: " <<endl;
    getline(cin, name);
    cout << "Enter the item price: " <<endl;
    cin >> price;
    cout << "Enter the item quantity: " <<endl;
    cin >> qty;

    objectB.setName(name);
    objectB.setPrice(price);
    objectB.setQuantity(qty);
    cin.ignore();
    cout<<endl;

    objectA.printItemCost();
    objectB.printItemCost();
    cout << endl;

    total = (objectA.getPrice()*objectA.getQuantity()) + (objectB.getPrice()*objectB.getQuantity());

    cout << "Total: $" <<total <<".00"<<endl;

}
