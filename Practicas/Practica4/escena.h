#ifndef _ESCENA_H
#define _ESCENA_H
#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "cubo.h"
#include "tetra.h"
#include "octa.h"
#include "ply.h"
#include "orevolucion.h"
#include "objetoCompuesto.h"
#include "ssolar.h"
#include "escenap4.h"
#include "luzDireccional.h"
#include "luzPosicional.h"

class Escena {
private:
// tamaño de los ejes
const int AXIS_SIZE=5000;

// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;
int figura=0;
int tipo=0;
int modoDibujo=0;
int divi=40;
int posicionTraslacion=0;
float velocidadGrado1=0;
int velocidadGrado2=0;
int velocidadGrado3=0;
bool activadaTraslacionAutomatica=false;
bool creados=false;


//Objetos
ObjetoCompuesto 			giroscopio;
Ssolar 						sistema;
Escenap4 					practica4;
Oply objetoPly=				Oply("perfil");
Orev objetoRevolucion=		Orev("perfil",divi,1);	
LuzDireccional 				luzDireccional;
LuzPosicional				luzPosicional;


// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Width,Height,Front_plane,Back_plane;

private:
	void clear_window();
	void draw_axis();
	void draw_objects(int lado,char* archivo);

//Transformación de cámara
	void change_projection();
	void change_observer();


public:
    Escena();
	void inicializar(int UI_window_width,int UI_window_height);
	void redimensionar(int newWidth,int newHeight) ;
	void idle();

	// Dibujar
	void dibujar(int lado,char* archivo) ;

	// Interacción con la escena
	int teclaPulsada(unsigned char Tecla1,int x,int y) ;
	void teclaEspecial(int Tecla1,int x,int y);
	void cambiarIluminacion();
	void creaIluminacion();
};
#endif
