#include "Boss.h"
#include <iostream>
using namespace std;




Boss::Boss(int pvida, std::string pName, int pAttack, int pPosicionX, int pPosicionY, int pLunaSangre, int pCataclismo) : 
	Personaje( pvida, pName,  pAttack,  pPosicionX,  pPosicionY) {
	lunaSangre = pLunaSangre;
	cataclismo = pCataclismo;
}


int Boss::getlunaSangre() {
	return lunaSangre;
}
int Boss::getcataclismo() {
	return cataclismo;
}

void Boss::setlunaSangre(int pLunaSangre) {
	lunaSangre = pLunaSangre;
}
void Boss::setcataclismo(int pCataclismo) {
	cataclismo = pCataclismo;
}

void Boss::printAllStats() {
	cout << "El nombre del enemigo final es " << getName() << endl;
	cout << "La vida del enemigo final es " << getHp() << endl;
	cout << "El ataque normal del enemigo final es " << getAttack() << endl;
	cout << "El ataque de fuego del enemigo final es " << getlunaSangre() << endl;
	cout << "El ataque de hielo del enemigo final es " << getcataclismo() << endl;
}