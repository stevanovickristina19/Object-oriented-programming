#pragma once
#ifndef _privilegovanTim_
#define _privilegovanTim_h_
#include "TimV3.h"
#include "GreskaV3.h"

class PrivilegTim : public Tim {
	double min_vred;
public:
	PrivilegTim(string naziv, int max, double min) : Tim(naziv, max), min_vred(min) {}

	void postavi_igraca(int i, Igrac& ig) override {
		if (ig.dohv_vrednost() < min_vred) throw GMalaVrednost();
		niz[i] = &ig;
		br_igraca++;
		if (i > poslednji) poslednji = i;
	}
	friend ostream& operator<<(ostream& os, const PrivilegTim& t) {
		os << t.naziv << "(" << t.min_vred << ")[";
		for (int i = 0; i < t.max; i++) {
			if (t.niz[i] == nullptr) continue;
			if (t.niz[i] == t.niz[t.poslednji]) cout << *t[i] << "]";
			else cout << *t[i] << ", ";
		}
		os << endl;
		return os;
	}
};


#endif 
