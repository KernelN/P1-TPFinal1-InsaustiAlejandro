#include<iostream>
#include"../../Libreria/libreria.h"
#include "Definiciones.h"
using namespace std;

class Bala{
	int _x;
	int _y;
	static int _cantBalas; 
public:
	Bala(int x,int y);
	~Bala();
	void dibujar();
	void borrar();
	bool afuera();
	int getX(){ return _x;}
	int getY(){ return _y;}
	int getCantBalas();
};