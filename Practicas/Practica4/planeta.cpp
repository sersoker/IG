#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "planeta.h"


void Planeta::dibujar(int modo,int identificador){
//Planeta Estandar
if(identificador==0){
	glPushMatrix();
	glRotatef(1,0,1,0);
		if(modo!=3)		esfera2.dibujar20(modo);
		else			esfera2.dibujar15(modo);
	glPopMatrix();
}
//Tierra con luna
else if(identificador==1){
	glPushMatrix();
	glRotatef(1,0,1,0);
		if(modo!=3)		esfera2.dibujar20(modo);
		else			esfera2.dibujar15(modo);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1,1,0);
	glRotatef(-1,0,1,0);
	glScalef(0.4,0.4,0.4);
	glColor3ub(153,153,153);
		if(modo!=3)		esfera2.dibujar20(modo);
		else			esfera2.dibujar15(modo);
	glPopMatrix();
}
//Saturno
else{
	glPushMatrix();
	glRotatef(1,0,1,0);
		if(modo!=3)		esfera2.dibujar20(modo);
		else			esfera2.dibujar15(modo);
	glPopMatrix();
	glPushMatrix();
	glRotatef(45,0,0,1);
	glScalef(1.5,0.1,1.5);
		if(modo!=3)		toroide2.dibujar20(modo);
		else			toroide2.dibujar15(modo);
	glPopMatrix();
}


}
