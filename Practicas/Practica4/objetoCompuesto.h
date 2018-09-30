#ifndef _OBJCOMP_H
#define _OBJCOMP_H
#include "base.h"
#include "esfera.h"
class ObjetoCompuesto {
private:
    float traslacion=0;
    int rotacion1=0;
    int rotacion2=0;
	Base baseObjeto;	
	Esfera objetoEsfera;

public:
	//constructor
   	ObjetoCompuesto(){;}
    void dibujar(int modo);
    void cambiaTraslacion(float numero);
    void aumentaTraslacion(float numero);
    void aumentaRotacion(int numero,int aumento);

};
#endif