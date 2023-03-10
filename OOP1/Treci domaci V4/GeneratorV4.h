#pragma once
#ifndef _generator_h_
#define _generator_h_
#include "IzrazV4.h"
#include "ElementV4.h"
#include "SabiranjeV4.h"
#include "BinarniOPV4.h"
class Generator {
	static int brojac;
	Izraz postfix;
	Izraz stek;
public:
	Generator() {
		brojac++;
		if (brojac > 1) throw GGenerator();
	}
	Generator(const Generator& g) = delete;
	Generator& operator=(const Generator& g) = delete;

	Izraz& generator(Izraz& i);

};
#endif // !_generator_h_
