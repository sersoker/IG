#include "escena.h"

void Escena::idle(){
	if(activadaTraslacionAutomatica)
		giroscopio.aumentaTraslacion(velocidadGrado1);
		giroscopio.aumentaRotacion(1,velocidadGrado2);
		giroscopio.aumentaRotacion(2,velocidadGrado3);
	sistema.aumentaRotacion(1,velocidadGrado2);
	if(mueveluces)
	//	luzRoja.mueveluces();
	glutPostRedisplay();
}

Escena::Escena(){
	Front_plane=50;
	Back_plane=1000;
	Observer_distance = 4*Front_plane;
	Observer_angle_x = Observer_angle_y=0;

}

void Escena::inicializar(int UI_window_width,int UI_window_height) {
	glClearColor(1,1,1,1);// se indica cual sera el color para limpiar la ventana	(r,v,a,al)
	glEnable(GL_DEPTH_TEST);	// se habilita el z-bufer
	this->change_projection();
	Width=UI_window_width/10;
	Height=UI_window_height/10;
	glViewport(0,0,UI_window_width,UI_window_height);
	luzDireccional.inicia();
	luzPosicional.inicia();
	luzRoja.inicia();
}

//**************************************************************************
// Funcion que dibuja objetos en la escena
//***************************************************************************
void Escena::draw_objects(int lado,char* archivo) {

/*	Oply objetoPly(archivo);
	Orev objetoRevolucion(archivo,divi,1);	
*/	if(figura==6){
		luzRoja.enciendeLuz();
		//luzDireccional.enciendeLuz();

	}
	else if(figura==5){		
		luzDireccional.enciendeLuz();
		luzPosicional.enciendeLuz();
	}
	else{
		luzDireccional.apagaLuz();
		luzPosicional.apagaLuz();
	}

	switch (figura){
		case 1:
			if(tipo!=3)
				objetoPly.dibujar20(tipo);
			else
				objetoPly.dibujar15(tipo);
		break;
		case 2:
			if(tipo!=3)	
			objetoRevolucion.dibujar20(tipo);
			else
			objetoRevolucion.dibujar15(tipo);
		break;
		case 3:
			giroscopio.dibujar(tipo);
		break;
		case 4:
			sistema.dibujar(tipo);
		break;
		case 5:
			practica4.dibujar(tipo);
		break;
		case 6:
			obExamen.dibujar(tipo);
		break;	
	}
}


void Escena::dibujar(int lado,char* archivo) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	glEnable(GL_CULL_FACE);
	change_observer();
	draw_axis();
	draw_objects(lado,archivo);

}


int Escena::teclaPulsada(unsigned char Tecla1,int x,int y) {
	std::cout << "Tecla: " << Tecla1<< std::endl;
	unsigned char tecla= Tecla1;

		switch (tecla){
		case 'Q':
			return 1;
			break;
		case 'q':
			return 1;
			break;
//*********** Grados ********************			
			//Grado1 +
		case 'Z':
		velocidadGrado1=0.1;
		giroscopio.aumentaTraslacion(velocidadGrado1);
			break;
			//Grado 1 -
		case 'z':
		velocidadGrado1=-0.1;
		giroscopio.aumentaTraslacion(velocidadGrado1);
			break;
			//Grado2 +
		case 'X':
			giroscopio.aumentaRotacion(1,1);
			break;
			//Grado 2 -
		case 'x':
			giroscopio.aumentaRotacion(1,-1);
			break;
			//Grado3 +
		case 'C':
			giroscopio.aumentaRotacion(2,1);
			break;
			//Grado 3 -
		case 'c':
			giroscopio.aumentaRotacion(2,-1);
			break;
//*********** Grados ********************
//*********** Velocidades ********************			
			//Grado1 +
		case 'B':
		activadaTraslacionAutomatica=true;
			velocidadGrado1+=0.1;
			break;
			//Grado 1 -
		case 'b':
		activadaTraslacionAutomatica=true;
			velocidadGrado1+=-0.1;
			break;
			//Grado2 +
		case 'N':
			velocidadGrado2++;
			break;
			//Grado 2 -
		case 'n':
			velocidadGrado2--;
			break;
			//Grado3 +
		case 'M':
			velocidadGrado3++;
			break;
			//Grado 3 -
		case 'm':
			velocidadGrado3--;
			break;
//*********** velocidades ********************			
			//Mas Divisiones
		case '+':
			divi++;
			break;
			//Menos Divisiones
		case '-':
			if(divi>4)divi--;
			break;
//*********** Modos *********************
			//Modo solido
		case 's':
			tipo=0;
			break;
			//Modo puntos
		case 'p':
			tipo=1;
			break;
			//Modo lineas
		case 'l':
			tipo=2;
			break;
			//Modo ajedrez
		case 'a':
			tipo=3;
			break;
//*********** Modos *********************
//*********** Figuras *******************
			//Figura PLY
		case '1':
			figura=1;
			break;
			//Figura revolucion
		case '2':
			figura=2;
			break;
			//Figura jerarquica
		case '3':
			figura=3;
			break;
		case '4':
			figura=4;
			break;
		case '5':
			figura=5;
			break;	
		case '6':
			figura=6;
			break;				
//*********** Figuras *******************
//*********** Luces *******************
		case 'g':
			luzDireccional.disminuyex();
			luzRoja.disminuyex();
			break;
		case 'G':
			luzDireccional.aumentax();
			luzRoja.aumentax();
			break;
		case 'h':
			luzDireccional.disminuyey();
			luzRoja.disminuyey();
			break;
		case 'H':
			luzDireccional.aumentay();
			luzRoja.aumentay();
			break;
//*********** Luces *******************			
}
return 0;
}

void Escena::teclaEspecial(int Tecla1,int x,int y) {
switch (Tecla1){
	case GLUT_KEY_LEFT:Observer_angle_y--;break;
	case GLUT_KEY_RIGHT:Observer_angle_y++;break;
	case GLUT_KEY_UP:Observer_angle_x--;break;
	case GLUT_KEY_DOWN:Observer_angle_x++;break;
	case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
	case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;
	}
}


//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************
void Escena::change_projection(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glFrustum(-Width,Width,-Height,Height,Front_plane,Back_plane);
	//Cambiar la linea superior por
	glOrtho(-Width/3,Width/3,-Height/3,Height/3 ,Front_plane,Back_plane);
}


void Escena::redimensionar(int newWidth,int newHeight) {
	change_projection();
	Width=newWidth/10;
	Height=newHeight/10;
	glViewport(0,0,newWidth,newHeight);
}


//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************
void Escena::change_observer() {
	// posicion del observador
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0,0,-Observer_distance);
	glRotatef(Observer_angle_x,1,0,0);
	glRotatef(Observer_angle_y,0,1,0);
}


//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************
void Escena::draw_axis(){
	glBegin(GL_LINES);
	// eje X, color rojo
	glColor3f(1,0,0);
	glVertex3f(-AXIS_SIZE,0,0);
	glVertex3f(AXIS_SIZE,0,0);
	// eje Y, color verde
	glColor3f(0,1,0);
	glVertex3f(0,-AXIS_SIZE,0);
	glVertex3f(0,AXIS_SIZE,0);
	// eje Z, color azul
	glColor3f(0,0,1);
	glVertex3f(0,0,-AXIS_SIZE);
	glVertex3f(0,0,AXIS_SIZE);
	glEnd();
}
