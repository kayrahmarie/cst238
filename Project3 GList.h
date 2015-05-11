#include <iostream>
#include <string>
using namespace std;

#include "Grocery.h"
#include "LList.h"

#ifndef GLIST
#define GLIST

typedef Grocery ElementType;

class GList : public LList
{
private:
	class Node
	{
	public:
		ElementType data;
		Node * next;
	};
	
	Node *first;
	Node *last;
	int size;
public:
	GList();  // Default Constructor
	GList(const GList &origList);  // Copy Constructor
	~GList();  // Destructor
	int getSize();  // Accessor for size member variable
	bool emptyList();  // returns true if the list is empty, false otherwise
	void print();  // prints the list, one item per line
	void insert(ElementType newData); // inserts an existing grocery object into the list
	void insert(string f, int a, bool o); // inserts a grocery object with the member variables set 
										  // using the values of the function parameters
	void destroyList(); // completely empties out a list
	void copyList(const GList &origList);	// makes the current list a duplicate of origList
	const GList & operator=(const GList&rhs); // overloaded assignment operator
	void erase(string findfood, bool o=false); // erases the object whose food and organic member variables
											   // match the parameters from the list
	void updateItem(string f, int amount);  // updates the amount requested of the item in the list whose food
										    // member variable matches f by the amount amount.  (Should not let total
										    // amount of object become negative.)
	void printByStore();  // Prints list by which store each item should be purchased at.  Breaks down to one of three stores
						  // as follows:
	                      // Items that you need more than 20 of should be purchased at Costco
	                      // Anything that is organic, and you want fewer than 20 of should be purchased at Whole Foods
	                      // Everything else should be purchased at your favorite Grocery Store
						  // See sample output for an example
};

#endif //GList
