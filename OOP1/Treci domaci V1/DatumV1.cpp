#include "DatumV1.h"

bool operator==(const Datum& d1, const Datum& d2)
{
    if (d1.dan == d2.dan && d1.mesec == d2.mesec && d1.godina == d2.godina) return true;
    else return false;
}
