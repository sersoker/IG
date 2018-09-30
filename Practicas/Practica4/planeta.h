#ifndef _PLANE_H
#define _PLANE_H
#include "ply.h"

class Planeta {
private:
	int grado;
	Oply toroide2=	Oply("toroide2");
	Oply esfera2=	Oply("esfera2");
public:
	//Constructor
    Planeta(){;}

    //Metodo dibujar del objeto
    void dibujar(int modo,int identificador);

};
#endif
