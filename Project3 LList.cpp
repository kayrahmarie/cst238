#include "LList.h"

LList::LList()
{
	cout << "Default constructor getting invoked\n";
	first = NULL;
	last = NULL;
	size = 0;
}

void LList::copyList(const LList &origList)
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
		}// end while for creating nodes in the list
	}// end else for list not empty
}// end copy function

LList::LList(const LList &origList) // copy constructor
{
	first = NULL;
	copyList(origList);
}

const LList & LList::operator=(const LList&rhs)
{
	if(this != &rhs)
	{
		copyList(rhs);
	}

	return *this;
}

int LList::getSize()
{
	return size;
}

bool LList::emptyList()
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

void LList::print()
{	//printing a list
	Node *current = first;
	while(current != NULL)
	{
		cout << current->data << endl;
		current = current->next;
	}
}

void LList::insert(ElementType newData)
{	Node *newItem;
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
	//cout << "\nPrinting list in insert\n";
	//print();
	//cout << "Done printing list in insert\n";

	size++;
}

void LList::destroyList()
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

LList::~LList()
{
	cout << "\n****** DESTRUCTOR *************\n";
	destroyList();
	//if(!emptyList())
	//{
	//	Node *current = first;
	//	while(current != NULL)
	//	{
	//		current = current->next;
	//		delete first;
	//		first = current;
	//	}
	//}
}

void LList::erase(ElementType item)
{
	Node * current, * previous;
	current = previous = first;

	while(current != NULL)
	{
		if(current->data == item)
		{
			cout << "found item to delete!\n";
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
		cout << "Hey, " << item << " isn't in your list!\n";
	}
	else if(current == first) // we want to delete the first item
	{
		first = current->next;
		if(current == last) // handle case where it is also last item
		{					// deletion will create an empty list
			last = NULL;
		}
		delete current;
	}
	else if(current == last) // delete the last item in the list
	{
		last = previous;
		last->next = NULL;
		delete current;
	}
	else // we want to delete from the middle of the list
	{
		previous->next = current->next;
		delete current;
	}
}
