#pragma once
#ifndef _greska_h_
#define _greska_h_
#include <exception>
using namespace std;

class GPrazna : public exception {
public:
	GPrazna() : exception("Greska: Lista je prazna.") {}
};
class GPostfix : public exception {
public:
	GPostfix() : exception("Greska: U infixu postoji isti ili veci broj binarnih operatora od operanada.") {}
};
class GGenerator : public exception {
public:
	GGenerator() : exception("Greska: Moguce je napraviti samo jedan generator izraza.") {}
};
class GPostfixZagrade : public exception {
public:
	GPostfixZagrade() : exception("Greska: U infixu postoji razlicit broj ulaznih i izlaznih zagrada.") {}
};
class GPostfixZagrade1 : public exception {
public:
	GPostfixZagrade1() : exception("Greska: U infixu je zadata zatvorena zagrada pre otvorene.") {}
};
#endif // !_greska_h_
