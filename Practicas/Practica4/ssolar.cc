#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "ply.h"
#include "ssolar.h"

void Ssolar::aumentaRotacion(int numero,int aumento){if(numero==1){rotacion+=aumento;}	 }

void Ssolar::dibujar(int modo){
//Sol
	glColor3ub(255,255,0);
	glPushMatrix();
	glRotatef(5*rotacion,0,1,0);
		glScalef(5,5,5);
		planeta.dibujar(modo,0);
	glPopMatrix();
//Mercurio
	glColor3ub(204,204,204);
	glPushMatrix();
	glRotatef(4.5*rotacion,0,1,0);
		glTranslatef(8,0,0);
		planeta.dibujar(modo,0);
	glPopMatrix();
//Venus
	glColor3ub(204,153,51);
	glPushMatrix();
	glRotatef(4*rotacion,0,1,0);
		glTranslatef(11,0,0);
		glScalef(1.4,1.4,1.4);
		planeta.dibujar(modo,0);
	glPopMatrix();

//Tierra
	glColor3ub(0,255,255);
	glPushMatrix();
	glRotatef(3.5*rotacion,0,1,0);
		glTranslatef(14,0,0);
		glScalef(1.2,1.2,1.2);
		planeta.dibujar(modo,1);
	glPopMatrix();

//Marte
	glColor3ub(153,0,0);
	glPushMatrix();
	glRotatef(3*rotacion,0,1,0);
		glTranslatef(17,0,0);
		glScalef(1.1,1.1,1.1);
		planeta.dibujar(modo,0);
	glPopMatrix();

//Jupiter
	glColor3ub(102,51,0);
	glPushMatrix();
	glRotatef(2.5*rotacion,0,1,0);
		glTranslatef(17,0,0);
		glScalef(1.1,1.1,1.1);
		planeta.dibujar(modo,0);
	glPopMatrix();

//Saturno
	glColor3ub(204,153,51);
	glPushMatrix();
	glRotatef(2*rotacion,0,1,0);
		glTranslatef(20,0,0);
		glScalef(2.4,2.4,2.4);
		planeta.dibujar(modo,3);
	glPopMatrix();

//Urano
	glColor3ub(153,204,204);
	glPushMatrix();
	glRotatef(1.8*rotacion,0,1,0);
		glTranslatef(25,0,0);
		glScalef(1.4,1.4,1.4);
		planeta.dibujar(modo,0);
	glPopMatrix();

//Neptuno
	glColor3ub(0,204,204);
	glPushMatrix();
	glRotatef(1.4*rotacion,0,1,0);
		glTranslatef(27,0,0);
		glScalef(1.4,1.4,1.4);
		planeta.dibujar(modo,0);
	glPopMatrix();

//Pluton
	glColor3ub(0,0,102);
	glPushMatrix();
	glRotatef(1.2*rotacion,0,1,0);
		glTranslatef(30,0,0);
		glScalef(0.8,0.8,0.8);
		planeta.dibujar(modo,0);
	glPopMatrix();

}
