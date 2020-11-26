// Crear un juego y juegue hasta apretar la tecla ESCAPE 
#include <iostream>
#include "Juego.h"
using namespace std;

void main() {
Juego* j=new Juego();
	j->play();
	delete j;
	cin.get();
}