#include "objeto3d.h"
//******************************************************
// Funcion para mandar los datos desde un vector.

Objeto3d::Objeto3d(const Objeto3d & obj){
	vertices=obj.vertices;
	triangulos=obj.triangulos;
	nTriangulos=obj.nTriangulos;
}

Objeto3d::Objeto3d(vector<GLfloat> & v,vector<GLint> & t,unsigned int n){
	vertices=v;
	triangulos=t;
	nTriangulos=n;
}

//******************************************************
//*********************Modificar************************	
void Objeto3d::setVertices(vector<GLfloat> &v){	vertices=v;}

void Objeto3d::setTriangulos(vector<GLint> &t){	triangulos=t;}

void Objeto3d::setNTriangulos(int n){	nTriangulos=n;}


//******************************************************
//*********************Obtener**************************	
vector<GLfloat> Objeto3d::getVertices(){	return vertices;}

vector<GLint> Objeto3d::getTriangulos(){	return triangulos;}

int Objeto3d::getNTriangulos(){	return nTriangulos;}


//******************************************************
//*********************Dibujar************************
void Objeto3d::dibujar15(int tipo){
switch (tipo){
	case 0:
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL)
;			break;
	case 1:
			glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
			break;
	case 2:
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			break;
}

	glBegin( GL_TRIANGLES );
		for( int i = 0	; i < nTriangulos*3 ; i+=3 ){
			int valor=triangulos[i]*3;
			int valor2=triangulos[i+1]*3;
			int valor3=triangulos[i+2]*3;

			if(tipo==3){
				if((i%2)==0)
						glColor3f( 1.0, 0.0, 0.0 );
				else
						glColor3f( 0.0, 1.0, 1.0 );
			}
				glVertex3f(vertices[valor],vertices[valor+1],vertices[valor+2]);
				glVertex3f(vertices[valor2],vertices[valor2+1],vertices[valor2+2]);
				glVertex3f(vertices[valor3],vertices[valor3+1],vertices[valor3+2]);
		}
	glEnd() ;
}


void Objeto3d::dibujar20(int tipo){
switch (tipo){
	case 0:
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			break;
	case 1:
			glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
			break;
	case 2:
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			break;
}
	glEnableClientState( GL_VERTEX_ARRAY ); // habilitar ’vertex arrays’
	// especificar puntero a tabla de coords. de vértices
	glVertexPointer( 3, GL_FLOAT, 0, &(vertices[0]) );
	// dibujar usando vértices indexados
	glDrawElements( GL_TRIANGLES, 3*nTriangulos, GL_UNSIGNED_INT, &(triangulos[0]) );
 }


void Objeto3d::dibujarN(int tipo){
  switch (tipo){
    case 0:
        glPolygonMode(GL_FRONT, GL_FILL);
        break;
    case 1:
        glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
        break;
    case 2:
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        break;
  }
  glEnableClientState( GL_VERTEX_ARRAY ); // habilitar ’vertex arrays’
  glEnableClientState( GL_NORMAL_ARRAY ); // habilitar 'normal arrays’
  // especificar puntero a tabla de coords. de vértices
  glVertexPointer( 3, GL_FLOAT, 0, &(vertices[0]) );
  glNormalPointer( GL_FLOAT,0,&(normalesVertices[0])  );
  // dibujar usando vértices indexados
  glDrawElements( GL_TRIANGLES, 3*nTriangulos, GL_UNSIGNED_INT, &(triangulos[0]) );
 }

void Objeto3d::dibujarNC(int tipo){
  switch (tipo){
    case 0:
        glPolygonMode(GL_FRONT, GL_FILL);
        break;
    case 1:
        glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
        break;
    case 2:
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        break;
  }
  glEnableClientState( GL_VERTEX_ARRAY ); // habilitar ’vertex arrays’
  glEnableClientState( GL_NORMAL_ARRAY ); // habilitar 'normal arrays’
  // especificar puntero a tabla de coords. de vértices
  glVertexPointer( 3, GL_FLOAT, 0, &(vertices[0]) );
  glNormalPointer( GL_FLOAT,0,&(normalesCaras[0])  );
  // dibujar usando vértices indexados
  glDrawElements( GL_TRIANGLES, 3*nTriangulos, GL_UNSIGNED_INT, &(triangulos[0]) );
 }



//Consulta si el objeto existe
bool Objeto3d::empty(){	
  return nTriangulos==0;
}

//Funcion para el calculo de normales
void Objeto3d::calculaNormales(){
	normalesVertices.clear();
	normalesCaras.clear();
	
  vector<int> N(vertices.size()/3);
	fill(N.begin(), N.end(), 0.0);

    normalesVertices.resize(vertices.size());
    fill(normalesVertices.begin(), normalesVertices.end(), 0.0);
 
    normalesCaras.resize(triangulos.size());
    fill(normalesCaras.begin(), normalesCaras.end(), 0.0);
 

    for(int i = 0; i < triangulos.size(); i+=3){
    //Vertices almacenados en triangulos
           int v0 = triangulos[i];  int v1 = triangulos[i+1]; int v2 = triangulos[i+2];
 		//Acceso
           float Ax =  vertices[v0*3]; float Ay =  vertices[v0*3+1]; float Az =  vertices[v0*3+2];
           float Bx =  vertices[v1*3]; float By =  vertices[v1*3+1]; float Bz =  vertices[v1*3+2];
           float Cx =  vertices[v2*3]; float Cy =  vertices[v2*3+1]; float Cz =  vertices[v2*3+2];
    //Calculo
          
         float ABx = Bx - Ax;           float ABy = By - Ay;           float ABz = Bz - Az;
         float BCx = Cx - Bx;           float BCy = Cy - By;           float BCz = Cz - Bz;
    
          normalesCaras[i]   +=  ABy * BCz - ABz * BCy;
          normalesCaras[i+1] +=  ABz * BCx - ABx * BCz;
          normalesCaras[i+2] +=  ABx * BCy - ABy * BCx;
          float normalizador=sqrt(normalesCaras[i]*normalesCaras[i]+
                                  normalesCaras[i+1]*normalesCaras[i+1]+
                                  normalesCaras[i+2]*normalesCaras[i+2]);

          normalesCaras[i]   /=  normalizador;
          normalesCaras[i+1] /=  normalizador;
          normalesCaras[i+2] /=  normalizador;

    //Almacenando valores para las normales de los vertices
           normalesVertices[v0*3]   +=  normalesCaras[i];
           normalesVertices[v0*3+1] +=  normalesCaras[i+1];
           normalesVertices[v0*3+2] +=  normalesCaras[i+2];
           N[v0]++;
 
           normalesVertices[v1*3]   +=  normalesCaras[i];
           normalesVertices[v1*3+1] +=  normalesCaras[i+1];
           normalesVertices[v1*3+2] +=  normalesCaras[i+2];
           N[v1]++;           

           normalesVertices[v2*3]   +=  normalesCaras[i];
           normalesVertices[v2*3+1] +=  normalesCaras[i+1];
           normalesVertices[v2*3+2] +=  normalesCaras[i+2];
           N[v2]++;


        }
 
        for(int i = 0; i < N.size(); i++){
           normalesVertices[i*3]/= (float) N[i];
           normalesVertices[i*3+1]/= (float) N[i];
           normalesVertices[i*3+2]/= (float) N[i];
           float normalizador=sqrt(normalesVertices[i]*normalesVertices[i]+
                                  normalesVertices[i+1]*normalesVertices[i+1]+
                                  normalesVertices[i+2]*normalesVertices[i+2]);

           normalesVertices[i*3]/= normalizador;
           normalesVertices[i*3+1]/= normalizador;
           normalesVertices[i*3+2]/= normalizador;

        }
}


void Objeto3d::cargaTextura(std::string rutaArchivo){
  //No funciona
  glEnable(GL_TEXTURE_2D); 
  cout << textura << endl;
  jpg::Imagen * imagen= NULL;
  imagen = new jpg::Imagen("text-lata-1.jpg");
  glGenTextures(1,&textura);
  cout << textura << endl;
  glBindTexture(GL_TEXTURE_2D,textura);
  cout << textura << endl;
  glTexImage2D(GL_TEXTURE_2D, 0, 3, imagen->tamX() , imagen->tamY() , 0, GL_RGB, GL_UNSIGNED_BYTE, imagen->leerPixels());
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
  if (imagen != NULL){
    delete imagen;
  } 
  GLfloat s[4] = {1,0,0,0};
  GLfloat t[4] = {0,-1,0,0};
  
  glBindTexture(GL_TEXTURE_2D, textura);
  glTexGeni( GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
  glTexGenfv(GL_S, GL_OBJECT_PLANE, s);
  glEnable(GL_TEXTURE_GEN_S);

  glTexGeni( GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
  glTexGenfv(GL_T, GL_OBJECT_PLANE, t);
  glEnable(GL_TEXTURE_GEN_T);
}

void Objeto3d::calculaCoordenadasTextura(){
  //No funciona
  GLfloat S[4] = {1,0,0,0};
  GLfloat T[4] = {0,-1,0,0};
   if (identificadorTextura==-1){
    cout << "\nprueba" << endl;
  cout << "ID:"<<identificadorTextura<<endl;
    glBindTexture(GL_TEXTURE_2D, identificadorTextura);
    glTexGeni( GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    glTexGenfv(GL_S, GL_OBJECT_PLANE, S);
    glEnable(GL_TEXTURE_GEN_S);

    glTexGeni( GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
    glTexGenfv(GL_T, GL_OBJECT_PLANE, T);
    glEnable(GL_TEXTURE_GEN_T);
    cout << "ID:"<<identificadorTextura;
  }
}
