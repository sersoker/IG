#ifndef _ESFE_H
#define _ESFE_H
#include "ply.h"

class Esfera {
private:
	int grado;
	Oply toroide2=	Oply("toroide2");
	Oply esfera2=	Oply("esfera2");
	Oply cilindro2=	Oply("cilindro2");
public:
	//Constructor
    Esfera(){;}

    //Metodo dibujar del objeto
    void dibujar(int grado1,int grado2,int modo);

};
#endif