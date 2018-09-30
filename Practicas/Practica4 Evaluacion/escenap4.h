#ifndef _ESP4_H
#define _ESP4_H
#include "orevolucion.h"
#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "ply.h"
#include <string>

class Escenap4 {
private:
	//Identificadores para las texturas
	Orev peon=			Orev("p4/perfil",10,1);
	Orev cuerpoLata=	Orev("p4/lata-pcue",50,1);
	Orev culoLata=		Orev("p4/lata-pinf",50,1);
	Orev tapaLata=		Orev("p4/lata-psup",50,1);
	
	struct material {
		GLfloat ambiente[4] = 	{0.0,0.0,0.0,0.0};  
		GLfloat difusa[4] = 	{0.0,0.0,0.0,0.0};  
		GLfloat especular[4] = 	{0.0,0.0,0.0,0.0};
		float brillo =			0.0;
	} ;

	material materialNegro;	
	material materialBlanco;	
	material materialMetalico;	
	material materialMadera;
	GLuint textCoca=-1;
	GLuint textMadera=-1;
	

public:
	//constructor
   	Escenap4();
    void dibujar(int modo);
    void iniciaMateriales();
    void calcula();
    void cargaMaterial(material &mat);
    void cargaTexMad();
    void cargaTexLat();

};
#endif