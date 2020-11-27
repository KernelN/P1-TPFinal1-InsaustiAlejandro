#include "Juego.h"

Juego::Juego(){
	_nave = NULL;
	for(short i = 0; i < TOPE; i++){
		vecAst[i] = NULL;
	}
	for(int i=0;i<TOPEB;i++){
		_vecB[i] = NULL;
	}
}
Juego::~Juego(){
	if(_nave != NULL){
		_nave = NULL;
		delete _nave;
	}
	for(short i = 0; i < TOPE; i++){
		if(vecAst[i] != NULL){
			vecAst[i] = NULL;
			delete vecAst[i];
		}
	}
	for(short i = 0; i < TOPEB; i++){
		if(_vecB[i] != NULL){
			_vecB[i] = NULL;
			delete _vecB[i];
		}
	}
}
void Juego::init(){
	srand(time(0));
	_tecla=' ';
	_gameOver=false;
	_puntos=0;
	_resultado=false;
	_nave= new Nave(38,21,3,3);

	vecAst[0] = new Asteroide(10, 4);
	vecAst[1] = new Asteroide(4, 8);
	vecAst[2] = new Asteroide(15, 10);
}
bool Juego::gameOver(){
	return _gameOver;
}
void Juego::input(){
	_tecla=' ';
	if(_tecla=getKey(false)){
		_nave->borrar();

		short naveY = _nave->getY();
		short naveX = _nave->getX();

		switch(_tecla){
		case KEY_UP:
			if(naveY - 1 >= MIN_Y)
				_nave->setY(naveY - 1);
			break;
		case KEY_LEFT:
			if(naveX - 2 > MIN_X)
				_nave->setX(naveX - 1);
			break;
		case KEY_DOWN:
			if(naveY + 1 < MAX_Y - 2)
				_nave->setY(naveY + 1);
			break;
		case KEY_RIGHT:
			if(naveX + 2 < MAX_X)
				_nave->setX(naveX + 1);
			break;
		case FIRE:
			for(int i=0;i<TOPEB;i++){
				if(_vecB[i]==NULL){
					_vecB[i] = new Bala(_nave->getX() + 2, _nave->getY() - 1);
					break;
				}
			}
			break;
		case KEY_ESC:
			_gameOver = true;
		default:
			break;
		}
	}
}
void Juego::draw(){
	if(!_gameOver){
		display();
		_nave->dibujar();

		for(short i = 0; i < TOPE; i++){
			if(vecAst[i] != NULL){				
				vecAst[i]->dibujar();
			}
		}
		for(short i = 0; i < TOPEB; i++){
			if(_vecB[i] != NULL){				
				if(_vecB[i]->afuera()){
					_vecB[i]->borrar();
				}
				else{
					_vecB[i]->dibujar();
				}
			}

		}
	}
}
void Juego::update(){	
	for(int i=0;i<TOPEB;i++){
		if(_vecB[i]!=NULL && _vecB[i]->afuera()){
			_vecB[i]->borrar();
			delete _vecB[i];
			_vecB[i]=NULL;
		}
		for(short j = 0; j < TOPE; j++){
			if(vecAst[j] != NULL && _vecB[i]!=NULL && 
				_vecB[i]->getX() == vecAst[j]->getX() && _vecB[i]->getY() == vecAst[j]->getY()){
					_vecB[i]->borrar();
					_vecB[i]=NULL;
					delete _vecB[i];

					vecAst[j]->borrar();
					vecAst[j] = new Asteroide(rand()%MAX_X-1,MIN_Y);
			}
		}
	}
	for(short i = 0; i < TOPE; i++){
		if(vecAst[i] != NULL){
			vecAst[i]->mover();
			vecAst[i]->colision(_nave);
		}
	}

	if(_puntos==PUNTOS){
		_resultado=true;
		_gameOver=true;
	}
	if((_nave->getVidas()==0))	
		_gameOver=true;
	_nave->morir();
}
void Juego::display(){
	gotoxy(2,1);cout<<"Vidas "<<_nave->getVidas()<<" ";
	gotoxy(11,1);cout<<"Salud ";
	gotoxy(17,1);cout<<"        ";
	gotoxy(55,1);cout<<"Asteroides:" << Asteroide::getCantAsteroides();
	int c=_nave->getCorazones();
	for(int i=0;i<c;i++){
		gotoxy(17+i,1);
		cout<<(char)CORAZON;
	}
	// completar
}
void Juego::result(){
	if(_gameOver){
		// completar
		gotoxy(35,12);
		cout<<"Game Over";
	}
}
void Juego::play(){
	init();
	hideCursor();
	marco(MIN_COL,MIN_FIL,MAX_COL,MAX_FIL);
	display();
	draw();
	while(!gameOver()){
		input();
		update();
		draw();
		miliSleep(55);
	}
	result();
}