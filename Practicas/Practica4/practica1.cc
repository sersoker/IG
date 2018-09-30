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
int ladoEscena;
char* archivo;

void draw_scene()  {
	if (escena!=NULL)	escena->dibujar(ladoEscena,archivo);
	glutSwapBuffers();
}

//***************************************************************************
// Funcion llamada cuando se produce un cambio en el tamaño de la ventana
// el evento manda a la funcion: nuevo ancho  nuevo alto
//***************************************************************************
void change_window_size(int newWidth,int newHeight)  {
	if (escena!=NULL)	escena->redimensionar(newWidth,newHeight);
	glutPostRedisplay();
}

void idle(){
	if(escena!=NULL)
		escena->idle();
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
	glutCreateWindow("Práctica 4: Bryan Moreno Picamán");

	//Pasar lado de entrada a escena y el archivo PLY
	if(argc<2){
		std::cout << "***************************************"<<std::endl;
		std::cout << "ERROR, faltan parametros de entrada"<<std::endl;
		std::cout << "Formato:./programa [ArchivoPLY/ArchivoPerfil]"<<std::endl;
		std::cout << "***************************************"<<std::endl;	
		return -1;
	}

	//Opciones del Menú;
	std::cout <<std::endl<<std::endl<<std::endl<<std::endl<<std::endl;
	std::cout << "***************************************"<<std::endl;
	std::cout << "************Menú de acciones:*************" <<std::endl;
	std::cout << "AVISO: El archivo pasado como parametro se usa para ArchivoPLY y Revolucion" <<std::endl;
	std::cout << "Tecla 'p' - Modo Puntos"<<std::endl;
	std::cout << "Tecla 'l' - Modo Lineas/aristas"<<std::endl;
	std::cout << "Tecla 's' - Modo Solido"<<std::endl;
	std::cout << "Tecla 'a' - Modo Ajedrez"<<std::endl;

	std::cout << "Figura a dibujar:"<<std::endl;
	std::cout << "Tecla '1' - PLY"<<std::endl;
	std::cout << "Tecla '2' - Revolucion"<<std::endl;
	std::cout << "Tecla '3' - Jerarquico"<<std::endl;
	std::cout << "Tecla '4' - Jerarquico Extra"<<std::endl;
	std::cout << "Tecla '5' - Escena Lata+Peones"<<std::endl;

	std::cout << "Opciones de Dibujo:"<<std::endl;
	std::cout << "Tecla 'Z/z' - Primer grado de Libertad"<<std::endl;
	std::cout << "Tecla 'X/x' - Segundo grado de Libertad"<<std::endl;
	std::cout << "Tecla 'C/c' - Tercer grado de Libertad"<<std::endl;
	std::cout << "Tecla '+/-' - Divisiones figura PLY"<<std::endl;
	std::cout << "Tecla 'B/b' -  incrementa/decrementa la velocidad de modificación del primer grado de libertad"<<std::endl;
	std::cout << "Tecla 'N/n' -  incrementa/decrementa la velocidad de modificación del segundo grado de libertad"<<std::endl;
	std::cout << "Tecla 'M/m' -  incrementa/decrementa la velocidad de modificación del tercer grado de libertad"<<std::endl;
	std::cout <<std::endl;
	std::cout << "Tecla 'Q/q' - SALIR"<<std::endl;

	//Pasando parametros de lado y archivo de entrada
	archivo=argv[2];


	// asignación de la funcion llamada "dibujar" al evento de dibujo
	glutDisplayFunc(draw_scene);
	// asignación de la funcion llamada "cambiar_tamanio_ventana" al evento correspondiente
	glutReshapeFunc(change_window_size);
	// asignación de la funcion llamada "tecla_normal" al evento correspondiente
	glutKeyboardFunc(normal_keys);
	// asignación de la funcion llamada "tecla_Especial" al evento correspondiente
	glutSpecialFunc(special_keys);
	glutIdleFunc(idle);
	// funcion de inicialización
	escena->inicializar(UI_window_width,UI_window_height);
	// inicio del bucle de eventos
	glutMainLoop();
	return 0;
}
