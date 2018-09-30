#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include <vector>
#include "objeto3d.h"

#ifndef TORO_H
#define TORO_H

using namespace std;

class Toroide: public Objeto3d{

public:
	// Constructores.
	Toroide(int lado);
	Toroide(const Toroide & obj);
	Toroide(vector<GLfloat> & v,vector<GLint> & t,unsigned int n);
	
	//Funcion de cambio de lado
	void setLado(int lado);
		
};
#include "toro.cpp"

#endif
