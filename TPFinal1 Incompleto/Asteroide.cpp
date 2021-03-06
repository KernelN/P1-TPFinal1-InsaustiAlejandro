﻿#include"Asteroide.h"

int Asteroide::_cantAsteroides=0;
Asteroide::Asteroide(int x,int y){
	_x=x;
	_y=y;
	_cantAsteroides++;
}
Asteroide::~Asteroide(){
	_cantAsteroides--;
}
int Asteroide::getCantAsteroides(){
	return _cantAsteroides;
}
void Asteroide::dibujar(){
	gotoxy(_x,_y);
	cout<<(char)ASTEROIDE;
}
void Asteroide::borrar(){
	gotoxy(_x,_y);
	cout<<" ";
}
void Asteroide::mover(){
	borrar();
	_y++;
	if(_y >= MAX_Y){
		_y = MIN_Y;
		_x = rand()%MAX_X-1;
	}
}
void Asteroide::colision(Nave* nave){
	if(_x>=nave->getX() && _x<nave->getX()+ANCHO_NAVE && 
		_y>=nave->getY() && _y>=nave->getY()+ALTO_NAVE){
		nave->corazones();
		_x=rand()%MAX_X-1;	
		if(_x<3)
			_x=4;
		_y=MIN_Y;
	}
}