#include "MecV3.h"

void Mec::odigraj_mec()
{
	if (par.dohv_prvi().vrednost_tima() > par.dohv_drugi().vrednost_tima()) ishod_meca = "POBEDA_DOMACIN";
	else {
		if (par.dohv_prvi().vrednost_tima() < par.dohv_drugi().vrednost_tima()) ishod_meca = "POBEDA_GOST";
		else ishod_meca = "NERESENO";
	}

	if (ishod_meca == "POBEDA_DOMACIN") {
		for (int i = 0; i < par.dohv_prvi().dohv_max(); i++) {
			if (par.dohv_prvi()[i] == nullptr) continue;
			par.dohv_prvi()[i]->menjaj_vrednost(+10);
		}
		for (int i = 0; i < par.dohv_drugi().dohv_max(); i++) {
			if (par.dohv_drugi()[i] == nullptr) continue;
			par.dohv_drugi()[i]->menjaj_vrednost(-10);
		}
	}
	if (ishod_meca == "POBEDA_GOST") {
		for (int i = 0; i < par.dohv_prvi().dohv_max(); i++) {
			if (par.dohv_prvi()[i] == nullptr) continue;
			par.dohv_prvi()[i]->menjaj_vrednost(-10);
		}
		for (int i = 0; i < par.dohv_drugi().dohv_max(); i++) {
			if (par.dohv_drugi()[i] == nullptr) continue;
			par.dohv_drugi()[i]->menjaj_vrednost(+10);
		}
	}
}

Par<int>* Mec::dohv_poene() const
{
	Par<int>* poeni = nullptr;
	
	if (ishod_meca == "NEODIGRAN") throw GMecNeodigran();
	if (ishod_meca == "POBEDA_DOMACIN") {
		poeni = new Par<int>(poeni_pobednik,poeni_gubitnik);
	}
	if (ishod_meca == "POBEDA_GOST") poeni = new Par<int>(poeni_pobednik, poeni_gubitnik);
	if (ishod_meca == "NERESECNO") poeni = new Par<int>(poeni_nereseno, poeni_nereseno);

	return poeni;
}


