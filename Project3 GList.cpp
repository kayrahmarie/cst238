//Kayla Peterson and Dylan Rolicheck

#include <iostream>
#include <string>
using namespace std;

#include "GList.h"
#include "Grocery.h"
#include "LList.h"

GList::GList()  // Default Constructor
{
	first= NULL;
	last = NULL;
	size = 0;
}
GList::GList(const GList &origList)  // Copy Constructor
{
	// Check to see if list we are copying too is not empty
	if(first != NULL) 
	{
		destroyList();
	}
	// Handle case where original list is empty
	if(origList.size == 0)
	{
		destroyList();
	}
	else 
	{
		size = origList.size;
		Node * origCurr = origList.first;
		Node * curr;
		Node * prev;

		// Copy over the first node
		curr = new (nothrow) Node;
		curr->data = origCurr->data;
		curr->next = NULL;
		first = last = curr;
		prev = curr;
		origCurr = origCurr->next;

		while(origCurr != NULL)
		{
			curr = new (nothrow) Node;
			if(curr == 0)
			{
				cout << "Can't allocate any more nodes!!!\n";
				exit(1);
			}

			curr->data = origCurr->data;
			curr->next = NULL;
			prev->next = curr;
			prev = curr;
			origCurr = origCurr->next;
		}
	}
}
GList::~GList()  // Destructor
{
	destroyList();
}
int GList:: getSize()  // Accessor for size member variable
{
	return size;
}
bool GList:: emptyList()  // returns true if the list is empty, false otherwise
{
	if(first == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void GList:: print()  // prints the list, one item per line
{
	//cout << "\nPRINTING GLIST\n\n";
	Node *current = first;
	while(current != NULL)
	{
		current->data.print();
		current = current->next;
	}
}
void GList::insert(ElementType newData) // inserts an existing grocery object into the list
{
	Node *newItem;
	newItem = new (nothrow) Node;
	if(newItem == 0)
	{
		cout << "No more room for the list!\n";
		exit(1);
	}

	newItem->data = newData;
	newItem->next = NULL;

	if(emptyList())
	{
		first = last = newItem;
	}
	else // already have items in the list
	{
		last->next = newItem; // add item after current last
		last = newItem; // new item becomes new last item
	}
	size++;
}
void GList::insert(string f, int a, bool o) // inserts a grocery object with the member variables set 
										// using the values of the function parameters
{
	Node *newItem;
	newItem = new (nothrow) Node;
	if(newItem == 0)
	{
		cout << "No more room for the list!\n";
		exit(1);
	}

	newItem->data = Grocery(f,a,o);
	newItem->next = NULL;

	if(emptyList())
	{
		first = last = newItem;
	}
	else // already have items in the list
	{
		last->next = newItem; // add item after current last
		last = newItem; // new item becomes new last item
	}

	size++;
}
void GList::destroyList() // completely empties out a list
{
	if(!emptyList())
	{
		Node *current = first;
		while(current != NULL)
		{
			current = current->next;
			delete first;
			first = current;
		}
	}
	first = last = NULL;
	size = 0;
}
void GList::copyList(const GList &origList)	// makes the current list a duplicate of origList
{
	// Check to see if list we are copying too is not empty
	if(first != NULL) 
	{
		destroyList();
	}
	// Handle case where original list is empty
	if(origList.size == 0)
	{
		destroyList();
	}
	else  // Original list is not empty
	{
		size = origList.size;
		Node * origCurr = origList.first;
		Node * curr;
		Node * prev;

		// Copy over the first node
		curr = new (nothrow) Node;
		curr->data = origCurr->data;
		curr->next = NULL;
		first = last = curr;
		prev = curr;
		origCurr = origCurr->next;

		while(origCurr != NULL)
		{
			curr = new (nothrow) Node;
			if(curr == 0)
			{
				cout << "Can't allocate any more nodes!!!\n";
				exit(1);
			}

			curr->data = origCurr->data;
			curr->next = NULL;
			prev->next = curr;
			prev = curr;
			origCurr = origCurr->next;
		}
	}
}
const GList & GList::operator=(const GList&rhs) // overloaded assignment operator
{
	if(this != &rhs)
	{
		copyList(rhs);
	}

	return *this;
}
void GList::erase(string findfood, bool o) // erases the object whose food and organic member variables
											// match the parameters from the list
{
	Node * current, * previous;
	current = previous = first;

	while(current != NULL)
	{
		if(current->data.getFood() == findfood && current->data.getOrganic() == o)
		{
			if(o)
			{
				cout << "\nErasing Organic " << findfood << ":\n";
			}
			else
			{
			cout << "\nErasing non-organic " << findfood << ":\n";
			}
			break;
		}

		previous = current;
		current = current->next;
	}

	if(first == NULL) // empty list
	{
		cout << "Hey, you can't delete from an empty list!\n";
	}
	else if(current == NULL) // item not in list
	{
		if(o)
		{
			cout << "Hey, organic " << findfood << " isn't in your list!\n";
		}
		else
		{
			cout << "Hey, " << findfood << " isn't in your list!\n";
		}
		
	}
	else if(current == first) // we want to delete the first item
	{
		first = current->next;
		if(current == last) // handle case where it is also last item
		{					// deletion will create an empty list
			last = NULL;
		}
		delete current;
		size--;
	}
	else if(current == last) // delete the last item in the list
	{
		last = previous;
		last->next = NULL;
		delete current;
		size--;
	}
	else // we want to delete from the middle of the list
	{
		previous->next = current->next;
		delete current;
		size--;
	}
}
void GList::updateItem(string f, int amount) // updates the amount requested of the item in the list whose food
										// member variable matches f by the amount amount.  (Should not let total
										// amount of object become negative.)
{
	Node * current, * previous;
	current = previous = first;

	while(current != NULL)
	{
		if(current->data.getFood() == f)
		{
			cout << "found item to update!\n";
			break;
		}

		previous = current;
		current = current->next;
	}
	if(first == NULL) // empty list
	{
		cout << "Hey, your list is empty!\n";
	}
	else if(current == NULL) // item not in list
	{
			cout << "Hey, " << f << " isn't in your list!\n";
	}
	else // updating item in list
	{
		current->data.changeAmount(amount);
	}

}
void GList::printByStore()  // Prints list by which store each item should be purchased at.  Breaks down to one of three stores
						// as follows:
	                    // Items that you need more than 20 of should be purchased at Costco
	                    // Anything that is organic, and you want fewer than 20 of should be purchased at Whole Foods
	                    // Everything else should be purchased at your favorite Grocery Store
						// See sample output for an example
{
	cout <<"\nPrinting list by store\n";

	Node * current, * previous;
	current = previous = first;

	cout << "\nAt Costco you should buy: \n";
	while(current != NULL)
	{
		if(current->data.getAmount()>20)
		{
			current->data.print();
		}
		previous = current;
		current = current->next;
	}

	current = previous = first;

	cout << "\nAt Whole Foods you should buy: \n";
	while(current != NULL)
	{
		if(current->data.getAmount()<20 && current->data.getOrganic())
		{
			current->data.print();
		}
		previous = current;
		current = current->next;
	}

	current = previous = first;

	cout << "\nAt Safeway you should buy: \n";
	while(current != NULL)
	{
		if(current->data.getAmount()<20 && current->data.getOrganic() == false)
		{
			current->data.print();
		}
		previous = current;
		current = current->next;
	}
}
