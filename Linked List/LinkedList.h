#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class T>
class Lista {
private:
	struct Obiekt {
		T dane;
		struct Obiekt* nastepny;
		struct Obiekt* poprzedni;
	};

	Obiekt* glowa;
	Obiekt* ogon;

public:
	Lista() {
		glowa = nullptr;
	}

	~Lista();

	void dodajNaKoncu(T);
	void dodajNaPoczatku(T);
	T wypisz(int, T);
	T zmien(int index, T dane, T wynik);
	T wyszukaj(T dane, T wynik);
	void usunPierwszy();
	void usunOstatni();
	T usunWyszukane(T dane, bool wynik);
	T dodaj(T dane, int index);


};

template <class T>
void Lista<T>::dodajNaKoncu(T dane) {
	Lista* nowyObiekt;
	Lista* obiektPtr;

	nowyObiekt = new Obiekt;
	nowyObiekt->dane = dane;
	nowyObiekt->nastepny = nullptr;

	if (!glowa) {
		glowa = nowyObiekt;
		nowyObiekt->poprzedni = nullptr;
	}
	else
	{
		obiektPtr = ogon;
		nowyObiekt->poprzedni = obiektPtr;
		obiektPtr->nastepny = nowyObiekt;
		ogon = nowyObiekt;
	}
};

template <class T>
void Lista<T>::dodajNaPoczatku(T dane) {
	Lista* nowyObiekt;
	Lista* obiektPtr;

	nowyObiekt = new Obiekt;
	nowyObiekt->dane = dane;
	nowyObiekt->poprzedni = nullptr;

	if (!glowa) {
		glowa = nowyObiekt;
		nowyObiekt->nastepny = nullptr;
	}
	else {
		obiektPtr = glowa;
		nowyObiekt->nastepny = obiektPtr;
		obiektPtr->poprzedni = nowyObiekt;
		glowa = nowyObiekt;
	}
};

template <class T>
T Lista<T>::wypisz(int index, T wynik) {
	Lista* obiektPtr;

	obiektPtr = glowa;

	for (int i = 0; i != index; i++) {
		if (obiektPtr == nullptr) {
			wynik = NULL;
		}
		else if (i != index){
			obiektPtr = obiektPtr->nastepny;
		}
		else {
			wynik = obiektPtr->dane;
		}
	}
};

#endif // !LINKEDLIST.H