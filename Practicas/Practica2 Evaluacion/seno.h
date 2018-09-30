#ifndef OREV_H
#define OREV_H

#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include <vector>
#include "objeto3d.h"
#include "file_ply_stl.hpp"
#include <math.h>

using namespace std;

class Seno: public Objeto3d{

public:
	// Constructores.
	Seno(int l);

	vector<GLfloat> getVertices();

};

#endif
