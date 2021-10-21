#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class Object {
public:
	int data1;
	char data2;
	Object* next;
	Object* prev;

	Object() {
		next = nullptr;
		prev = nullptr;
	}
};

template <class T>
class List {
private:
	Object* head;
	Object* tail;
	int size;

public:
	List() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	};

	~List();

	void addToEnd(T);
	void addToStart(T);
	Object print(int, Object);
};

template <class T>
void List<T>::addToEnd(T objectData) {
	Object* newObject;
	Object* objectPrt;

	newObject = new Object;
	newObject->data1 = objectData.data1;
	newObject->data2 = objectData.data2;
	size++;

	if (!head) {
		head = newObject;
		tail = newObject;		
	}
	else
	{
		objectPrt = tail;
		newObject->prev = objectPrt;
		objectPrt->next = newObject;
		tail = newObject;
	}
}

#endif // !LINKEDLIST.H