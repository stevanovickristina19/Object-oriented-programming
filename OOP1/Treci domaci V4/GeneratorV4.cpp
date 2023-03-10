#include "GeneratorV4.h"

Izraz& Generator::generator(Izraz& i)
{
    int br_zagrada = 0;
    int rank = 0;
    while (true) {
        if (i.dovh_br() == 0) break;
        Element* o = (*i).kopija();
        char check = o->dohv_oznaku();
        switch (check) {
        case 'D': {
            postfix.dodaj(o);
            rank++;
            break;
        }
        default: {
            if (br_zagrada < 0) throw GPostfixZagrade1();
            if (o->dohv_oznaku() == '(') {
                br_zagrada++;
                while (stek.dovh_br() > 0) {
                    Element* s = (-stek).kopija();
                    postfix.dodaj(s);
                    rank--;
                    
                }
                break;
            }
            if (stek.dovh_br() == 0 && o->dohv_oznaku() != ')') {
                stek.dodaj(o);
                break;
            }
            
            if (o->dohv_oznaku() != ')') {
                while (stek.dovh_br() > 0) {
                    Element* s = (-stek).kopija();
                    if (static_cast<Binarni*>(o)->dohv_prior() <= static_cast<Binarni*>(s)->dohv_prior()) {
                        postfix.dodaj(s);
                        rank--;

                    }
                    else {
                        stek.dodaj(s);
                        stek.dodaj(o);
                        break;
                    }

                    stek.dodaj(o);
                    break;
                }
            }
            else {
                br_zagrada--;
                break;
            }



        }

        }
       

    }
    while (stek.dovh_br() > 0) {
        Element* s = (-stek).kopija();
        postfix.dodaj(s);
        rank--;
    }
    if (rank != 1) throw GPostfix();
    if (br_zagrada != 0) throw GPostfixZagrade();
    return postfix;
}
