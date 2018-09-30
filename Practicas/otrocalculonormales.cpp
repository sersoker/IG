

void Objeto3d::calculaNormales(){
  float modulo;
  for (int i=0; i<nTriangulos;i+=3){
	int posicion=i*3;

	float vectorAx=vertices[triangulos[posicion+1]]-vertices[triangulos[posicion]];
	float vectorAy=vertices[triangulos[posicion+1]+1]-vertices[triangulos[posicion]+1];
	float vectorAz=vertices[triangulos[posicion+1]+2]-vertices[triangulos[posicion]+2];

	float vectorBx=vertices[triangulos[posicion+2]]-vertices[triangulos[posicion]];
	float vectorBy=vertices[triangulos[posicion+2]+1]-vertices[triangulos[posicion]+1];
	float vectorBz=vertices[triangulos[posicion+2]+2]-vertices[triangulos[posicion]+2];

	//Calculamos el producto vectorial de los dos vectores obtenidos vectorAB x vectorBC
	float normalCx=vectorAy*vectorBz-vectorAz*vectorBy;
	float normalCy=vectorAz*vectorBx-vectorAx*vectorBz;
	float normalCz=vectorAx*vectorBy-vectorAy*vectorBx;

	modulo = sqrt ((normalCx*normalCx)+(normalCy*normalCy)+(normalCz*normalCz));

	normalesCaras.push_back(normalCx/modulo);
	normalesCaras.push_back(normalCy/modulo);
	normalesCaras.push_back(normalCz/modulo);
  }


