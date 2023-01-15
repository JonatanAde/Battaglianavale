//ADEMI JONATAN - Matricola: 2008796
/*La classe Tecnica racchiude la gestione delle due griglie e i metodi dei comandi di input.
Che sia dal main o da Tecnica.cpp, quando si vuole inserire una armata, si richiama la funzione
insert(Char) per inserire l'armata del tipo char {C,S,E} = Corazzata, Nave di Supporto e Sottomarino di esplorazione*/


#ifndef TECNICA_H
#define TECNICA_H
#include <ostream>
#include "Ship.hpp"
#include "Corazzata.hpp"
#include "Nds.hpp"
#include "Sde.hpp"

class Tecnica{
public:
//Costruttore per le griglie del giocatore
	Tecnica();
//Costruttore per le grigle della CPU, genera randomicamente le posizioni delle armate
	Tecnica(bool);
	
//Metodo inserimento corazzate, in caso di caselle occupate (richiama checkPosition), inserisce nuove coordinate
	void insert(char tipo, int capoX, int capoY, int codaX, int codaY);
	
//Metodo controllo correttezza della coordinata
	bool checkPosition(int capoX, int capoY, int codaX, int codaY);
	
//Metodo visualizzazione delle griglie. "XX XX"
	void showGrid(void);
	
//Metodo di "Guarda che nave trovi ed esegui"
	bool action(int x1, int y1, int x2, int y2);
	
//Metodo di controllo di una singola casella, data le coordinate e la griglia da controllare
	char checkType(int x, int y);
	
	
	/*
//Metodo di controllo quando un'armata viene colpita
	bool checkHealth(int x, int y);

//Metodo abbattimento di una armata quando viene distrutta
	void killShip(int x1, int y1, int x2, int y2);
	*/
	
private:
	char atk[12][12];
	char def[12][12];
	bool cpu = false;
};

#endif //TECNICA_H


//controllo: quando colpisci, acquisisci la lettera e da essa il numero (X) di caselle.
//controllo di tot posizioni finche non trovi X caselle != ' '