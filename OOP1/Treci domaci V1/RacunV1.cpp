#include "RacunV1.h"

bool Racun::izvrsi_prenos(double iznos, Racun& r)
{
	if (this->naRacunu - iznos < 0) return false;
	this->naRacunu -= iznos;
	r.naRacunu += iznos;
	
	return true;
}
