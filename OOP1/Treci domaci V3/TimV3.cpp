#include "TimV3.h"

void Tim::kopiraj(const Tim& t)
{
	this->naziv = t.naziv;
	this->max = t.max;
	this->niz = new Igrac * [t.max]{ nullptr };
	for (int i = 0; i < t.max; i++) {
		niz[i] = t.niz[i];
	}
}

void Tim::premesti(Tim& t)
{
	this->naziv = t.naziv;
	this->max = t.max;
	this->niz = t.niz;
	for (int i = 0; i < t.max; i++) {
		niz[i] = nullptr;
	}
	niz = nullptr;
}

double Tim::vrednost_tima() const
{
	double sr_vrednost = 0;
	double uk_vrednost = 0;
	for (int i = 0; i < max; i++) {
		if (niz[i] == nullptr) continue;
		uk_vrednost += niz[i]->dohv_vrednost();
	}
	sr_vrednost = uk_vrednost / this->dohv_br_igraca();
	return sr_vrednost;
}

bool operator==(const Tim& t1, const Tim& t2)
{

	if (t1.naziv == t2.naziv && t1.max == t2.max) {
		for (int i = 0; i < t1.max; i++) {
			if (t1.niz[i] != nullptr && t2.niz[i] == nullptr) return false;
			if (t1.niz[i] == nullptr && t2.niz[i] != nullptr) return false;
			if (t1.niz[i] == nullptr && t2.niz[i] == nullptr) continue;
			if (t1.niz[i] != nullptr && t2.niz[i] != nullptr) {
				if (*t1.niz[i] == *t2.niz[i]) continue;
				else return false;
			}

		}
		return true;
	}
	else return false;
}
