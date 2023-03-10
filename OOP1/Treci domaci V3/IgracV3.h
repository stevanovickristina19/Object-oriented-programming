#pragma once
#ifndef _igrac_h_
#define _igrac_h_
#include <iostream>
#include <string>
using namespace std;

class Igrac {
	string ime;
	double vrednost;
public:

	Igrac(string ime, int vrednost = 1000) : ime(ime), vrednost(vrednost) {}

	string dohv_ime() const { return ime; }
	double dohv_vrednost() const { return vrednost; }
	void menjaj_vrednost(double procenat) {
		this->vrednost = this->vrednost +  procenat / 100 * this->vrednost;
	}

	friend bool operator==(const Igrac& i1, const Igrac& i2) {
		if (i1.ime == i2.ime && i1.vrednost == i2.vrednost) return true;
		else return false;
	}
	friend ostream& operator<<(ostream& os, const Igrac& i) {
		os << i.ime << "#" << i.vrednost;
		return os;
	}
};
#endif // !_igrac_h_
