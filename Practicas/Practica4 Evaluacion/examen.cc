#include "examen.h"

Examen::Examen(){
	iniciaMateriales();
}

void Examen::cargaMaterial(material &mat){
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat.ambiente);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat.difusa);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat.especular);
	glMaterialf(GL_FRONT,GL_SHININESS,mat.brillo);	
}


void Examen::dibujar(int modo){

//Peon blanco, sin brillo
	cargaMaterial(materialBlanco);
		glPushMatrix();
			glTranslatef(0,0,0);
			glScalef(2,2,2);
			peon.dibujarN(modo);
		glPopMatrix();	//Peon blanco, sin brillo
	cargaMaterial(materialBlanco);
		glPushMatrix();
			glTranslatef(5,0,0);
			glScalef(2,2,2);
			peon.dibujarN(modo);
		glPopMatrix();	//Peon blanco, sin brillo
	cargaMaterial(materialBlanco);
		glPushMatrix();
			glTranslatef(-5,0,0);
			glScalef(2,2,2);
			peon.dibujarN(modo);
		glPopMatrix();	

}

void Examen::calcula(){
  ;
	
}

void Examen::cargaTexMad(){

if(textMadera==-1)
{  jpg::Imagen * imagen= NULL;
  imagen = new jpg::Imagen("text-madera.jpg");
  glGenTextures(1,&textMadera);
  glBindTexture(GL_TEXTURE_2D,textMadera);
  glTexImage2D(GL_TEXTURE_2D, 0, 3, imagen->tamX() , imagen->tamY() , 0, GL_RGB, GL_UNSIGNED_BYTE, imagen->leerPixels());
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
  if (imagen != NULL){
	delete imagen;
  } 
  cout << "ENTRA"<<endl;
}
  GLfloat s[4] = {1,0,0,0};
  GLfloat t[4] = {0,-1,0,0};

  glBindTexture(GL_TEXTURE_2D, textMadera);
  glTexGeni( GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
  glTexGenfv(GL_S, GL_OBJECT_PLANE, s);
  glEnable(GL_TEXTURE_GEN_S);

  glTexGeni( GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
  glTexGenfv(GL_T, GL_OBJECT_PLANE, t);
  glEnable(GL_TEXTURE_GEN_T);

}

void Examen::cargaTexLat(){

if(textCoca==-1){
  jpg::Imagen * imagen= NULL;
  imagen = new jpg::Imagen("text-lata-1.jpg");
  glGenTextures(1,&textCoca);
  glBindTexture(GL_TEXTURE_2D,textCoca);
  glTexImage2D(GL_TEXTURE_2D, 0, 3, imagen->tamX() , imagen->tamY() , 0, GL_RGB, GL_UNSIGNED_BYTE, imagen->leerPixels());
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
  if (imagen != NULL){
	delete imagen;
  } 
  cout << "ENTRA"<<endl;
}
  GLfloat s[4] = {1,0,0,0};
 GLfloat t[4] = {0,-1,0,1};

  glBindTexture(GL_TEXTURE_2D, textCoca);
  glTexGeni( GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
  glTexGenfv(GL_S, GL_OBJECT_PLANE, s);
  glEnable(GL_TEXTURE_GEN_S);

  glTexGeni( GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
  glTexGenfv(GL_T, GL_OBJECT_PLANE, t);
  glEnable(GL_TEXTURE_GEN_T);

}



void Examen::iniciaMateriales(){
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