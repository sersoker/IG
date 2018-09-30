#include "tetra.h"

//Constructores
Tetraedro::Tetraedro(int lado){

	vertices.push_back(0);vertices.push_back(lado);vertices.push_back(0);	
	vertices.push_back(0);vertices.push_back(0);vertices.push_back(lado);
	vertices.push_back(lado);vertices.push_back(0);vertices.push_back(-lado);	
	vertices.push_back(-lado);vertices.push_back(0);vertices.push_back(-lado);


	triangulos.push_back(1);triangulos.push_back(3);triangulos.push_back(2);	
	triangulos.push_back(0);triangulos.push_back(2);triangulos.push_back(1);
	triangulos.push_back(0);triangulos.push_back(1);triangulos.push_back(3);	
	triangulos.push_back(0);triangulos.push_back(3);triangulos.push_back(2);

	nTriangulos=4;
}

Tetraedro::Tetraedro(const Tetraedro & obj){
	vertices=obj.vertices;
	triangulos=obj.triangulos;
	nTriangulos=obj.nTriangulos;
}

Tetraedro::Tetraedro(vector<GLfloat> &v,vector<GLint> &t,unsigned int n){
	vertices=v;
	triangulos=t;
	nTriangulos=n;
}


//Funcion de cambio de lado
void Tetraedro::setLado(int lado){
	for(int i=0;i<vertices.size();i++)
		vertices[i]*=lado;
}
