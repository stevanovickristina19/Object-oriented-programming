#pragma once
#ifndef _dinarski_h_
#define _dinarski_h_
#include "RacunV1.h"
class Dinarski : public Racun {
public:
	Dinarski(Osoba* vlasnik, int br) : Racun(vlasnik, br) {}
	string dohv_valutu() const { return "RSD"; }

};
#endif // !_dinarski_h_
