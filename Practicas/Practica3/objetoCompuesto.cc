#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "ply.h"
#include "objetoCompuesto.h"
#include "cubo.h"
#include "base.h"
#include "esfera.h"

ObjetoCompuesto::ObjetoCompuesto(){
;
}

void ObjetoCompuesto::cambiaTraslacion(float numero){traslacion=numero;}
void ObjetoCompuesto::aumentaTraslacion(float numero){if(traslacion+numero<5&&traslacion+numero>0)traslacion+=numero;}
void ObjetoCompuesto::aumentaRotacion(int numero,int aumento){if(numero==1){rotacion1+=aumento;}
													if(numero==2){rotacion2+=aumento;} }

void ObjetoCompuesto::dibujar(int modo){
Base baseObjeto;	
	glPushMatrix();
		baseObjeto.dibujar(modo);
	glPopMatrix();
Esfera objetoEsfera;
	glPushMatrix();
		glTranslatef(0,traslacion,0);
		objetoEsfera.dibujar(rotacion1,rotacion2,modo);
	glPopMatrix();

}