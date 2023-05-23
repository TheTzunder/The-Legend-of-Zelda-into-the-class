#pragma once
#include <iostream>

class Personaje
{
private:
	int vida;
	int attack;
	std::string name;
	int posicionX;
	int posicionY;

public:
	//constructor
	Personaje(int pvida, std::string pName, int pAttack, int pPosicionX, int pPosicionY);
	//getters
	int getHp();

	std::string getName();

	int getAttack();

	int getPosicionX();

	int getPosicionY();

	//setters

	void setHp(int php);

	void setName(std::string pname);

	void setAttack(int pattack);

	void setPosicionX(int pDefense);

	void setPosicionY(int pDefense);

	//metodos propios

	void printStatus();


};

