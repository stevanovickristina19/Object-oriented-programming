#include "TimV3.h"
#include "PrivilegovanTimV3.h"
#include "ParV3.h"
#include "MecV3.h"

int Mec::poeni_pobednik = 3;
int Mec::poeni_gubitnik = 0;
int Mec::poeni_nereseno = 1;
void main() {
	try {
		Igrac i1("Marko", 900);
		Igrac i2("Milan", 1000);
		Igrac i3("Milica", 700);
		Igrac i4("Dusan", 500);
		
		Tim t1("Manojlovic", 5);

		t1.postavi_igraca(0, i1);
		t1.postavi_igraca(4, i2);
		
		
		Igrac* pok = t1[0];
		cout << *pok << endl;

		cout << t1;

		
		PrivilegTim t2("Golubovic", 5,400);
		t2.postavi_igraca(0, i3);
		t2.postavi_igraca(1, i4);
		cout << t2;

		
		Mec m(t1, t2);

		m.odigraj_mec();
		
		Par<int>* p = m.dohv_poene();
		
		cout << m;
		cout << *p << endl;
		
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
	cout << endl << "Kraj programa..." << endl;
}