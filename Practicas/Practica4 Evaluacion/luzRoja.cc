#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "luzRoja.h"

void LuzRoja::inicia(){

//luz roja	
	glLightfv (GL_LIGHT2, GL_AMBIENT, Ambienter);
	glLightfv (GL_LIGHT2, GL_DIFFUSE, Difusar);
	glLightfv (GL_LIGHT2, GL_SPECULAR, Especularr);
	glLightfv (GL_LIGHT2, GL_POSITION, Posicionr); 	
//Luz verde
	glLightfv (GL_LIGHT3, GL_AMBIENT, Ambienteg);
	glLightfv (GL_LIGHT3, GL_DIFFUSE, Difusag);
	glLightfv (GL_LIGHT3, GL_SPECULAR, Especularg);
	glLightfv (GL_LIGHT3, GL_POSITION, Posiciong); 
//Luz azul
	glLightfv (GL_LIGHT4, GL_AMBIENT, Ambienteb);
	glLightfv (GL_LIGHT4, GL_DIFFUSE, Difusab);
	glLightfv (GL_LIGHT4, GL_SPECULAR, Especularb);
	glLightfv (GL_LIGHT4, GL_POSITION, Posicionb); 


}

void LuzRoja::aumentax(){
	Posicionr[0]++;
	Posiciong[0]++;
	Posicionb[0]++;
}

void LuzRoja::aumentay(){
		Posicionr[1]++;
		Posiciong[1]++;
		Posicionb[1]++;
}

void LuzRoja::disminuyex(){
		Posicionr[0]--;
		Posiciong[0]--;
		Posicionb[0]--;
}

void LuzRoja::disminuyey(){
		Posicionr[1]--;
		Posiciong[1]--;
		Posicionb[1]--;
}


void LuzRoja::enciendeLuz(){


	glEnable(GL_LIGHTING);
	glPushMatrix();
		glRotatef(10,0,0,1);
		glLightfv (GL_LIGHT2, GL_POSITION, Posicionr); 
		glEnable(GL_LIGHT2);
	glPopMatrix();
	glPushMatrix();
		glRotatef(50,0,0,1);
		glLightfv (GL_LIGHT3, GL_POSITION, Posiciong); 
		glEnable(GL_LIGHT3);
	glPopMatrix();
	glPushMatrix();
		glRotatef(100,0,0,1);
		glLightfv (GL_LIGHT4, GL_POSITION, Posicionb); 
		glEnable(GL_LIGHT4);
	glPopMatrix();	
}
