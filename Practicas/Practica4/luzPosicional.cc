#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "luzPosicional.h"


void LuzPosicional::inicia(){
	GLfloat posAmbient[4] = { 0.5, 0.5, 0.5, 1.0 };		
	GLfloat posDiffuse[4] = { 1.0, 1.0, 1.0, 1.0 };	
	GLfloat posSpecular[4] = { 0.0, 0.0, 1.0, 1.0 };	
	GLfloat posPosition[4] = { 0.0, 0.0, 1.0, 0.0 };
	
	Ambiente[0]=posAmbient[0];	
	Ambiente[1]=posAmbient[1];	
	Ambiente[2]=posAmbient[2];	
	Ambiente[3]=posAmbient[3];

	Difusa[0]=posDiffuse[0];	
	Difusa[1]=posDiffuse[1];	
	Difusa[2]=posDiffuse[2];	
	Difusa[3]=posDiffuse[3];

	Especular[0]=posSpecular[0];	
	Especular[1]=posSpecular[1];	
	Especular[2]=posSpecular[2];	
	Especular[3]=posSpecular[3];

	Posicion[0]=posPosition[0];	
	Posicion[1]=posPosition[1];	
	Posicion[2]=posPosition[2];	
	Posicion[3]=posPosition[3];

	glLightfv (GL_LIGHT0, GL_AMBIENT, Ambiente);
	glLightfv (GL_LIGHT0, GL_DIFFUSE, Difusa);
	glLightfv (GL_LIGHT0, GL_SPECULAR, Especular);
	glLightfv (GL_LIGHT0, GL_POSITION, Posicion); 

}

void LuzPosicional::enciendeLuz(){
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv (GL_LIGHT0, GL_POSITION, Posicion); 

}

