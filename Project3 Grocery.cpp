//Kayla Peterson and Dylan Rolicheck

#include <iostream>
#include <string>
#include "Grocery.h"
using namespace std;


Grocery::Grocery(string f/*=" "*/, int a/*=0*/, bool o/*=false*/) //constructor
{
	food = f;
	organic = o;
	if (a < 0)
	{
		amt = 0;
	}
	else
	{
		amt = a;
	}
}
bool Grocery::getOrganic() const	// accessor for the organic member variable
{
	return organic;
}
string Grocery::getFood() const	// accessor for the food member variable
{
	return food;
}
int Grocery::getAmount() const	// accessor for the amt member variable
{
	return amt;
}
void Grocery::changeAmount(int change)	// updates the amt member variable by the int change
// note that change could be negative (reduce the amount to purchase) or
// positive (increase the amount to purchase)  You can't reduce by more than amt
{
	if(amt+change < 0)
	{
		cout << "That change won't work" << endl;
	}
	else 
	{
		cout << "Amount updated" << endl;
		amt+=change;
	}
}
void Grocery::setAmount(int newAmount)	// mutator for the amt member variable
{
	amt = newAmount;
}
void Grocery::setOrganic(bool org)		// mutator for the organic member variable
{
	organic = org;
}
void Grocery::setGrocery(string f, int a, bool o)	// updates all the member variables of a Grocery object
{
	food = f;
	if (a < 0)
	{
		amt = 0;
	}
	else
	{
		amt = a;
	}
	organic = o;
}
void Grocery::print() const
{
	if(getOrganic())
	{
		cout << getAmount() << " organic " << getFood() << endl;
	}
	else
	{
		cout << getAmount() << " " << getFood() << endl;
	}
}

// Place this code in Grocery.cpp and uncomment it
ostream & operator << (ostream & out, const Grocery &g)
{
    g.print();
    return out;
}

bool operator == (const Grocery &g1, const Grocery &g2)
{
    return (g1.getFood() == g2.getFood() && g1.getAmount() == g2.getAmount() && g1.getOrganic() == g2.getOrganic());
}
