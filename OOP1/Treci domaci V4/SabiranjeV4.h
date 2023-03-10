#pragma once
#ifndef _sabiranje_h_
#define _sabiranje_h_
#include "BinarniOPV4.h"
class Sabiranje : public Binarni {
public:
	
	string dohv_natpis() const override { return "+"; }
	Sabiranje* kopija() { return new Sabiranje(*this); }
	int dohv_prior() const override { return 1; }
	

};
#endif // !_sabiranje_h_

