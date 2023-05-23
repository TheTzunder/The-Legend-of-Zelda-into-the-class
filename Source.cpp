#include <iostream>
#include "Personaje.h"
#include "Boss.h"
#include <conio.h>
#include <stdlib.h>
#pragma comment(lib, "winmm")
#include <Windows.h>
#pragma warning(disable : 4996)
using namespace std;
const int ROWS = 10;
const int COLS = 10;
const int BOSS_ROW = ROWS - 1;
const int BOSS_COL = COLS / 2;
const int Fin_ROW = ROWS - 10;
const int Fin_COL = COLS/2;


int generarNumeroAleatorio(int min, int max) {
    return rand() % 8 + 1;
}
void combate(Personaje& enemigo, Personaje& heroe) {
    int hAtack = heroe.getAttack();
    int hVida = heroe.getHp();
    int eAtack = enemigo.getAttack();
    int eVida = enemigo.getHp();
    system("cls");
    Sleep(2000);
    cout << "Hola " << heroe.getName() << " te has encontrado a  " << enemigo.getName() << " nos vamos a pegar \n";
       if (eVida>0){
        eVida = eVida - hAtack;
        enemigo.setHp(eVida);
        cout << "Vas atacar " << hAtack << " al enemigo le quedan " << eVida;
        Sleep(2000);
        }

    }

void combate(Boss& enemigo, Personaje& heroe) {
    system("cls");
    Sleep(2000);
    cout << "Hola " << heroe.getName() << " soy " << enemigo.getName() << " nos vamos a pegar \n";
    Sleep(2000);
    cout << "Ganaste Fin de la Aventura salvaste a Zelda";
    Sleep(2000);
}

int main() {
    cout << "Elige musica 1 Ganon 2 Templo 3 Tears \n";
    int mus;
    cin >> mus;

    switch (mus)
    {
    case 1:
        PlaySound(TEXT("Ganon.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
        break;
    case 2:
        PlaySound(TEXT("musica.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);

        break;
    case 3:
        PlaySound(TEXT("musica2.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
        break;

    default:
        break;
    }
    system("cls");



	//CREAMOS UN Heroe 
	Personaje Link(100, "Link", 30, 0, 0);
  
	//CREAMOS UN ENEMIGO 
	//Personaje bokoblin(100, "bokoblin", 10, 2, 1);

	//Personaje Guardian(200, "Guardian", 20, 3, 4);

	// BOSS
	Boss Ganon(400, "Ganon",20, 5,4,30,40 );


   
    srand(time(NULL));
    
        char grid[ROWS][COLS];

        // Inicializar la cuadrícula con caracteres vacíos
        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                grid[row][col] = '#';
            }
        }

        // Establecer al jefe en la última fila
        grid[BOSS_ROW][BOSS_COL] = 'B';
        grid[Fin_ROW][Fin_COL];
        // Crear enemigos aleatorios
        Personaje bokoblin(100, "Bokoblin", 10,generarNumeroAleatorio(0, ROWS - 1),generarNumeroAleatorio(0, COLS - 1));
        Personaje Guardian(50, "Guardian", 20, generarNumeroAleatorio(0, ROWS - 1), generarNumeroAleatorio(0, COLS - 1));
        Personaje Lizalfo(100, "Lizalfo", 10, generarNumeroAleatorio(0, ROWS - 1), generarNumeroAleatorio(0, COLS - 1));
        Personaje Keese(10, "Keese", 5, generarNumeroAleatorio(0, ROWS - 1), generarNumeroAleatorio(0, COLS - 1));

        // Imprimir la cuadrícula inicial
        system("cls");
        grid[0][0] = '/';
        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                cout << grid[row][col] << " ";
            }
            cout << endl;
        }

        int row_pos = 0;
        int col_pos = 0;

        // Moverse por la cuadrícula
        while (true) {
            // Obtener la tecla presionada
            char input = getch();

            // Moverse hacia arriba
            if (input == 'w' && row_pos > 0) {
                row_pos--;
            }
            // Moverse hacia abajo
            else if (input == 's' && row_pos < ROWS - 1) {
                row_pos++;
            }
            // Moverse hacia la izquierda
            else if (input == 'a' && col_pos > 0) {
                col_pos--;
            }
            // Moverse hacia la derecha
            else if (input == 'd' && col_pos < COLS - 1) {
                col_pos++;
            }
            // Salir del loop si se presiona la tecla 'q'
            else if (input == 'q') {
                break;
            }

        // Limpiar la consola y actualizar la posición del cursor
        system("cls");
        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                if (row == row_pos && col == col_pos) {
                    cout << '/' << " ";
                }
                else {
                    cout << '#' << " ";
                }
            }
            cout << endl;
        }
        if (row_pos == bokoblin.getPosicionX() && col_pos == bokoblin.getPosicionY()) {
            combate(bokoblin, Link);
        }
        else if (row_pos == Guardian.getPosicionX() && col_pos == Guardian.getPosicionY()) {
            combate(Guardian, Link);
        }
        else if (row_pos == Lizalfo.getPosicionX() && col_pos == Lizalfo.getPosicionY()) {
            combate(Lizalfo, Link);
        }
        else if (row_pos == Keese.getPosicionX() && col_pos == Keese.getPosicionY()) {
            combate(Keese, Link);
        }
        if (row_pos == Fin_ROW && col_pos == Fin_COL) {
            cout << "Encontraste la espada destructora del mal y has matado a todos";
            break;
        }
       
        // Verificar si el jugador encuentra a un enemigo
       
        // Si el jugador llega a la posición del jefe, mostrar mensaje y salir del loop
        if (row_pos == BOSS_ROW && col_pos == BOSS_COL) {
            combate(Ganon, Link);
            break;
        }
        }

        return 0;
    }

