//Kayla Peterson and Dylan Rolicheck

#include <iostream>
#include <string>
using namespace std;

#include "GList.h"
#include "Grocery.h"
#include "LList.h"

int main()
{
	Grocery item; // testing default constructor
	Grocery item2("carrots", 8, false); //testing constructor with perameters
	item2.print();
	cout << endl;
	item.setGrocery("eggs", 5, true); //testing set grocery function
	item.print();
	cout << endl;
	item.changeAmount(-3);//testing changeamt function should work
	item.print();
	cout << endl;
	item.changeAmount(4);//testing changeamt function should work
	item.print();
	cout << endl;
	item.changeAmount(-100);//testing change amt function shouldn't work
	item.print();

	cout << "\nGLIST STUFF\n";
	GList one; // testing default constructor
	one.insert("bacon",12,false); // testing insert fuction
	one.insert(item); 
	one.print(); // testing print function
	one.erase("bacon",false);
	one.print();
	one.updateItem("bacon",12); // test updating item not in list
	one.print();
	one.updateItem("eggs",-1200); //test updating eggs shouldn't work
	one.print();
	one.updateItem("eggs",12); // test updating eggs should work
	one.print();

	one.insert("Ketchup",50,false); //should print under Costco
	one.insert("Kumquat",3,false); //Should print under Safeway
	one.insert("Mustard",50,true); //Should print under Costco
	one.insert("Potato",7,true); //Should print under Whole Foods
	one.printByStore();
}
