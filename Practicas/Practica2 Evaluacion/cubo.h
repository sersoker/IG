#ifndef CUBO_H
#define CUBO_H

#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include <vector>
#include <iostream>
#include "objeto3d.h"

using namespace std;

class Cubo: public Objeto3d{

public:
	// Constructores.
	Cubo(int lado);
	Cubo(const Cubo & obj);
	Cubo(vector<GLfloat> & v,vector<GLint> & t,unsigned int n);
	
	//Funcion de cambio de lado
	void setLado(int lado);
		
};
#endif