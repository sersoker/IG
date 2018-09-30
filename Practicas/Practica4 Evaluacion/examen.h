#ifndef _EXA_H
#define _EXA_H
#include "orevolucion.h"
#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "ply.h"
#include <string>

class Examen {
private:
	//Identificadores para las texturas
	Orev peon=			Orev("p4/perfil",10,1);
	
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
   	Examen();
    void dibujar(int modo);
    void iniciaMateriales();
    void calcula();
    void cargaMaterial(material &mat);
    void cargaTexMad();
    void cargaTexLat();

};
#endif