#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "ply.h"
#include "base.h"

Base::Base(){
;
}

void Base::dibujar(int modo){
	Oply cubo2("cubo2");
	Oply cono2("cono2");
glPushMatrix();	
	glPushMatrix();	
		glPushMatrix();	
			glTranslatef(5.5,0,0);
			glScalef(0.5,1.1,0.5);
			if(modo!=3)	
			cono2.dibujar20(modo);
			else
			cono2.dibujar15(modo);
		glPopMatrix();	
		glPushMatrix();	
			glTranslatef(-5.5,0,0);
			glScalef(0.5,1.1,0.5);
			if(modo!=3)			
			cono2.dibujar20(modo);
			else
			cono2.dibujar15(modo);	
		glPopMatrix();	
	glPopMatrix();	
	glPushMatrix();	
		glScalef(10,0.1,10);
		glTranslatef(0,-1,0);
		if(modo!=3)		
		cubo2.dibujar20(modo);
		else
		cubo2.dibujar15(modo);
	glPopMatrix();	
glPopMatrix();	
}