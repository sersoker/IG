#include "orevolucion.h"

Orev::Orev(char* nombre,int divisiones, int modo){
	vector<GLfloat> v;
	vector<GLint> t;
	//Lectura de PLY en los auxiliares
	_file_ply::read(nombre,v,t);

	creaRevolucion(v,divisiones,modo);
	calculaNormales();
	cout << "Ha calculado normales "<< triangulos.size() << " " <<normalesCaras.size() << " "<< normalesVertices.size()<< " "<< vertices.size()<<endl;
}

Orev::Orev(vector<GLfloat> &v,int divisiones, int modo){
	creaRevolucion(v,divisiones,modo);
	calculaNormales();
}


void Orev::creaRevolucion(vector<GLfloat> &v,int divisiones, int modo){

	float alfa,ang,angulo;
	ang=360/divisiones;
	angulo=ang;
	int pPerfil=v.size();
	
	//Si el perfil esta al contrario de como se necesita, lo invertimos
	if(v[4]>v[7])
		invertirVertices(v);

	//Miramos si el ultimo punto es el del eje y, para no calcular sus rotaciones
	if(v[pPerfil-1]==0&&v[pPerfil-3]==0)
		pPerfil-=3;
	else
		pPerfil+=3;

	//Añade en caso de que no exista el punto del eje y, y añade todos los puntos en vertices
	cPuntoA(v,vertices);  

	//Se calculan los puntos rotados y se van añadiendo a vertices
	for(int j=0; j<divisiones-1; j++){
		//Angulo en radianes
		alfa = 3.1415/180*ang;

		for (int i=1; i <pPerfil/3; i++){
			//se añaden a vertices los puntos calculados
			float xr=0,yr=0,zr=0;

			xr=vertices[i*3]*cos(alfa) + (vertices[(i*3)+2])*sin(alfa);
			yr=vertices[(i*3)+1];
			zr=-1*vertices[i*3]*sin(alfa) + (vertices[(i*3)+2])*sin(alfa);

			vertices.push_back(xr);   
			vertices.push_back(yr);   
			vertices.push_back(zr);   
		}
		//aumentamos el angulo
		ang+=angulo;
	}
	//Calculamos el punto de la parte inferior (si no existe)
	cPuntoB(v,vertices);

	calculaCaras(divisiones,((vertices.size()-6)/divisiones)/3);
}


//Si el perfil se da de arriba a abajo, se invierten los valores;
void Orev::invertirVertices(vector<GLfloat> &v){
	vector<GLfloat> auxiliar;

	for(int i=v.size()-1;i>=0;i-=3){
		auxiliar.push_back(v[i-2]);
		auxiliar.push_back(v[i-1]);
		auxiliar.push_back(v[i]);
	}
	v=auxiliar;
}

//Calcula el punto central de la tapadera, si ya existe no hace nada
void Orev::cPuntoA(vector<GLfloat> & v,vector<GLfloat> & vertices){
	//Si el ultimo punto es el del eje y, no lo metemos a la lista te puntos, para que esten ordenados
	bool unoMenos=false;
	if(v[v.size()-1]==0&&v[v.size()-3]==0)
		unoMenos=true;

	//Si el primer valor es el del eje y, metemos todos los valores.
	if(v[0]==0&&v[2]==0){
		vertices=v;
	}
	else{
		vertices.push_back(0.0);//valor de x en 0
		vertices.push_back(v[1]);//valor de y igual al primer valor
		vertices.push_back(0.0);//valor de z en 0
		//Se añaden el resto de valores
		for(int i=0;i<v.size();i++)
			vertices.push_back(v[i]);
	}
	//Si el ultimo valor es el del eje y, se quita de los vertices, posteriormente se añadirá al finalen cPuntoB
	if(unoMenos){
		vertices.pop_back();    	vertices.pop_back();    	vertices.pop_back();
	}
}


//Calcula el punto final de la parte inferior, si ya existe no hace nada
void Orev::cPuntoB(vector<GLfloat> & v,vector<GLfloat> & vertices){
	int tama=v.size();
	//Si el valor x y z del ultimo elemento son 0, no hace falta añadir ningun punto
	if(v[v.size()-1]==0&&v[v.size()-3]==0){
		vertices.push_back(v[tama-3]);    	vertices.push_back(v[tama-2]);    	vertices.push_back(v[tama-1]);
	}
	//En caso contrario, el ultimo punto no era de eje y por lo tanto se rotaron, se calcula un nuevo punto en la posicion 0,y,0 (con y= y del ultimo elemento)
	else{
		vertices.push_back(0.0);    	vertices.push_back(v[tama-2]);    	vertices.push_back(0.0);
	}
}


//Funcion que dada un numero de puntos y la cantidad de parciones calcula las caras de los vertices
void Orev::calculaCaras(int particiones,int numeroPuntosInicial){
	//Vector auxiliar para calcular las caras;
	vector<GLint> t;
	vector <GLfloat> auxiliar;
	
	//Movemos los vertices, para poner el primero al final.
	for(int i=3;i<vertices.size();i++)
	auxiliar.push_back(vertices[i]);
	auxiliar.push_back(vertices[0]);auxiliar.push_back(vertices[1]);auxiliar.push_back(vertices[2]);

	vertices=auxiliar;

//Calculo de las caras
for(int i=0;i<particiones-1;i++){
	for(int j=0;j<numeroPuntosInicial-1;j++){
		t.push_back(i*numeroPuntosInicial+j);
		t.push_back((i+1)*numeroPuntosInicial+j);
		t.push_back((i*numeroPuntosInicial)+j+1);

		t.push_back(i*numeroPuntosInicial+j+1);
		t.push_back((i+1)*numeroPuntosInicial+j);
		t.push_back((i+1)*numeroPuntosInicial+j+1);
	}
}
//Union del ultimo perfil con el primero
for (int j = 0; j < numeroPuntosInicial - 1; j++){
		t.push_back((particiones-1)*numeroPuntosInicial + j);
		t.push_back(j);
		t.push_back((particiones-1)*numeroPuntosInicial + j + 1);

		t.push_back((particiones-1)*numeroPuntosInicial + j + 1);
		t.push_back(j);
		t.push_back(j+1);
	}


//Calculo de la tapa
	int puntoTapa=vertices.size()/3-2;

	int valora=numeroPuntosInicial-1;
	int valorb=valora+numeroPuntosInicial;
	for(int i=0;i<particiones-1;i++){
		t.push_back(puntoTapa);
		t.push_back(valora);
		t.push_back(valorb);
		valora=valorb;
		valorb+=numeroPuntosInicial;
	}
	t.push_back(puntoTapa);t.push_back(valora);t.push_back(numeroPuntosInicial-1);

	puntoTapa++;
	valora=numeroPuntosInicial;
	valorb=valora-numeroPuntosInicial;
	for(int i=0;i<particiones-1;i++){
		t.push_back(puntoTapa);
		t.push_back(valora);
		t.push_back(valorb);
		valorb+=numeroPuntosInicial;
		valora+=numeroPuntosInicial;
	}
	t.push_back(puntoTapa);t.push_back(0);t.push_back(valora-numeroPuntosInicial);
	triangulos=t;
	nTriangulos=t.size()/3;
}
