#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "escena.h"
#include "cubo.h"
#include "tetra.h"
#include "octa.h"
#include "ply.h"
#include "orevolucion.h"



Escena::Escena(){
	Front_plane=50;
	Back_plane=1000;
	Observer_distance = 4*Front_plane;
	Observer_angle_x = Observer_angle_y=0;

}

void Escena::inicializar(int UI_window_width,int UI_window_height) {
	glClearColor(1,1,1,1);// se indica cual sera el color para limpiar la ventana	(r,v,a,al)

	glEnable(GL_DEPTH_TEST);	// se habilita el z-bufer

	this->change_projection();
	Width=UI_window_width/10;
	Height=UI_window_height/10;
	glViewport(0,0,UI_window_width,UI_window_height);

}

//**************************************************************************
// Funcion que dibuja objetos en la escena
//***************************************************************************
void Escena::draw_objects(int lado,char* archivo) {
	Cubo cub(lado);
	Tetraedro tet(lado);
	Octaedro octae(lado);
	Oply objetoPly(archivo);
	Orev objetoRevolucion(archivo,divi,1);	

	switch (figura){
		case 1:
			if(modoDibujo==0)cub.dibujar15(tipo);
			else cub.dibujar20(tipo);
		break;
		case 2:
			if(modoDibujo==0)tet.dibujar15(tipo);
			else tet.dibujar20(tipo);
		break;
		case 3:
			if(modoDibujo==0)octae.dibujar15(tipo);
			else octae.dibujar20(tipo);
		break;
		case 4:
			if(modoDibujo==0)objetoPly.dibujar15(tipo);
			else objetoPly.dibujar20(tipo);
		break;
		case 5:
			if(modoDibujo==0)objetoRevolucion.dibujar15(tipo);
			else objetoRevolucion.dibujar20(tipo);
		break;
	}
}


void Escena::dibujar(int lado,char* archivo) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	glEnable(GL_CULL_FACE);
	change_observer();
	draw_axis();
	draw_objects(lado,archivo);
}


int Escena::teclaPulsada(unsigned char Tecla1,int x,int y) {
	std::cout << "Tecla: " << Tecla1<< std::endl;
	unsigned char tecla= toupper(Tecla1);

	switch (tecla){
		default:
			return 0;
		case 'Q':
			return 1;
			break;
		case 'C':
			figura=1;
			return 0;
			break;
		case 'T':
			figura=2;
			return 0;
			break;
		case 'O':
			figura=3;
			return 0;
			break;
		case 'A':
			figura=4;
			return 0;
			break;
		case 'R':
			figura=5;
			return 0;
			break;
		case '+':
			divi++;
			return 0;
			break;
		case '-':
			if(divi>4)divi--;
			return 0;
			break;
		
		case '0':
			tipo=0;
			return 0;
			break;
		case '1':
			tipo=1;
			return 0;
			break;
		case '2':
			tipo=2;
			return 0;
			break;
		case '3':
			tipo=3;
			return 0;
			break;
		
		case 'V':
			modoDibujo=0;
			return 0;
			break;
		case 'N':
			modoDibujo=1;
			return 0;
			break;
	}
	std::cout << "MODODIBUJO: " << tipo<< std::endl;
	std::cout << "DIVI:" << divi;

}

void Escena::teclaEspecial(int Tecla1,int x,int y) {
switch (Tecla1){
	case GLUT_KEY_LEFT:Observer_angle_y--;break;
	case GLUT_KEY_RIGHT:Observer_angle_y++;break;
	case GLUT_KEY_UP:Observer_angle_x--;break;
	case GLUT_KEY_DOWN:Observer_angle_x++;break;
	case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
	case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;
	}

	//std::cout << Observer_distance << std::endl;
}


//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************
void Escena::change_projection(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glFrustum(-Width,Width,-Height,Height,Front_plane,Back_plane);
	//Cambiar la linea superior por
	glOrtho(-Width/4,Width/4,-Height/4,Height/4 ,Front_plane,Back_plane);
}


void Escena::redimensionar(int newWidth,int newHeight) {
	change_projection();
	Width=newWidth/10;
	Height=newHeight/10;
	glViewport(0,0,newWidth,newHeight);
}


//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************
void Escena::change_observer() {
	// posicion del observador
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0,0,-Observer_distance);
	glRotatef(Observer_angle_x,1,0,0);
	glRotatef(Observer_angle_y,0,1,0);
}


//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************
void Escena::draw_axis(){
	glBegin(GL_LINES);
	// eje X, color rojo
	glColor3f(1,0,0);
	glVertex3f(-AXIS_SIZE,0,0);
	glVertex3f(AXIS_SIZE,0,0);
	// eje Y, color verde
	glColor3f(0,1,0);
	glVertex3f(0,-AXIS_SIZE,0);
	glVertex3f(0,AXIS_SIZE,0);
	// eje Z, color azul
	glColor3f(0,0,1);
	glVertex3f(0,0,-AXIS_SIZE);
	glVertex3f(0,0,AXIS_SIZE);
	glEnd();
}
