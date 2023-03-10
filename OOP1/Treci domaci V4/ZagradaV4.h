#pragma once
#ifndef _zagrada_h_
#define _zagrada_h_
#include "ElementV4.h"
class LZagrada : public Element {
public:
	char dohv_oznaku() const override { return '('; }
	string dohv_natpis() const override { return "("; }
	LZagrada* kopija() override { return new LZagrada(*this); }

};
class DZagrada : public Element {
public:
	char dohv_oznaku() const override { return ')'; }
	string dohv_natpis() const override { return ")"; }
	DZagrada* kopija() override { return new DZagrada(*this); }

};


#endif // !_zagrada_h_

