#ifndef _REVOLUCION_H
#define _REVOLUCION_H
#include "objeto3d.h"
#include "file_ply_stl.h"
#include <vector>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;

class Revolucion: public Objeto3D {

protected:
	char *ruta;
	int divisiones;
	const float pi = 3.14159265358979323846;
	float giro = (2*pi)/divisiones;
	float gradosAGirar = giro;

	int numero_de_vertices;

	int valor_altura;

	int altura_perfil;
	int altura_baja_perfil;

	vector<GLfloat> verticesQueNoSeGiran; 
	vector<GLfloat> verticesQueSiSeGiran;

public:
	Revolucion();
	Revolucion(char *rutaDeArchivo, int numeroDivisiones);
	void creaRevolucionAscendente(vector<GLfloat> listaVertices, int numeroDivisiones);
	void creaRevolucionDescendente(vector<GLfloat> listaVertices, int numeroDivisiones);
 	Revolucion operator= ( Revolucion objetoRevol );
	bool es_perfil();
	vector<GLfloat> getVertices();
	void crea_iteracion_perfil(int i, int j, int k, int l);
	void creaTapaderaSuperior();
	void creaTapaderaInferior();
	float gira(int divisiones);
	void aumentaDivisiones();
	void disminuyeDivisiones();
	bool estaEnEjeY(GLfloat vertice);
	bool sentidoAscendente(GLfloat inicio, GLfloat fin);
};
#endif