
void Escenap4::importarTextura(string rutaImagen, GLuint &textura){
   //Cargamos la textura de la lata de cocola
  jpg::Imagen * imagen= NULL;
  imagen = new jpg::Imagen("text-madera.jpg");
  glGenTextures(1,&textura);
  glBindTexture(GL_TEXTURE_2D,textura);
  gluBuild2DMipmaps(GL_TEXTURE_2D,GL_RGB,imagen->tamX(),imagen->tamY(),GL_RGB,GL_UNSIGNED_BYTE,imagen->leerPixels());
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
  if (imagen != NULL){
    delete imagen;
  } 
}

void Escenap4::coordSTexturaAutomatica(GLuint &textura){
	GLfloat S[4] = {1,0,0,0};
	GLfloat T[4] = {0,-1,0,0};
	
	glBindTexture(GL_TEXTURE_2D, textura);
	glTexGeni( GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_S, GL_OBJECT_PLANE, S);
	glEnable(GL_TEXTURE_GEN_S);

	glTexGeni( GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
	glTexGenfv(GL_T, GL_OBJECT_PLANE, T);
	glEnable(GL_TEXTURE_GEN_T);

}


  void importarTextura(string rutaImagen, GLuint &textura);
  void coordSTexturaAutomatica(GLuint &textura);

//importarTextura("text-madera.jpg",idTextMadera);
//importarTextura("text-lata-1.jpg",idTextCoca);
  //coordSTexturaAutomatica(idTexCoca);