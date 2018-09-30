#ifndef _BASE_H
#define _BASE_H
#include "ply.h"

class Base {
private:
	int grado;
	Oply cubo2=	Oply("cubo2");
	Oply cono2=	Oply("cono2");
public:
	//Constructor
    Base(){;}

    //Metodo dibujar del objeto
    void dibujar(int modo);

};
#endif