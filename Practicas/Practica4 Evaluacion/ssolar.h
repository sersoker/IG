#ifndef _SSOLAR_H
#define _SSOLAR_H
#include "planeta.h"
class Ssolar {
private:
    int rotacion=0;
    Planeta planeta;
public:
	//constructor
   	Ssolar(){;}

    void aumentaRotacion(int numero,int aumento);
    void dibujar(int modo);

};
#endif
