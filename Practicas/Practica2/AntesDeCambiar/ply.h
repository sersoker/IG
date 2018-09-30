#ifndef OPLY_H
#define OPLY_H

#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include <vector>
#include "objeto3d.h"
#include "file_ply_stl.hpp"

using namespace std;

class Oply: public Objeto3d{

public:
	// Constructores.
	Oply(int l);
	Oply(char * nombre);
	Oply(vector<GLfloat> & v,vector<GLint> & t,unsigned int n);

	void crear(char * nombre);
};

#endif
