#ifndef _ESCENA_H
#define _ESCENA_H
# define M_PI           3.14159265358979323846  /* pi */

class Escena {
private:
// tama�o de los ejes
const int AXIS_SIZE=5000;

// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;
int figura=0;
int tipo=0;
int modoDibujo=0;
int divi=4;


// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Width,Height,Front_plane,Back_plane;

private:
	void clear_window();
	void draw_axis();
	void draw_objects(int lado,char* archivo);

//Transformaci�n de c�mara
	void change_projection();
	void change_observer();


public:

    Escena();
	void inicializar(int UI_window_width,int UI_window_height);
	void redimensionar(int newWidth,int newHeight) ;

	// Dibujar
	void dibujar(int lado,char* archivo) ;

	// Interacci�n con la escena
	int teclaPulsada(unsigned char Tecla1,int x,int y) ;
	void teclaEspecial(int Tecla1,int x,int y);

};
#endif