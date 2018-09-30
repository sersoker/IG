#include <cstdio>
#include <iostream>
#include "revolucion.h"
#include <vector>
#include "file_ply_stl.h"
#include <cmath>
#include <GL/gl.h>
#include <GL/glut.h>


Revolucion::Revolucion(){

}

Revolucion Revolucion::operator= ( Revolucion objetoRevol ){
	vertices = objetoRevol.vertices;
	triangulos = objetoRevol.triangulos;
}


Revolucion::Revolucion(char *rutaArchivo, int numeroDivisiones){

   _file_ply lectorPly;
 
    lectorPly.open(rutaArchivo);
    lectorPly.read(vertices,triangulos);
    lectorPly.close();

	triangulos.clear();

	numero_de_vertices = vertices.size() / 3;

    divisiones = numeroDivisiones;

    std::cout << "\n\nDivisiones Revolucion: " << divisiones << endl;
	num_tri = ( triangulos.size() )/3;

	triangulos.clear();

	for (int i=0; i<numero_de_vertices; i++){
		if ( estaEnEjeY(i) ){
			std::cout << "\nEl vertice " << i << " esta en el eje Y. Descartado de giro\n" << endl;
			verticesQueNoSeGiran.push_back(vertices[3*i]);
			verticesQueNoSeGiran.push_back(vertices[(3*i)+1]);
			verticesQueNoSeGiran.push_back(vertices[(3*i)+2]);
		}else{
			verticesQueSiSeGiran.push_back(vertices[3*i]);
			verticesQueSiSeGiran.push_back(vertices[(3*i)+1]);
			verticesQueSiSeGiran.push_back(vertices[(3*i)+2]);
		}
	}
	vertices = verticesQueSiSeGiran;

	///////////////////////////// INICIO COMPROBACIÓN DEL SENTIDO DE LOS VÉRTICES (ASCENDENTE O DESCENDENTE) //////////////////////
	if (sentidoAscendente(vertices[1],vertices[vertices.size()-1] ) ){
		creaRevolucionAscendente(vertices,numeroDivisiones);
	}else{
		creaRevolucionDescendente(vertices,numeroDivisiones);
	}
	///////////////////////////// FIN COMPROBACIÓN DEL SENTIDO DE LOS VÉRTICES (ASCENDENTE O DESCENDENTE) //////////////////////
}

// Método que se encarga de generar la revolución completa del perfil
void Revolucion::creaRevolucionAscendente(vector<GLfloat> listaVertices, int numeroDivisiones){
	vertices = listaVertices;
	divisiones = numeroDivisiones;
	/* 
	Cojo el tamaño del vector de vértices para usarlo en un bucle a la hora de meter 'numberoDivisiones' veces 
	las modificaciones realizadas a las coordenadas de cada uno de los vértices
	*/
	int tamanio_vector_vertices = vertices.size();

	// Recorrer el vector de vértices aplicándole las transformaciones a los puntos que NO están en el eje Y

	for (int i=1; i<numeroDivisiones; i++){
		for (int j=0; j<tamanio_vector_vertices; j=j+3){	
			// Eje X 
		    vertices.push_back( vertices[j] * cos ( gira(numeroDivisiones) * i ) + vertices[j+2] * sin ( gira(numeroDivisiones) * i ) );
		    // Eje Y
		    vertices.push_back(vertices[j+1]);
		    // Eje Z
		    vertices.push_back( - vertices[j] * sin ( gira(numeroDivisiones) * i ) + vertices[j+2] * cos ( gira(numeroDivisiones) * i ) );		
		}		
		//gradosAGirar = gradosAGirar + giro;
	}

	int i=0; 
	int incremento = numero_de_vertices; // numero de vertices 
	int j= i + incremento;
	int k = i+1;
	int l = j+1;	

	crea_iteracion_perfil(i,j,k,l);

//////////////////////////////////////   VERTICE INVENTADO PARA COGER LA ALTURA DEL PERFIL ///////////////////////////////////////

	vector<GLfloat> aux;
	aux.push_back(0.0);
	aux.push_back( vertices[ vertices.size()-2 ]); 
	aux.push_back(0.0);

	vertices.push_back(0.0);
	vertices.push_back( aux[1] );
	vertices.push_back(0.0);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Número del vértice inventado que tiene por coordenada X y Z = 0, y por la Y la altura del perfil
	altura_perfil = (vertices.size()/3)-1;

////////////////// SE REPITE LO MISMO DE LA ALTURA, PERO PARA COGER EL VALOR DE 'Y' DEL VÉRTICE MÁS BAJO ///////////////////////

	aux.clear();
	aux.push_back( vertices[1]); //Valor de 'Y' del vértice más bajo de la figura

	vertices.push_back(0.0);
	vertices.push_back( aux[0] ); // Es el valor de arriba, el vertices[1]
	vertices.push_back(0.0);	

	altura_baja_perfil = (vertices.size()/3);
	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	



/////////////////////////_____________ INICIO CREACIÓN DEL CUERPO DEL PERFIL POR REVOLUCIÓN____////////////////////////////////////////

	for (int iteraciones=0; iteraciones<divisiones-1; iteraciones++){
		crea_iteracion_perfil(i,j,k,l);
		i = i + incremento;
		j = i + incremento;
		k = i + 1;
		l = j +1;
	}

	// Para unir la última cara con la primera
	j=0;
	l=1;
	
	crea_iteracion_perfil(i,j,k,l);

/////////////////////////_____________ FIN CREACIÓN DEL CUERPO DEL PERFIL POR REVOLUCIÓN____////////////////////////////////////////


/////////////////////////////_____________ INICIO CREACIÓN DE LAS TAPAS DEL PERFIL POR REVOLUCIÓN____///////////////////////////////

	if (estaEnEjeY(vertices[1]) == false){ //Detecta si el primer vértice está sobre el eje Y (sería el "centro" de la unión de los vértices)
		creaTapaderaInferior();	
	}
	if (estaEnEjeY(vertices[vertices.size()-2]) == false){ // Detecta si el último vértice está sobre el eje Y (mismo razonamiento)
		creaTapaderaSuperior();
	}	

/////////////////////////////_____________ FIN CREACIÓN DE LAS TAPAS DEL PERFIL POR REVOLUCIÓN____///////////////////////////////

}

// Método que se encarga de generar la revolución completa del perfil
void Revolucion::creaRevolucionDescendente(vector<GLfloat> listaVertices, int numeroDivisiones){
	vertices = listaVertices;
	divisiones = numeroDivisiones;
	/* 
	Cojo el tamaño del vector de vértices para usarlo en un bucle a la hora de meter 'numberoDivisiones' veces 
	las modificaciones realizadas a las coordenadas de cada uno de los vértices
	*/
	int tamanio_vector_vertices = vertices.size();

	// Recorrer el vector de vértices aplicándole las transformaciones a los puntos que NO están en el eje Y

	for (int i=1; i<numeroDivisiones; i++){
		for (int j=0; j<tamanio_vector_vertices; j=j+3){	
			// Eje X 
		    vertices.push_back( vertices[j] * cos ( gira(numeroDivisiones) * i ) + vertices[j+2] * sin ( gira(numeroDivisiones) * i ) );
		    // Eje Y
		    vertices.push_back(vertices[j+1]);
		    // Eje Z
		    vertices.push_back( - vertices[j] * sin ( gira(numeroDivisiones) * i ) + vertices[j+2] * cos ( gira(numeroDivisiones) * i ) );		
		}		
		//gradosAGirar = gradosAGirar + giro;
	}

	int i=vertices.size(); 
	int decremento = numero_de_vertices; // numero de vertices 
	int j= i - decremento;
	int k = i-1;
	int l = j-1;	

	crea_iteracion_perfil(i,j,k,l);

//////////////////////////////////////   VERTICE INVENTADO PARA COGER LA ALTURA DEL PERFIL ///////////////////////////////////////

	vector<GLfloat> aux;
	aux.push_back(0.0);
	aux.push_back( vertices[ vertices.size()-2 ]); 
	aux.push_back(0.0);

	vertices.push_back(0.0);
	vertices.push_back( aux[1] );
	vertices.push_back(0.0);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// Número del vértice inventado que tiene por coordenada X y Z = 0, y por la Y la altura del perfil
	altura_perfil = (vertices.size()/3)-1;

////////////////// SE REPITE LO MISMO DE LA ALTURA, PERO PARA COGER EL VALOR DE 'Y' DEL VÉRTICE MÁS BAJO ///////////////////////

	aux.clear();
	aux.push_back( vertices[1]); //Valor de 'Y' del vértice más bajo de la figura

	vertices.push_back(0.0);
	vertices.push_back( aux[0] ); // Es el valor de arriba, el vertices[1]
	vertices.push_back(0.0);	

	altura_baja_perfil = (vertices.size()/3);
	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	



/////////////////////////_____________ INICIO CREACIÓN DEL CUERPO DEL PERFIL POR REVOLUCIÓN____////////////////////////////////////////

	for (int iteraciones=0; iteraciones<divisiones-1; iteraciones++){
		crea_iteracion_perfil(i,j,k,l);
		i = i - decremento;
		j = i - decremento;
		k = i - 1;
		l = j -1;
	}

	// Para unir la última cara con la primera
	j=0;
	l=1;
	
	crea_iteracion_perfil(i,j,k,l);

/////////////////////////_____________ FIN CREACIÓN DEL CUERPO DEL PERFIL POR REVOLUCIÓN____////////////////////////////////////////


/////////////////////////////_____________ INICIO CREACIÓN DE LAS TAPAS DEL PERFIL POR REVOLUCIÓN____///////////////////////////////

	if (estaEnEjeY(vertices[1]) == false){ //Detecta si el primer vértice está sobre el eje Y (sería el "centro" de la unión de los vértices)
		creaTapaderaInferior();	
	}
	if (estaEnEjeY(vertices[vertices.size()-2]) == false){ // Detecta si el último vértice está sobre el eje Y (mismo razonamiento)
		creaTapaderaSuperior();
	}	

/////////////////////////////_____________ FIN CREACIÓN DE LAS TAPAS DEL PERFIL POR REVOLUCIÓN____///////////////////////////////

}

bool Revolucion::es_perfil(){
	if (num_tri == 0){
		return true;
	} else{
		return false;
	}
}

// Método que devuelve el ángulo a girar en función del número de divisiones deseado
float Revolucion::gira(int divisiones){
	return ((2*pi)/divisiones);
}

// Método que devuelve el vector de vértices
vector<GLfloat> Revolucion::getVertices(){
	return vertices;
}

// Método que genera las caras del perfil
void Revolucion::crea_iteracion_perfil(int i, int j, int k, int l){
	int diferencia;
	
	diferencia = divisiones - (numero_de_vertices -1);
	for (int iteraciones=diferencia; iteraciones<divisiones; iteraciones++){
		triangulos.push_back(i);
		triangulos.push_back(j);
		triangulos.push_back(k);

		triangulos.push_back(k);
		triangulos.push_back(j);
		triangulos.push_back(l);

		i++;
		j++;
		k++;
		l++;
	}
	
}

// Método que crea la tapadera superior del objeto revolución
void Revolucion::creaTapaderaSuperior(){
	int ultimo_vertice_iteracion = numero_de_vertices;

	//////////////////////// INICIO TAPADERA SUPERIOR /////////////////////////////////
	for (int j = 0; j < divisiones-1 ; j++){
	    //Tapadera Superior
		triangulos.push_back( (ultimo_vertice_iteracion-1) );     //  Último vértice de la 'J'ésima iteración
		triangulos.push_back( (numero_de_vertices+ultimo_vertice_iteracion)-1  ); //  Último vértice de la 'J'ésima+1 iteración
		triangulos.push_back( altura_perfil );    //	Vértice Auxiliar inventado para cerrar el triángulo situado en el eje Y a la altura del perfil

		ultimo_vertice_iteracion = ultimo_vertice_iteracion + numero_de_vertices;
	}

	// Última iteración de la tapa superior
	triangulos.push_back( (ultimo_vertice_iteracion-1) );   //  Último vértice de la última iteración
	triangulos.push_back( (numero_de_vertices)-1  ); 		//  Último vértice de la primera iteración
	triangulos.push_back( altura_perfil );    //	Vértice Auxiliar inventado para cerrar el triángulo situado en el eje Y a la altura del perfil
	
	//////////////////////// FIN TAPADERA SUPERIOR /////////////////////////////////	
}

// Método que crea la tapadera inferior del objeto revolución
void Revolucion::creaTapaderaInferior(){
	int ultimo_vertice_iteracion = numero_de_vertices;
	int por_abajo = (vertices.size()-4)/3;
	int primer_vertice_iteracion = por_abajo;


	//////////////////////// INICIO TAPADERA INFERIOR /////////////////////////////////
	primer_vertice_iteracion = primer_vertice_iteracion - numero_de_vertices;	
	for (int j = 0; j < divisiones -1 ; j++){
		//Tapadera Inferior
		triangulos.push_back( (primer_vertice_iteracion) );     //  Primer vértice de la 'J'ésima iteración
		triangulos.push_back( (primer_vertice_iteracion - numero_de_vertices )  ); //  Primer vértice de la 'J'ésima-1 iteración
		triangulos.push_back( (vertices.size()/3)-1 );    //	Vértice Auxiliar  para cerrar el triángulo situado en el eje Y a la altura "más baja" del perfil

		primer_vertice_iteracion = primer_vertice_iteracion - numero_de_vertices;
	}

	primer_vertice_iteracion = primer_vertice_iteracion + numero_de_vertices; // Rectifico el primer vértice para poder unir el primero con el último

	triangulos.push_back( (0) );     //  Primer vértice de la 'J'ésima iteración
	triangulos.push_back( por_abajo - numero_de_vertices ); //  Primer vértice de la 'J'ésima+1 iteración
	triangulos.push_back( (vertices.size()/3)-1 );    //	Vértice Auxiliar inventado para cerrar el triángulo situado en el eje Y a la altura del perfil

	////////////////////////// FIN TAPADERA INFERIOR //////////////////////////////////	
}

// Aumenta el número de divisiones
void Revolucion::aumentaDivisiones(){
	divisiones++;
}

// Disminuye el número de divisiones
void Revolucion::disminuyeDivisiones(){
	divisiones--;
}

// Método que detecta si un vértice está en el EJE 'Y' para no calcular su rotación
bool Revolucion::estaEnEjeY(GLfloat vertice){
	if ( (vertices[3*vertice]==0) && (vertices[(3*vertice)+1]!=0) && (vertices[(3*vertice)+2]==0) ){
		return true;
	}else{
		return false;
	}
}

// Método que indica si el sentido en el que se han dado los vértices en el archivo PLY es Ascendente (true) o Descendente (false)
bool Revolucion::sentidoAscendente(GLfloat inicio, GLfloat fin){
	if (fin>=inicio){
		return true;
	}else{
		return false;
	}
}