#include "Nave.h"

Nave::Nave(int x,int y,int vidas,int corazones){
	_x=x;
	_y=y;
	_vidas=vidas;
	_corazones=corazones;
}
Nave::~Nave(){
}
void Nave::dibujar(){
	borrar();
	gotoxy(_x,_y); 
	cout<<NAVE_FILA_1;
	gotoxy(_x,_y+1);
	cout<<NAVE_FILA_2;
	gotoxy(_x,_y+2);
	cout<<NAVE_FILA_3;
}
void Nave::borrar(){
	gotoxy(_x,_y);
	cout<<"     ";
	gotoxy(_x,_y+1);
	cout<<"     ";
	gotoxy(_x,_y+2);
	cout<<"     ";
}
void Nave::morir(){
	if(_corazones==0){
		borrar();
		gotoxy(_x,_y);  cout<<" ** ";
		gotoxy(_x,_y+1);cout<<"****";
		gotoxy(_x,_y+2);cout<<" ** ";
		miliSleep(100);
		borrar();
		gotoxy(_x,_y);  cout<<"* * *";
		gotoxy(_x,_y+1);cout<<" *** ";
		gotoxy(_x,_y+2);cout<<"* * *";
		miliSleep(50);
		borrar();
		_vidas--;
		_corazones=3;
	}
}