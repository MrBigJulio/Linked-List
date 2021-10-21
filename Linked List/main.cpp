#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
	List<Object>* list = new List<Object>();
	Object* o = new Object();
	o->data1 = 222;
	o->data2 = 'a';
	list->addToEnd(*o);
	Object* o2 = new Object();
	o2->data1 = 333;
	o2->data2 = 'b';
	list->addToEnd(*o2);
	Object* o3 = new Object();
	o3->data1 = 111;
	o3->data2 = 'c';
	list->addToStart(*o3);
	list->print(2);
	Object* o4 = new Object();
	o4->data1 = 444;
	o4->data2 = 'd';
	list->edit(2, *o4);
	/*Object* o5 = new Object();
	Object* o6 = new Object();
	o5->data2 = 'e';
	o6 = list->search(*o5);		!!!!! Error in g)
	cout << o6->data1 << endl;
	cout << o6->data2 << endl;*/
	list->deleteLast();

	
};
