#ifndef JUEGO_H
#define JUEGO_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../../Libreria/libreria.h"
#include "Nave.h"	
#include "Asteroide.h"

#include "Definiciones.h"

using namespace std;

class Juego{
	int _tecla;
	bool _gameOver;
	int _puntos;
	bool _resultado;
	Nave* _nave;
	Asteroide* vecAst[TOPE];	
	// completar
public:
	Juego();
	~Juego();
	void init();
	bool gameOver();
	void input();
	void draw();
	void update();
	void display();
	void result();
	void play();
};

#endif