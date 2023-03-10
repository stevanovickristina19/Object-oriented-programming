#pragma once
#ifndef _operand_h_
#define _operand_h_
#include "ElementV4.h"
class Operand : public Element {
	string natpis;
public:
	Operand(string natpis) : natpis(natpis) {}

	char dohv_oznaku() const override { return 'D'; }
	string dohv_natpis() const override { return this->natpis; }
	Operand* kopija() override { return new Operand(*this); }

};
#endif // !_operand_h_
