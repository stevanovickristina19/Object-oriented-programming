#pragma once
#ifndef _element_h_
#define	_element_h_
#include <iostream>
#include <string>
using namespace std;
class Element {

public:
	
	virtual char dohv_oznaku() const = 0;
	virtual string dohv_natpis() const = 0;
	virtual Element* kopija() = 0;

	friend ostream& operator<<(ostream& os, const Element& e) {
		os << e.dohv_natpis();
		return os;
	}
	virtual ~Element() {}

};
#endif // _element_h_

