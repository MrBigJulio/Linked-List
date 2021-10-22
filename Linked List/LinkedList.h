#ifndef LINKEDLIST_H
#define LINKEDLIST_H
using namespace std;

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

	void addToEnd(T);				//a)
	void addToStart(T);				//b)
	void print(int);				//e)
	void edit(int, T);				//f)
	T search(T);					//g) to fix
	void deleteLast();				//c)
	void deleteFirst();				//d)
	bool searchAndDelete(T);		//h)
	~List();						//j)
	void add(int, T);				//i)
};

template <class T>
void List<T>::addToEnd(T objectData) {
	Object* newObject = new Object();
	Object* objectPrt;

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
	};
}

template <class T>
void List<T>::addToStart(T objectData) {
	Object* newObject = new Object();
	Object* objectPtr;
;
	newObject->data1 = objectData.data1;
	newObject->data2 = objectData.data2;
	size++;

	if (!head) {
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		objectPtr = head;
		newObject->next = objectPtr;
		objectPtr->prev = newObject;
		head = newObject;
	}
}

template <class T>
void List<T>::print(int index) {
	Object* objectPtr = head;
	int i = 0;

	while (i <= index) {
		if (objectPtr == nullptr) {
			cout << "Out of range!" << endl;
			break;
		}
		else if (i != index) {
			objectPtr = objectPtr->next;
		}
		else {
			cout << objectPtr->data1 << endl;
			cout << objectPtr->data2 << endl;
		}
		i++;
	};
}

template <class T>
void List<T>::edit(int index, T newData) {
	Object* objectPtr = head;

	int i = 0;

	while (i <= index) {
		if (objectPtr == nullptr) {
			cout << "Out of range!" << endl;
			break;
		}
		else if (i != index) {
			objectPtr = objectPtr->next;
		}
		else {
			objectPtr->data1 = newData.data1;
			objectPtr->data2 = newData.data2;
		}
		i++;
	};
}

template <class T>
T List<T>::search(T data) {
	Object* objectPtr = head;
	bool finished = false;

	while (finished != true) {
		if (objectPtr == nullptr) {
			//return *objectPtr;				
			cout << "ERROR" << endl;
			finished = true;
		}
		else if (objectPtr->data1 == data.data1 || objectPtr->data2 == data.data2) {
			return *objectPtr;
			finished = true;
		}
		else
		{
			objectPtr = objectPtr->next;
		}
	}
}

template <class T>
void List<T>::deleteLast() {
	Object* objectToDelete = tail;
	Object* objectPtr;
	
	if (objectToDelete == nullptr) {
		cout << "Empty list!" << endl;
	}
	else if (objectToDelete->next == nullptr && objectToDelete->prev == nullptr) {
		head = nullptr;
		tail = nullptr;
		delete objectToDelete;
		size--;
	}
	else {
		objectPtr = objectToDelete->prev;
		objectPtr->next = nullptr;
		tail = objectPtr;
		delete objectToDelete;
		size--;
	}
}

template <class T>
void List<T>::deleteFirst() {
	Object* objectToDelete = head;
	Object* objectPtr;

	if (objectToDelete == nullptr) {
		cout << "Empty list!" << endl;
	}
	else if (objectToDelete->next == nullptr && objectToDelete->prev == nullptr) {
		head = nullptr;
		tail = nullptr;
		delete objectToDelete;
		size--;
	}
	else {
		objectPtr = objectToDelete->next;
		objectPtr->prev = nullptr;
		head = objectPtr;
		delete objectToDelete;
		size--;
	}
}

template <class T>
bool List<T>::searchAndDelete(T data) {
	Object* objectToDelete = head;
	Object* objectPtr;
	bool finished = false;

	while (finished != true) {
		if (objectToDelete == nullptr) {
			cout << "ERROR" << endl;
			finished = true;
			return false;	
		}
		else if (objectToDelete->data1 == data.data1 || objectToDelete->data2 == data.data2) {
			if (objectToDelete->prev == nullptr && objectToDelete->next == nullptr) {
				head = nullptr;
				tail = nullptr;
				delete objectToDelete;
				size--;
			}
			else if (objectToDelete->prev == nullptr) {
				objectPtr = objectToDelete->next;
				objectPtr->prev = nullptr;
				head = objectPtr;
				delete objectToDelete;
				size--;
			}
			else if (objectToDelete->next == nullptr) {
				objectPtr = objectToDelete->prev;
				objectPtr->next = nullptr;
				tail = objectPtr;
				delete objectToDelete;
				size--;
			}
			else
			{
				objectPtr = objectToDelete->prev;
				objectPtr->next = objectToDelete->next;
				objectPtr = objectPtr->next;
				objectPtr->prev = objectToDelete->prev;
				delete objectToDelete;
				size--;
			}
			finished = true;
			return true;
		}
		else
		{
			objectToDelete = objectToDelete->next;
		}
	}
}

template <class T>
List<T>::~List() {
	Object* objectToDelete = head;
	Object* objectPtr;

	if (objectToDelete == nullptr) {
		cout << "Empty list!" << endl;
	}
	else
	{
		while (objectToDelete != nullptr)
		{
			objectPtr = objectToDelete->next;
			delete objectToDelete;
			objectToDelete = objectPtr;
			size--;
		}
		head = nullptr;
		tail = nullptr;
	}
}

template <class T>
void List<T>::add(int index, T objectData) {
	Object* newObject = new Object();
	Object* objectPtr;

	newObject->data1 = objectData.data1;
	newObject->data2 = objectData.data2;

	for (int i = 0; i <= index; i++) {

	}
}
#endif // !LINKEDLIST.H