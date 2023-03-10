#pragma once
#ifndef _par_h_
#define _par_h_
#include <iostream>
using namespace std;
template<typename T>
class Par {
	T* prvi;
	T* drugi;
public:
	Par(T& a, T& b) {
		prvi = &a;
		drugi = &b;
	}

	T& dohv_prvi() const { return *prvi; }
	T& dohv_drugi() const { return *drugi; }

	void postavi_priv(T& t) {
		prvi = &t;
	}
	void postavi_drugi(T& t) {
		drugi = &t;
	}

	friend bool operator==(const Par& p1, const Par& p2) {
		if (p1.dohv_prvi() == p2.dohv_prvi() && p1.dohv_drugi() == p2.dohv_drugi()) return true;
		else return false;
	}

	friend ostream& operator<<(ostream& os, const Par& p) {
		os << "[" << p.dohv_prvi() << "-" << p.dohv_drugi() << "]";
		return os;
	}
};

#endif // !_par_h_

