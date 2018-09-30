#ifndef OCTA_H
#define OCTA_H

#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include <vector>
#include "objeto3d.h"

using namespace std;

class Octaedro: public Objeto3d{

public:
	// Constructores.
	Octaedro(int lado);
	Octaedro(const Octaedro & obj);
	Octaedro(vector<GLfloat> & v,vector<GLint> & t,unsigned int n);
	
	//Funcion de cambio de lado
	void setLado(int lado);
		
};

#endif
