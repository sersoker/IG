//**************************************************************************
// Práctica 1  Bryan Moreno Picamán
// GPL
//**************************************************************************

#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include "escena.h"
#include <iostream>


Escena *escena;

void draw_scene(void)  {
	if (escena!=NULL)	escena->dibujar();
	glutSwapBuffers();
}
void darLado(int l)  {
	if (escena!=NULL)	escena->setLado(l);
}


//***************************************************************************
// Funcion llamada cuando se produce un cambio en el tamaño de la ventana
// el evento manda a la funcion: nuevo ancho  nuevo alto
//***************************************************************************

void change_window_size(int newWidth,int newHeight)  {
	if (escena!=NULL)	escena->redimensionar(newWidth,newHeight);
	glutPostRedisplay();
}


//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla normal
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton
//***************************************************************************

void normal_keys(unsigned char Tecla1,int x,int y)  {
	int salir=0;
	if (escena!=NULL)	
		salir=escena->teclaPulsada(Tecla1,x,y);
	
	if (salir) {
		delete escena;
		exit(0);
	} else
		glutPostRedisplay();
}

//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla especial
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton

//***************************************************************************

void special_keys(int Tecla1,int x,int y) {
	if (escena!=NULL)
		escena->teclaEspecial(Tecla1,x,y);
	glutPostRedisplay();
}



//***************************************************************************
// Programa principal
//
// Se encarga de iniciar la ventana, asignar las funciones e comenzar el
// bucle de eventos
//***************************************************************************

int main(int argc, char **argv) {

escena = new Escena();

// se llama a la inicialización de glut
glutInit(&argc, argv);

// se indica las caracteristicas que se desean para la visualización con OpenGL
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

// variables que determninan la posicion y tamaño de la ventana X
int UI_window_pos_x=50,UI_window_pos_y=50,UI_window_width=500,UI_window_height=500;

// posicion de la esquina inferior izquierdad de la ventana
glutInitWindowPosition(UI_window_pos_x,UI_window_pos_y);
// tamaño de la ventana (ancho y alto)
glutInitWindowSize(UI_window_width,UI_window_height);

// llamada para crear la ventana, indicando el titulo
glutCreateWindow("Práctica 1: Bryan Moreno Picamán");

//Pasar lado de entrada a escena.
if(argc<3)
std::cout << "ERROR, faltan parametros de entrada"<<std::endl;
std::cout << "Formato:[Lado][ArchivoPLY/ArchivoPerfil]";
darLado(atoi(argv[1]));
escena->leePly(argv[2]);

//Opciones del Menú;
std::cout <<std::endl<<std::endl<<std::endl<<std::endl<<std::endl;
std::cout << "***************************************"<<std::endl;
std::cout << "************Menú de acciones:*************" <<std::endl;
std::cout << "Modo de dibujo:"<<std::endl;
std::cout << "Tecla 'V' - Dibujo15 (Por Defecto)"<<std::endl;
std::cout << "Tecla 'N' - Dibujo20"<<std::endl;
std::cout << "Figura a dibujar:"<<std::endl;
std::cout << "Tecla 'C' - Cubo"<<std::endl;
std::cout << "Tecla 'T' - Tetraedro"<<std::endl;
std::cout << "Tecla 'O' - Octaedro"<<std::endl;
std::cout << "Tecla 'D' - Icosaedro"<<std::endl;
std::cout << "Tecla 'A' - ArchivoPLY"<<std::endl;
std::cout << "Tecla 'R' - Revolucion"<<std::endl;
std::cout << "Opciones de Dibujo:"<<std::endl;
std::cout << "Tecla '0' - Relleno (Por Defecto)"<<std::endl;
std::cout << "Tecla '1' - Puntos"<<std::endl;
std::cout << "Tecla '2' - Lineas"<<std::endl;
std::cout << "Tecla '3' - Ajedrez (solo con modo de dibujo 'V')"<<std::endl;
std::cout <<std::endl;
std::cout << "Tecla 'Q' - SALIR"<<std::endl;








// asignación de la funcion llamada "dibujar" al evento de dibujo
glutDisplayFunc(draw_scene);
// asignación de la funcion llamada "cambiar_tamanio_ventana" al evento correspondiente
glutReshapeFunc(change_window_size);
// asignación de la funcion llamada "tecla_normal" al evento correspondiente
glutKeyboardFunc(normal_keys);
// asignación de la funcion llamada "tecla_Especial" al evento correspondiente
glutSpecialFunc(special_keys);

// funcion de inicialización
escena->inicializar(UI_window_width,UI_window_height);
// inicio del bucle de eventos
glutMainLoop();
return 0;
}
