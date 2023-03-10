#pragma once
#ifndef _tim_h_
#define _tim_h_
#include "IgracV3.h"
#include "GreskaV3.h"
class Tim {
protected:
	string naziv;
	int max;
	Igrac** niz;
	int br_igraca = 0;
	int poslednji = 0;
	void kopiraj(const Tim& t);
	void premesti(Tim& t);
	void brisi() {
		for (int i = 0; i < max; i++) {
			niz[i] = nullptr;
		}
		delete[] niz;
	}
	
public:
	Tim(string naziv, int max){
		this->naziv = naziv;
		this->max = max;
		niz = new Igrac * [max] {nullptr};
	}
	Tim(const Tim& t) { kopiraj(t); }
	Tim(Tim&& t) { premesti(t); }
	Tim& operator=(const Tim& t) {
		if (this != &t) {
			brisi();
			kopiraj(t);
		}
		return *this;
	}
	Tim& operator=(Tim&& t) {
		if (this != &t) {
			brisi();
			premesti(t);
		}
		return *this;
	}

	int dohv_max() const { return max; }
	virtual void postavi_igraca(int i, Igrac& ig) {
		if (i < 0 || i > max - 1 || niz[i]!= nullptr) throw GPogresanIndex();
		
		niz[i] = &ig;
		br_igraca++;
		if (i > poslednji) poslednji = i;
	}
	int dohv_br_igraca() const { return this->br_igraca; }

	Igrac* operator[](int i) const {
		return niz[i];
	}

	double vrednost_tima() const ;
	friend bool operator==(const Tim& t1, const Tim& t2);
	friend ostream& operator<<(ostream& os, const Tim& t) {
		os << t.naziv << "[";
		for (int i = 0; i < t.max; i++) {
			if (t.niz[i] == nullptr) continue;
			if (t.niz[i] == t.niz[t.poslednji]) cout << *t[i] << "]";
			else cout << *t[i] << ", ";
		}
		os << endl;
		return os;
	}
	virtual ~Tim() { brisi(); }
		
};
#endif // !_tim_h_

