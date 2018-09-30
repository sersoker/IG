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
			glPolygonMode(GL_FRONT, GL_FILL);
;			break;
	case 1:
			glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
			break;
	case 2:
			glPolygonMode(GL_FRONT, GL_LINE);
			break;
}

	glBegin( GL_TRIANGLES );
		for( int i = 0	; i < nTriangulos ; i++ ){
			int valor=triangulos[i]*3;
			if(tipo==3){
				if((i%2)==0)
						glColor3f( 1.0, 0.0, 0.0 );
				else
						glColor3f( 0.0, 1.0, 1.0 );
			}
				glVertex3f(vertices[valor],vertices[valor+1],vertices[valor+2]);

				glVertex3f(vertices[valor+3],vertices[valor+4],vertices[valor+5]);

				glVertex3f(vertices[valor+6],vertices[valor+7],vertices[valor+8]);
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
