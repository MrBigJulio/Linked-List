#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class T>
class Lista {
private:
	struct Wezel {
		T dane;
		struct Wezel* nastepny;
		struct Wezel* poprzedni;
	};

	Wezel* glowa;
	Wezel* ogon;

public:
	Lista() {
		glowa = nullptr
	}

	~Lista();

	dodajNaKoncu();
	dodajNaPoczatku();
	usunPierwszy();
	usunOstatni();
	wypisz();
	zmien();
	wyszukaj();
	usunWyszukane();
	dodaj();


};


#endif // !LINKEDLIST.H