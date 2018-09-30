#include "octa.h"

//Constructores
Octaedro::Octaedro(int lado){

	vertices.push_back(lado);vertices.push_back(0);vertices.push_back(0);	
	vertices.push_back(0);vertices.push_back(-lado);vertices.push_back(0);
	vertices.push_back(-lado);vertices.push_back(0);vertices.push_back(0);	
	vertices.push_back(0);vertices.push_back(lado);vertices.push_back(0);	
	vertices.push_back(0);vertices.push_back(0);vertices.push_back(lado);	
	vertices.push_back(0);vertices.push_back(0);vertices.push_back(-lado);


	triangulos.push_back(4);triangulos.push_back(0);triangulos.push_back(1);	
	triangulos.push_back(4);triangulos.push_back(1);triangulos.push_back(2);	
	triangulos.push_back(4);triangulos.push_back(2);triangulos.push_back(3);	
	triangulos.push_back(4);triangulos.push_back(3);triangulos.push_back(0);	
	triangulos.push_back(5);triangulos.push_back(1);triangulos.push_back(0);	
	triangulos.push_back(5);triangulos.push_back(2);triangulos.push_back(1);	
	triangulos.push_back(5);triangulos.push_back(3);triangulos.push_back(2);	
	triangulos.push_back(5);triangulos.push_back(0);triangulos.push_back(3);	


	nTriangulos=8;
}

Octaedro::Octaedro(const Octaedro & obj){
	vertices=obj.vertices;
	triangulos=obj.triangulos;
	nTriangulos=obj.nTriangulos;
}

Octaedro::Octaedro(vector<GLfloat> &v,vector<GLint> &t,unsigned int n){
	vertices=v;
	triangulos=t;
	nTriangulos=n;
}


//Funcion de cambio de lado
void Octaedro::setLado(int lado){
	for(int i=0;i<vertices.size();i++)
		vertices[i]*=lado;
}
