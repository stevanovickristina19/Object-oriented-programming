#include "GeneratorV4.h"
#include "IzrazV4.h"
#include "ZagradaV4.h"
#include "SabiranjeV4.h"
#include "BinarniOPV4.h"
#include "OperandV4.h"


int Generator::brojac = 0;

void main() {
	try {
		Generator e1;
		Izraz infix;
		Operand A("A");
		Operand B("B");
		Operand C("C");
		Operand D("D");
		Sabiranje s;
		LZagrada l;
		DZagrada d;
		
		/*infix.dodaj(l.kopija());
		infix.dodaj(A.kopija());
		infix.dodaj(s.kopija());
		infix.dodaj(l.kopija());
		infix.dodaj(B.kopija());
		infix.dodaj(s.kopija());
		infix.dodaj(C.kopija());
		infix.dodaj(d.kopija());
		infix.dodaj(d.kopija());*/
		infix.dodaj(A.kopija());
		infix.dodaj(s.kopija());
		infix.dodaj(B.kopija());
		infix.dodaj(s.kopija());
		infix.dodaj(C.kopija());
		infix.dodaj(s.kopija());
		infix.dodaj(s.kopija());
		infix.dodaj(D.kopija());

		cout << infix << endl;
		Izraz postfix = e1.generator(infix);
		
		cout << postfix << endl;

	}
	catch (exception e) {
		cout << e.what() << endl;
	}
	cout << endl <<"Kraj progarama!" << endl;
}