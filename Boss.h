#pragma once
#include "Personaje.h"
#include <iostream>
class Boss : public Personaje
{
private:
	int lunaSangre;
	int cataclismo;

public:

	//CONSTRUCTOR CON ELEMENTOS DE LA CLASE PADRE Y PROPIA
	Boss(int pvida, std::string pName, int pAttack, int pPosicionX, int pPosicionY, int pLunaSangre, int pCataclismo);

	//GETTERS AND SETTERS
	int getlunaSangre();
	int getcataclismo();

	void setlunaSangre(int pLunaSangre);
	void setcataclismo(int pcataclismo);

	//METODOS PROPIOS
	void printAllStats();


};




