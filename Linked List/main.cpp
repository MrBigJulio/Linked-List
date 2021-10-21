#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
	List<Object>* list = new List<Object>();
	Object* newObject = new Object();
	newObject->data1 = 123;
	newObject->data2 = 'a';
	list->addToEnd(*newObject);
	Object* newObject2 = new Object();
	newObject2->data1 = 312;
	newObject2->data2 = 'b';
	list->addToEnd(*newObject2);
	Object* newObject3 = new Object();
	newObject3->data1 = 231;
	newObject3->data2 = 'c';
	list->addToEnd(*newObject3);
};
