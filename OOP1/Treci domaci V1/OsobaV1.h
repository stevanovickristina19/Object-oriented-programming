#pragma once
#ifndef _osoba_h_
#define _osoba_h_
#include "DatumV1.h"
#include <string>
class Osoba {
	string ime;
	string maticni_broj;
	Datum rodjenje;
public:
	Osoba(string ime, string mat, const Datum& d) : rodjenje(d) {
		this->ime = ime;
		maticni_broj = mat;
	}
	Osoba(const Osoba& o) = delete;
	Osoba& operator=(const Osoba& o) = delete;

	string dovh_ime() const { return ime; }
	string dohv_mat_br() const { return maticni_broj; }
	Datum dohv_rodjenje() const { return rodjenje; }

	friend ostream& operator<<(ostream& os, const Osoba& o) {
		os << "o(" << o.ime << ", " << o.maticni_broj << ", " << o.rodjenje << ")";
		return os;
	}
};
#endif // !_osoba_h_

