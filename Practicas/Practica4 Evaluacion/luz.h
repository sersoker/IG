#ifndef _LUZ_H
#define _LUZ_H

class Luz {
protected:
	GLfloat Ambiente[4] 	= 	{ 0.0,0.0,0.0,0.0 };	
	GLfloat Difusa[4] 		= 	{ 0.0,0.0,0.0,0.0 };	
	GLfloat Especular[4] 	= 	{ 0.0,0.0,0.0,0.0 };		
	GLfloat Posicion[4] 	= 	{ 0.0,0.0,0.0,0.0 };

public:
	//constructor
   	Luz(){;}
	void apagaLuz();
};
#endif