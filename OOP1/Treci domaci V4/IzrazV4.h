#pragma once
#ifndef _izraz_h_
#define _izraz_h_
#include "ListaV4.h"
#include "ElementV4.h"

class Izraz : public Lista<Element> {
public:

	Izraz* kopija() { return new Izraz(*this); }
	
};
#endif // !_izraz_h_
