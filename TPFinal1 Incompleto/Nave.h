#ifndef NAVE_H
#define NAVE_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../../Libreria/libreria.h"
#include "Definiciones.h"

class Nave{
private:
	int _x;
	int _y;
	int _vidas;
	int _corazones;
public:
	Nave(int x,int y,int vidas,int corazones);
	virtual ~Nave();
	void dibujar();
	void borrar();
	void dibujarCorazones();
	void morir();
	void setX(int x){ _x=x;}
	void setY(int y){ _y=y;}
	int getX(){ return _x;}
	int getY(){ return _y;}
	void corazones(){_corazones--;}
	void vidas(){_vidas--;}
	int getCorazones(){return _corazones;}
	int getVidas(){return  _vidas;}
	void vidaCero(){_vidas=0;}
	void corazonesCero(){_corazones=0;}
};
#endif