#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "luz.h"

void Luz::apagaLuz(){
	glDisable(GL_LIGHTING);
}