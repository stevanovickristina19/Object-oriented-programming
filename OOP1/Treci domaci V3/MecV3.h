#pragma once
#ifndef _mec_h_
#define _mec_h_
#include "ParV3.h"
#include "GreskaV3.h"
#include "TimV3.h"
#include "PrivilegovanTimV3.h"

class Mec {
	Par<Tim> par;
	string ishod_meca;
	static int poeni_pobednik ;
	static int poeni_gubitnik ;
	static int poeni_nereseno ;
public:
	Mec(Tim& t1, Tim& t2): par(t1,t2) {
		ishod_meca = "NEODIGRAN";
	}

	void odigraj_mec();
	bool proveri_ishod() const {
		if (ishod_meca == "NEODIGRAN") return false;
		else return true;
	}
	Par<Tim> dohv_par() const { return par; }
	Par<int>* dohv_poene() const;

	friend ostream& operator<<(ostream& os, const Mec& m) {
		if (m.ishod_meca == "NEODIGRAN") throw GMecNeodigran();
		os << "Domacin: "<< m.par.dohv_prvi() << "Gost: " << m.par.dohv_drugi() << m.ishod_meca;
		return os;
	}
};
#endif // !_mec_h_
