#include "cubo.h"

//Constructores
Cubo::Cubo(int lado){

	vertices.push_back(0.0);vertices.push_back(0.0);vertices.push_back(lado);	vertices.push_back(lado);vertices.push_back(0.0);vertices.push_back(lado);
	vertices.push_back(0.0);vertices.push_back(lado);vertices.push_back(lado);	vertices.push_back(lado);vertices.push_back(lado);vertices.push_back(lado);
	vertices.push_back(0.0);vertices.push_back(0.0);vertices.push_back(0.0);	vertices.push_back(lado);vertices.push_back(0.0);vertices.push_back(0.0);
	vertices.push_back(0.0);vertices.push_back(lado);vertices.push_back(0.0);	vertices.push_back(lado);vertices.push_back(lado);vertices.push_back(0.0);

	triangulos.push_back(0);triangulos.push_back(1);triangulos.push_back(2);	triangulos.push_back(1);triangulos.push_back(3);triangulos.push_back(2);
	triangulos.push_back(2);triangulos.push_back(3);triangulos.push_back(7);	triangulos.push_back(2);triangulos.push_back(7);triangulos.push_back(6);
	triangulos.push_back(1);triangulos.push_back(7);triangulos.push_back(3);	triangulos.push_back(1);triangulos.push_back(5);triangulos.push_back(7);
	triangulos.push_back(6);triangulos.push_back(7);triangulos.push_back(4);	triangulos.push_back(7);triangulos.push_back(5);triangulos.push_back(4);
	triangulos.push_back(0);triangulos.push_back(4);triangulos.push_back(1);	triangulos.push_back(1);triangulos.push_back(4);triangulos.push_back(5);
	triangulos.push_back(2);triangulos.push_back(6);triangulos.push_back(4);	triangulos.push_back(0);triangulos.push_back(2);triangulos.push_back(4);

	nTriangulos=12;
}

Cubo::Cubo(const Cubo & obj){
	vertices=obj.vertices;
	triangulos=obj.triangulos;
	nTriangulos=obj.nTriangulos;
}

Cubo::Cubo(vector<GLfloat> &v,vector<GLint> &t,unsigned int n){
	vertices=v;
	triangulos=t;
	nTriangulos=n;
}


//Funcion de cambio de lado
void Cubo::setLado(int lado){
	for(int i=0;i<vertices.size();i++)
		vertices[i]*=lado;
}
