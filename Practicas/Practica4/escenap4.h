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
	Orev peon=			Orev("perfil",10,1);
	Orev cuerpoLata=	Orev("lata-pcue",50,1);
	Orev culoLata=		Orev("lata-pinf",50,1);
	Orev tapaLata=		Orev("lata-psup",50,1);
	
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
	void cargaMaterial(material &mat);

};
#endif