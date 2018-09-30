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
	Orev(char * nombre,int divisiones, int modo);
	Orev(std::vector<GLfloat> &v,int divisiones, int modo);

	//Funciones
	void creaRevolucion(vector<GLfloat> &v,int divisiones, int modo);
	void cPuntoA(vector<GLfloat> & v,vector<GLfloat> & vertices);
	void cPuntoB(vector<GLfloat> & v,vector<GLfloat> & vertices);
	void calculaCaras(int particiones, int numeroPuntosInicial);
	void invertirVertices(vector<GLfloat> &v);
};

#endif
