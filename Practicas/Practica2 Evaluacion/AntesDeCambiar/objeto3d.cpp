#include "objeto3d.h"
//******************************************************
// Funcion para mandar los datos desde un vector.
Objeto3d::Objeto3d(){
	;
}

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
void Objeto3d::setVertices(vector<GLfloat> &v){
	vertices=v;
}

void Objeto3d::setTriangulos(vector<GLint> &t){
	triangulos=t;
}

void Objeto3d::setNTriangulos(int n){
	nTriangulos=n;
}


//******************************************************
//*********************Obtener**************************	
vector<GLfloat> Objeto3d::getVertices(){
	return vertices;
}

vector<GLint> Objeto3d::getTriangulos(){
	return triangulos;
}

int Objeto3d::getNTriangulos(){
	return nTriangulos;
}


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

bool Objeto3d::empty(){
	return nTriangulos==0;
}

//GL_enable (gl_cull_face)
