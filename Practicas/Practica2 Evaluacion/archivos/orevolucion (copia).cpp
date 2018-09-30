#include "orevolucion.h"

//Constructores
Orev::Orev(int l){
;
}

Orev::Orev(char* nombre){
		_file_ply::read( nombre,vertices,triangulos);
		nTriangulos=(int)triangulos.size()/3;
}


Orev::Orev(vector<GLfloat> &v,vector<GLint> &t,unsigned int n){
	vertices=v;
	triangulos=t;
	nTriangulos=n;
}

void Orev::crear(char * nombre, int divisiones, int eje ){
	//Vectores auxiliares
	vector<GLfloat> v;
	vector<GLint> t;
	//Lectura de PLY en los auxiliares
	_file_ply::read( nombre,v,t);

	float alfa,ang,angulo;
	ang=360/divisiones;
	angulo=ang;
	int pPerfil=v.size();

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
			//cout <<"ENTRA" << i <<  " "<< xr<<  " "<<yr <<  " "<< zr<<endl;
		}
		//aumentamos el angulo
		ang+=angulo;
	}
	//Calculamos el punto de la parte inferior (si no existe)
	cPuntoB(v,vertices);
	calculaCaras(divisiones,((vertices.size()-6)/divisiones)/3);
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

void Orev::calculaCaras(int particiones,int numeroPuntosInicial){
	cout << "NUMERO DE PUNTOS QUE LLEGA"<< numeroPuntosInicial<<endl;
	cout << "particiones"<< particiones<<endl;
	//Vector auxiliar para calcular las caras;
	vector<GLint> t;
	int valora=1;
	int valorb=1+numeroPuntosInicial;
	//Creamos la tapadera
	for(int i=0;i<particiones-1;i++){
		t.push_back(0);
		t.push_back(valora);
		t.push_back(valorb);
		valora=valorb;
		valorb+=numeroPuntosInicial;
	}
	t.push_back(0);	t.push_back(valora);t.push_back(1);

int a=0;
int mod=particiones*numeroPuntosInicial;
	for(int i=0;i<numeroPuntosInicial;i++){
		a++;
		for(int j=0;j<particiones;j++){
		int b=a+(j*3);
			t.push_back(b);
			if(b+1>12)		t.push_back((b+1)%mod);
			else			t.push_back(b+1);
			if(b+1+3>12)	t.push_back((b+1+3)%mod);
			else			t.push_back(b+1+3);
			
			t.push_back(b);
			if(b+4>12)		t.push_back((b+1+3)%mod);
			else			t.push_back(b+1+3);
			if(b+3>12)			t.push_back((b+1+3)%mod);
			else			t.push_back(b+2);
		}
	}

	cout << "triangulos"<<endl;
	for(int x=0;x<t.size();x+=3)
	cout << t[x] << " "<< t[x+1]<< " "<< t[x+2]<<endl;	
	

	valora=numeroPuntosInicial;
	valorb=valora+numeroPuntosInicial;
	//Creamos la tapadera
	for(int i=0;i<particiones-1;i++){
		t.push_back(numeroPuntosInicial*particiones+1);
		t.push_back(valora);
		t.push_back(valorb);
		valora=valorb;
		valorb+=numeroPuntosInicial;
	}
	t.push_back(numeroPuntosInicial*particiones+1);	t.push_back(valora);t.push_back(numeroPuntosInicial);

	triangulos=t;
	nTriangulos=t.size()/3;
}
