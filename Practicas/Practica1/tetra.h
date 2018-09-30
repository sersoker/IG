#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include <vector>
#include "objeto3d.h"

#ifndef TETRA_H
#define TETRA_H

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
#include "tetra.cpp"

#endif
