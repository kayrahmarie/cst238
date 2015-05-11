#include <iostream>
#include <string>
using namespace std;

#ifndef GROCERY
#define GROCERY

class Grocery
{
private:
	string food;    // the name of the grocery item e.g. "bacon"
	int amt;		// the number of that item you need to buy at the store
	bool organic;	// true if the item should be organic, false otherwise
public:
	Grocery(string f=" ", int a=0, bool o=false); //constructor
	bool getOrganic() const;	// accessor for the organic member variable
	string getFood() const;	// accessor for the food member variable
	int getAmount() const;	// accessor for the amt member variable
	void changeAmount(int change);	// updates the amt member variable by the int change
    // note that change could be negative (reduce the amount to purchase) or
    // positive (increase the amount to purchase)  You can't reduce by more than amt
	void setAmount(int newAmount);	// mutator for the amt member variable
	void setOrganic(bool org);		// mutator for the organic member variable
	void setGrocery(string f, int a, bool o);	// updates all the member variables of a Grocery object
	void print() const; // prints a grocery object as shown in the sample output
};

ostream & operator << (ostream & out, const Grocery &g);
bool operator == (const Grocery &g1, const Grocery &g2);

#endif

