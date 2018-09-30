#ifndef OREV_H
#define OREV_H

#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include <vector>
#include "objeto3d.h"
#include "file_ply_stl.hpp"
#include <math.h>

using namespace std;

class Orev: public Objeto3d{

public:
	// Constructores.
	Orev(int l);
	Orev(char * nombre);
	Orev(vector<GLfloat> & v,vector<GLint> & t,unsigned int n);

	void crear(char * nombre, int divisiones, int eje );
	void cPuntoA(vector<GLfloat> & v,vector<GLfloat> & vertices);
	void cPuntoB(vector<GLfloat> & v,vector<GLfloat> & vertices);
	void calculaCaras(int particiones, int numeroPuntosInicial);
};

#endif
