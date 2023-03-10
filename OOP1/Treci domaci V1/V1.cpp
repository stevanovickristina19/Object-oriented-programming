#include "RacunV1.h"
#include "DatumV1.h"
#include "DinarskiRacunV1.h"


void main() {

	Datum d1(7, 9, 2000);
	Datum d2(9, 1, 2001);

	Osoba o1("Milan", "0709000781060", d1);
	Osoba o2("Aleksandra", "0901001781064", d2);
	cout << o1 << endl;
	Osoba* os1 = &o1;
	Osoba* os2 = &o2;

	Dinarski din1(os1, 1);

	din1 += 1000;
	cout << din1;

	Dinarski din2(os2, 163);
	
	din2 += 500;
	cout << din2;
	
	if (din1.izvrsi_prenos(500, din2)) {
		cout << "Prenos uspeo." << endl;
		cout << din1 << endl << din2 << endl;
	}
	else cout << "Prenos nije uspeo.";
}