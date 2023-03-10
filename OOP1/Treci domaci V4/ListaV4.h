#pragma once
#ifndef _lista_h_
#define _lista_h_
#include <iostream>
#include "GreskaV4.h"
using namespace std;

template<typename T>
class Lista {

	struct Elem {
		T* info;
		Elem* next;
		Elem(T* t) {
			info = t;
			next = nullptr;
		}
	};
	Elem* head;
	Elem* tail;
	int br;
	void kopiraj(const Lista& l);
	void premesti(Lista& l) {
		head = l.head;
		tail = l.tail;
		l.head = l.tail = nullptr;
	}
	void brisi();
public:
	Lista() {
		head = tail = nullptr;
		br = 0;
	}
	Lista(const Lista& l) { kopiraj(l); }
	Lista(Lista&& l) { premesti(l); }
	~Lista() { brisi(); }
	Lista& operator=(const Lista& l) {
		if (this != &l) {
			brisi();
			kopiraj(l);
		}
		return *this;
	}
	Lista& operator=(Lista&& l) {
		if (this != &l) {
			brisi();
			premesti(l);
		}
		return *this;
	}

	Lista& dodaj(T* t) {
		Elem* node = new Elem(t);
		if (head == nullptr) head = node;
		else tail->next = node;
		tail = node;
		br++;
		return *this;
	}

	T& operator-() {
		if (head == nullptr) throw GPrazna();
		T* tmp;
		Elem* curr = head;
		if (head == tail) {
			tmp = tail->info;
			brisi();
		}
		else {
			while (curr->next != tail) curr = curr->next;

			Elem* brisi = tail;
			tmp = tail->info;

			tail = curr;
			tail->next = nullptr;


			delete brisi;
		}
		br--;
		return *tmp;
	}

	T& operator*() {
		if (head == nullptr) throw GPrazna();
		Elem* curr = head;
		head = head->next;
		
		T* tmp = curr->info;
		delete curr;
		br--;
		return *tmp;
	}

	int dovh_br() const { return br; }

	friend ostream& operator<<(ostream& os, const Lista& t) {
		for (Elem* curr = t.head; curr; curr = curr->next) {
			os << *(curr->info) << " ";
		}
		return os;
	}
	
};
template<typename T>
void Lista<T>::kopiraj(const Lista& l){
	head = tail = nullptr;

	for (Elem* tmp = l.head; tmp; tmp = tmp->next) {
		Elem* node = new Elem(tmp->info);
		if (head == nullptr) head = node;
		else tail->next = node;
		tail = node;
	
	}

}
template<typename T>
void Lista<T>::brisi() {
	while (head) {
		Elem* tmp = head;
		head = head->next;
		delete tmp;
	}
	tail = nullptr;
}

#endif // !_lista_h_

