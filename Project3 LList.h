#include <iostream>
#include <string>
#include "Grocery.h"
using namespace std;

#ifndef LLIST
#define LLIST

typedef Grocery ElementType;

class LList
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
	LList();
	LList(const LList &origList);
	~LList();
	int getSize();
	bool emptyList();
	void print();
	void insert(ElementType newData);
	void destroyList();
	void copyList(const LList &origList);
	const LList & operator=(const LList&rhs);
	void erase(ElementType item);
};

#endif //LLIST
