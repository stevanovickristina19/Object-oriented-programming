#pragma once
#ifndef _binarni_h_
#define _binarni_h_
#include "ElementV4.h"

class Binarni : public Element {
public:

	virtual int dohv_prior() const = 0;
	char dohv_oznaku() const override { return 'O'; }
	
	friend bool operator>(const Binarni& b1, const Binarni& b2) {
		if (b1.dohv_prior() > b2.dohv_prior()) return true;
		else false;	
	}
	virtual ~Binarni() {}

};
#endif // !_binarni_h_

