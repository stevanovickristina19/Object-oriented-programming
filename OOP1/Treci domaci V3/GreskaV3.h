#pragma once
#ifndef _greska_h_
#define _greska_h_
#include <exception>
using namespace std;

class GMalaVrednost : public exception {
public:
	GMalaVrednost() :exception("Greska: Igrac ima vrednost koja je manja od najmanje dozvoljene.") {}
};
class GMecNeodigran : public exception {
public:
	GMecNeodigran() :exception("Greska: Mec nije odigran.") {}
};
class GPogresanIndex : public exception {
public:
	GPogresanIndex() :exception("Greska: Nije moguce postaviti igraca na ovu poziciju.") {}
};

#endif // !_greska_h_

