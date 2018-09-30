#ifndef TETRA_H
#define TETRA_H

#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include <vector>
#include "objeto3d.h"

using namespace std;

class Tetraedro: public Objeto3d{

public:
	// Constructores.
	Tetraedro(int lado);
	Tetraedro(const Tetraedro & obj);
	Tetraedro(vector<GLfloat> & v,vector<GLint> & t,unsigned int n);
	
	//Funcion de cambio de lado
	void setLado(int lado);
		
};

#endif
