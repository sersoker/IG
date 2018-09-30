	
	ObjetoCompuesto::dibujar(grado1,grado2,traslacion){
		glPushMatrix();
			baseObjeto.dibujar();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0,traslacion,0);
			objetoEsfera.dibujar(grado1,grado2);
		glPopMatrix();

	}


	Esfera::dibujar(int grado1,int grado2){
		glPushMatrix();	
		glTranslatef(0,5,0);
			glPushMatrix();	
				glRotatef(90,0,0,1);
				glPushMatrix();	
					glTranslatef(-2.4,-5.55,0);
					glScalef(2.5,0.1,0.1);
						cilindro2.dibujar();
				glPopMatrix();	
				glPushMatrix();	
					glTranslatef(-2.4,5.45,0);
					glScalef(2.5,0.1,0.1);
						cilindro2.dibujar();	
				glPopMatrix();	
			glPopMatrix();	

			glPushMatrix();	
			glRotatef(grado1,1,0,0);	

					//Toroide exterior	
					glPushMatrix();	
						glScalef(4.5,4.5,1);
						glRotatef(90,1,0,0);
							toroide.dibujar();
					glPopMatrix();
					
					//Union toroide con base
					glPushMatrix();	
					glScalef(1,0.1,0.1);
					glTranslatef(0,0.3,0);	
					
						glPushMatrix();	
							glTranslatef(5,0,0);
							glRotatef(90,0,0,1);		
							glTranslatef(0,-0.5,0);
								cilindro.dibujar();
						glPopMatrix();
						
						glPushMatrix();	
							glTranslatef(-5,0,0);
							glRotatef(90,0,0,1);		
							glTranslatef(0,-0.5,0);
								cilindro.dibujar();
						glPopMatrix();
						
					glPopMatrix();	
					
					//Toroide interior con nucleo
					glPushMatrix();	
					glRotatef(grado2,0,1,0);
						glPushMatrix();	
							glScalef(2.5,2.5,1);
							glRotatef(90,1,0,0);
								toroide.dibujar();
						glPopMatrix();
						
						glPushMatrix();	
								esfera.dibujar();
						glPopMatrix();
						
						//Union toroide toroide exterior
						glPushMatrix();	
							glScalef(0.1,1.5,0.1);
							glPushMatrix();	
								glTranslatef(0,2.2,0);
								glTranslatef(0,-0.5,0);
								cilindro.dibujar();
							glPopMatrix();
							glPushMatrix();	
								glTranslatef(0,-2.2,0);
								glTranslatef(0,-0.5,0);
								cilindro.dibujar();
							glPopMatrix();	
						glPopMatrix();	
					glPopMatrix();
					
			glPopMatrix();	
		glPopMatrix();
	}


	Base::dibujar(){
		glPushMatrix();	
			glPushMatrix();	
				glPushMatrix();	
					glTranslatef(5.5,0,0);
					glScalef(0.5,1.1,0.5);
					cono.dibujar();
				glPopMatrix();	
				glPushMatrix();	
					glTranslatef(-5.5,0,0);
					glScalef(0.5,1.1,0.5);
					cono.dibujar();
				glPopMatrix();	
			glPopMatrix();	
			glPushMatrix();	
				glScalef(10,0.1,10);
				glTranslatef(0,-1,0);
				cubo.dibujar();	
			glPopMatrix();	
		glPopMatrix();	
	}