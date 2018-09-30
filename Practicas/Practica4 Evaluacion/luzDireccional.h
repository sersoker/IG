#ifndef _LUZDIRECCIONAL_H
#define _LUZDIRECCIONAL_H
#include "luz.h"

class LuzDireccional: public Luz {
private:
	int alfa=0;
	int beta=0;

public:
	//constructor
   	void inicia();
   	void aumentax();
   	void aumentay();
   	void disminuyex();
   	void disminuyey();
   	void enciendeLuz();

};
#endif