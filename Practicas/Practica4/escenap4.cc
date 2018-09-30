#include "escenap4.h"

Escenap4::Escenap4(){
	iniciaMateriales();
}

void Escenap4::cargaMaterial(material &mat){
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat.ambiente);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat.difusa);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat.especular);
	glMaterialf(GL_FRONT,GL_SHININESS,mat.brillo);	
}


void Escenap4::dibujar(int modo){
//************ LATA COCACOLA************** //
	cargaMaterial(materialMetalico);
	glPushMatrix();
	glScalef(10,10,10);
		culoLata.dibujarN(modo);
		tapaLata.dibujarN(modo);
	glPopMatrix();

	glEnable(GL_TEXTURE_2D); 
	cargaMaterial(materialMetalico);
	glPushMatrix();
	glScalef(10,10,10);
		//cuerpoLata.calculaCoordenadasUniformesTextura();
		cuerpoLata.cargaTextura("text-lata-1.jpg");
		cuerpoLata.calculaCoorText();
		cuerpoLata.dibujarN(modo);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_TEXTURE_GEN_T); 
	glDisable(GL_TEXTURE_GEN_S);


//***********PEONES***************//
//Peon negro, con brillo
	cargaMaterial(materialNegro);
		glPushMatrix();
			glTranslatef(5,0,10);
			glScalef(2,2,2);
			peon.dibujarN(modo);
		glPopMatrix();	

//Peon blanco, sin brillo
	cargaMaterial(materialBlanco);
		glPushMatrix();
			glTranslatef(-5,0,0);
			glScalef(2,2,2);
			peon.dibujarN(modo);
		glPopMatrix();			

//Peon de madera, con brillo	
	glEnable(GL_TEXTURE_2D); 
	cargaMaterial(materialMadera);
	glPushMatrix();
		glTranslatef(0,0,5);
		glScalef(2,2,2);
		peon.cargaTextura("text-madera.jpg");
		peon.coorTextAuto();
		peon.dibujarN(modo);
	glPopMatrix();
	glDisable(GL_TEXTURE_GEN_T); 
	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_2D);


}

void Escenap4::iniciaMateriales(){
// Web materiales: http://www.real3dtutorials.com/tut00008.php
	//Material negro
	materialNegro.ambiente[0]=0.01; 	
	materialNegro.ambiente[1]=0.01; 	
	materialNegro.ambiente[2]=0.01;	
	materialNegro.ambiente[3]=0.01;
	materialNegro.difusa[0]=0.5; 		
	materialNegro.difusa[1]=0.5; 		
	materialNegro.difusa[2]=0.5;	
	materialNegro.difusa[3]=0.5;
	materialNegro.especular[0]=1.0; 	
	materialNegro.especular[1]=1.0; 	
	materialNegro.especular[2]=1.0;	
	materialNegro.especular[3]=1.0;
	materialNegro.brillo=38.5;

	//Material blanco
	materialBlanco.ambiente[0]=0.5; 	
	materialBlanco.ambiente[1]=0.5; 	
	materialBlanco.ambiente[2]=0.5;	
	materialBlanco.ambiente[3]=0.5;
	materialBlanco.difusa[0]=0.714; 		
	materialBlanco.difusa[1]=0.4284; 		
	materialBlanco.difusa[2]=0.58144;	
	materialBlanco.difusa[3]=1.0;
	materialBlanco.especular[0]=0.0; 	
	materialBlanco.especular[1]=0.0; 	
	materialBlanco.especular[2]=0.0;	
	materialBlanco.especular[3]=1.0;

	//Material metalico
	materialMetalico.ambiente[0]=0.2525; 	
	materialMetalico.ambiente[1]=0.2525; 	
	materialMetalico.ambiente[2]=0.2525;	
	materialMetalico.ambiente[3]=1.0;
	materialMetalico.difusa[0]=1.0; 	
	materialMetalico.difusa[1]=1.0; 	
	materialMetalico.difusa[2]=1.0;	
	materialMetalico.difusa[3]=1.0;
	materialMetalico.especular[0]=0.708273; 	
	materialMetalico.especular[1]=0.708273; 	
	materialMetalico.especular[2]=0.708273;	
	materialMetalico.especular[3]=1.0;
	materialMetalico.brillo=51.0;

	//Material madera
	materialMadera.ambiente[0]=0.0; 	
	materialMadera.ambiente[1]=0.0; 	
	materialMadera.ambiente[2]=0.0;	
	materialMadera.ambiente[3]=1.0;
	materialMadera.difusa[0]=1.0; 		
	materialMadera.difusa[1]=1.0; 		
	materialMadera.difusa[2]=1.0;	
	materialMadera.difusa[3]=1.0;
	materialMadera.especular[0]=1.0; 	
	materialMadera.especular[1]=1.0; 	
	materialMadera.especular[2]=1.0;	
	materialMadera.especular[3]=1.0;
	materialMadera.brillo=20.0;

}