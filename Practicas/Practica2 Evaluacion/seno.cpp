#include "seno.h"
Seno::Seno(int l){
	vector<GLfloat> v;
	v.push_back(sin(-M_PI/2));
	v.push_back(sin(-M_PI/3));
	v.push_back(sin(-M_PI/4));
	v.push_back(sin(-M_PI/5));
	v.push_back(sin(-M_PI/6));
	v.push_back(sin(-M_PI/7));
	v.push_back(sin(-M_PI/8));
	v.push_back(sin(-M_PI/9));
	v.push_back(sin(-M_PI/10));
	v.push_back(sin(-M_PI/11));


	v.push_back(sin(M_PI/11));
	v.push_back(sin(M_PI/10));
	v.push_back(sin(M_PI/9));
	v.push_back(sin(M_PI/8));
	v.push_back(sin(M_PI/7));
	v.push_back(sin(M_PI/6));
	v.push_back(sin(M_PI/5));
	v.push_back(sin(M_PI/4));
	v.push_back(sin(M_PI/3));
	v.push_back(sin(M_PI/2));

vertices=v;
}


vector<GLfloat> Seno::getVertices(){
	return vertices;

}
