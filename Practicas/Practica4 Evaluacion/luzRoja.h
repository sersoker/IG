#ifndef _LUZROJA_H
#define _LUZROJA_H
#include "luz.h"

class LuzRoja: public Luz {
private:
	int alfa=0;
	int beta=0;
GLfloat Ambienter[4] 	= 	{ 1.0,0.0,0.0,1.0 };	
GLfloat Ambienteg[4] 	= 	{ 0.0,1.0,0.0,1.0 };	
GLfloat Ambienteb[4] 	= 	{ 0.0,0.0,1.0,1.0 };	

GLfloat Difusar[4] 		= 	{ 1.0,0.0,0.0,1.0 };	
GLfloat Difusag[4] 		= 	{ 0.0,1.0,0.0,1.0 };	
GLfloat Difusab[4] 		= 	{ 0.0,0.0,1.0,1.0 };	

GLfloat Especularr[4] 	= 	{ 1.0,0.0,0.0,1.0};		
GLfloat Especularg[4] 	= 	{ 0.0,1.0,0.0,1.0 };		
GLfloat Especularb[4] 	= 	{ 0.0,0.0,1.0,1.0 };		

GLfloat Posicionr[4] 	= 	{ 5.0,0.0,0.0,0.0};
GLfloat Posiciong[4] 	= 	{ 0.0,5.0,0.0,0.0 };
GLfloat Posicionb[4] 	= 	{ 0.0,0.0,5.0,0.0 };

public:
	//constructor
   	void inicia();
   	void aumentax();
   	void aumentay();
   	void disminuyex();
   	void disminuyey();
   	void enciendeLuz();
   	void mueveluces();

};
#endif