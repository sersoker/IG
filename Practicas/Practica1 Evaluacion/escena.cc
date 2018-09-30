#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "escena.h"
#include "cubo.h"
#include "tetra.h"
#include "octa.h"
#include "toro.h"

Cubo cub(1);
Tetraedro tet(1);
Octaedro octae(1);
Toroide tor(1);


Escena::Escena(){
    Front_plane=50;
    Back_plane=2000;
    Observer_distance = 4*Front_plane;
    Observer_angle_x = Observer_angle_y=0;
    glEnable(GL_CULL_FACE);

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
void Escena::draw_objects() {
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
			if(modoDibujo==0)tor.dibujar15(tipo);
			else tor.dibujar20(tipo);
		break;
	}
}

void Escena::setLado(int l){
	cub.setLado(l);
	tet.setLado(l);
	octae.setLado(l);
	tor.setLado(l);
}

void Escena::dibujar() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	change_observer();
	draw_axis();
	draw_objects();
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
		case 'D':
			figura=4;
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
void Escena::change_projection()  {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-Width,Width,-Height,Height,Front_plane,Back_plane);
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
	//Eje x
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);	
	glBegin(GL_LINE_LOOP);
	glColor3f(0.1,0,0);
	glVertex3f(0,0,0);	glVertex3f(AXIS_SIZE,0,0);	glVertex3f(AXIS_SIZE,3,0);	glVertex3f(0,3,0);	glVertex3f(0,0,0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.5,0,0);
	glVertex3f(0,0,-3);	glVertex3f(AXIS_SIZE,0,-3);	glVertex3f(AXIS_SIZE,3,-3);	glVertex3f(0,3,-3);	glVertex3f(0,0,-3);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.7,0,0);	
	glVertex3f(0,0,0);		glVertex3f(0,0,-3);	glVertex3f(AXIS_SIZE,0,-3);	glVertex3f(AXIS_SIZE,0,0);	glVertex3f(0,0,0);	
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1,0,0);
	glVertex3f(0,3,0);	glVertex3f(0,3,-3);	glVertex3f(AXIS_SIZE,3,-3);	glVertex3f(AXIS_SIZE,3,0);	glVertex3f(0,3,0);
	glEnd();

//Eje y
	glBegin(GL_LINE_LOOP);
	glColor3f(0,0.1,0);
	glVertex3f(0,0,0);	glVertex3f(0,AXIS_SIZE,0);	glVertex3f(3,AXIS_SIZE,0);	glVertex3f(3,0,0);	glVertex3f(0,0,0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0,0.5,0);
	glVertex3f(0,0,-3);	glVertex3f(0,AXIS_SIZE,-3);	glVertex3f(3,AXIS_SIZE,-3);	glVertex3f(3,0,-3);	glVertex3f(0,0,-3);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0,0.7,0);	
	glVertex3f(0,0,0);		glVertex3f(0,0,-3);	glVertex3f(0,AXIS_SIZE,-3);	glVertex3f(0,AXIS_SIZE,0);	glVertex3f(0,0,0);	
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0,1,0);
	glVertex3f(3,0,0);	glVertex3f(3,0,-3);	glVertex3f(3,AXIS_SIZE,-3);	glVertex3f(3,AXIS_SIZE,0);	glVertex3f(3,0,0);
	glEnd();

//Eje z
	glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0.1);
	glVertex3f(0,0,0);	glVertex3f(0,0,AXIS_SIZE);	glVertex3f(3,0,AXIS_SIZE);	glVertex3f(3,0,0);	glVertex3f(0,0,0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0.5);
	glVertex3f(0,3,0);	glVertex3f(0,3,AXIS_SIZE);	glVertex3f(3,3,AXIS_SIZE);	glVertex3f(3,3,0);	glVertex3f(0,3,0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0,0,0.7);	
	glVertex3f(0,0,0);		glVertex3f(0,0,-3);	glVertex3f(0,-3,AXIS_SIZE);	glVertex3f(0,0,AXIS_SIZE);	glVertex3f(0,0,0);	
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0,0,1);
	glVertex3f(3,0,0);	glVertex3f(3,0,-3);	glVertex3f(3,-3,AXIS_SIZE);	glVertex3f(3,0,AXIS_SIZE);	glVertex3f(3,0,0);
	glEnd();

}