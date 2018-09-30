#ifndef OBJETO3D_H
#define OBJETO3D_H

#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include <vector>
#include <math.h>
#include <iostream>
#include "jpg_imagen.hpp"
#include <string> 


using namespace std;

class Objeto3d {
protected:
	vector<GLfloat> vertices;
	vector<GLfloat> normalesCaras;
	vector<GLfloat> normalesVertices;
	vector<GLint> triangulos;
	unsigned int nTriangulos;
	GLuint identificadorTextura=0;
	GLuint textura=0;
	jpg::Imagen * imagen;

public:
	// Funcion para mandar los datos desde un vector.
	Objeto3d(){;}
	Objeto3d(const Objeto3d & obj);
	Objeto3d(vector<GLfloat> & v,vector<GLint> & t,unsigned int n);

	//modificar	
	void setVertices(vector<GLfloat> &v);
	void setTriangulos(vector<GLint> &t);
	void setNTriangulos(int n);
	void cargaTextura(std::string rutaArchivo);
	void calculaCoordenadasTextura();
	void calculaNormales();

	//obtener
	vector<GLfloat> getVertices();
	vector<GLint> getTriangulos();
	int getNTriangulos();

	// Dibujar
	void dibujar15(int tipo);
	void dibujar20(int tipo);
	void dibujarN(int tipo);
	void dibujarNC(int tipo);
	bool empty();
	
};

#endif