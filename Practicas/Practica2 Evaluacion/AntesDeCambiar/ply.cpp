#include "ply.h"

//Constructores
Oply::Oply(int l){
	;
}

Oply::Oply(char* nombre){
	 	_file_ply::read( nombre,vertices,triangulos);
	 	nTriangulos=(int)triangulos.size()/3;
}

void Oply::crear(char * nombre){
	 	_file_ply::read( nombre,vertices,triangulos);
	 	nTriangulos=(int)triangulos.size()/3;
}

Oply::Oply(vector<GLfloat> &v,vector<GLint> &t,unsigned int n){
	vertices=v;
	triangulos=t;
	nTriangulos=n;
}