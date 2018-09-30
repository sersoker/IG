#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include <vector>

#ifndef OBJETO3D_H
#define OBJETO3D_H

using namespace std;

class Objeto3d {
protected:
	vector<GLfloat> vertices;
	vector<GLint> triangulos;
	unsigned int nTriangulos;

public:
	// Funcion para mandar los datos desde un vector.
	Objeto3d();
	Objeto3d(const Objeto3d & obj);
	Objeto3d(vector<GLfloat> & v,vector<GLint> & t,unsigned int n);

	//modificar	
	void setVertices(vector<GLfloat> &v);
	void setTriangulos(vector<GLint> &t);
	void setNTriangulos(int n);

	//obtener
	vector<GLfloat> getVertices();
	vector<GLint> getTriangulos();
	int getNTriangulos();

	// Dibujar
	void dibujar15(int tipo);
	void dibujar20(int tipo);
	bool empty();
	
};
#include "objeto3d.cpp"

#endif
