#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "ply.h"
#include "esfera.h"

Esfera::Esfera(){
;
}

void Esfera::dibujar(int grado1,int grado2,int modo){
	Oply toroide2("toroide2");
	Oply esfera2("esfera2");
	Oply cilindro2 ("cilindro2");

glPushMatrix();	
glTranslatef(0,5,0);
	glPushMatrix();	
		glRotatef(90,0,0,1);
		glPushMatrix();	
			glTranslatef(-2.4,-5.55,0);
			glScalef(2.5,0.1,0.1);
				if(modo!=3)			cilindro2.dibujar20(modo);
				else				cilindro2.dibujar15(modo);
		glPopMatrix();	
		glPushMatrix();	
			glTranslatef(-2.4,5.45,0);
			glScalef(2.5,0.1,0.1);
				if(modo!=3)			cilindro2.dibujar20(modo);
				else				cilindro2.dibujar15(modo);
		glPopMatrix();	
	glPopMatrix();	

	glPushMatrix();	
	glRotatef(grado1,1,0,0);	
		//Toroide exterior	
		glPushMatrix();	
			glScalef(4.5,4.5,1);
			glRotatef(90,1,0,0);
				if(modo!=3)		toroide2.dibujar20(modo);
				else			toroide2.dibujar15(modo);
		glPopMatrix();
		//Union toroide con base
		glPushMatrix();	
			glScalef(1,0.1,0.1);
			glTranslatef(0,0.3,0);	
			glPushMatrix();	
				glTranslatef(5,0,0);
				glRotatef(90,0,0,1);		
				glTranslatef(0,-0.5,0);
					if(modo!=3)			cilindro2.dibujar20(modo);
					else				cilindro2.dibujar15(modo);
			glPopMatrix();
			glPushMatrix();	
				glTranslatef(-5,0,0);
				glRotatef(90,0,0,1);		
				glTranslatef(0,-0.5,0);
					if(modo!=3)			cilindro2.dibujar20(modo);
					else				cilindro2.dibujar15(modo);
			glPopMatrix();	
		glPopMatrix();	
		
		//Toroide interior con nucleo
		glPushMatrix();	
		glRotatef(grado2,0,1,0);
			glPushMatrix();	
				glScalef(2.5,2.5,1);
				glRotatef(90,1,0,0);
					if(modo!=3)		toroide2.dibujar20(modo);
					else			toroide2.dibujar15(modo);
			glPopMatrix();
			glPushMatrix();	
					if(modo!=3)		esfera2.dibujar20(modo);
					else			esfera2.dibujar15(modo);
			glPopMatrix();
			//Union toroide toroide exterior
			glPushMatrix();	
				glScalef(0.1,1.5,0.1);
				//glTranslatef(0,0.3,0);	
				glPushMatrix();	
					glTranslatef(0,2.2,0);
					glTranslatef(0,-0.5,0);
						if(modo!=3)			cilindro2.dibujar20(modo);
						else				cilindro2.dibujar15(modo);
				glPopMatrix();
				glPushMatrix();	
					glTranslatef(0,-2.2,0);
					glTranslatef(0,-0.5,0);
						if(modo!=3)			cilindro2.dibujar20(modo);
						else				cilindro2.dibujar15(modo);
				glPopMatrix();	
			glPopMatrix();	

		glPopMatrix();

	glPopMatrix();	
glPopMatrix();

}