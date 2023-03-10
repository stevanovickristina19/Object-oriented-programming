#pragma once
#ifndef _racun_h_
#define _racun_h_
#include "OsobaV1.h"

class Racun {
	Osoba* vlasnik;
	int br_racuna;
	double naRacunu;
	
public:
	Racun(Osoba* o, int br): br_racuna(br) {
		vlasnik = o;
		naRacunu = 0;
	}
	virtual string dohv_valutu() const = 0;
	Osoba& dohv_vlasnik() { return *vlasnik; }
	int dohv_br_racuna() const { return br_racuna; }
	double dovh_naRacunu() const { return naRacunu; }
	

	Racun& operator+=(double iznos) {
		this->naRacunu += iznos;
		return *this;
	}
	bool izvrsi_prenos(double iznos, Racun& r);

	friend ostream& operator<<(ostream& os, const Racun& r) {
		os << "R: " << r.br_racuna << ":=:" << r.naRacunu << "-" << r.dohv_valutu() << endl;
		return os;
	}

	virtual ~Racun() {}
};
#endif // !_racun_h_

