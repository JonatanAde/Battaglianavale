//ADEMI JONATAN - Matricola: 2008796
/*La classe Tecnica racchiude la gestione delle due griglie e dei comandi che riceve in input.
Che sia dal main o da Tecnica.cpp, quando si vuole inserire una armata, si richiama la funzione
insert(Char) per inserire l'armata del tipo char {C,S,E} = Corazzata, Nave di Supporto e Sottomarino di esplorazione*/


#include <cstdlib>
#include <iostream>
#include "Tecnica.h"

//Costruttore vuoto, usato dal Player
Tecnica::Tecnica(){};

//Costruttore della CPU (Svolge il posizionamento autonomamente)
Tecnica::Tecnica(bool confirm){
	std::fill(*atk, *atk + 12*12, ' ');
	std::fill(*def, *def + 12*12, ' ');
	this -> cpu=confirm;
	if(this -> cpu==true){
		//richiama funzione di popolamento
		//3 Corazzate (C), 3 Navi di Supporto (S) e 2 Sottomarini di esplorazione (E)
	//Inserisce 1 corazzata orizzontale
		int x1, x2, y1, y2 = 0;
		srand(time(0));
		x1 = rand()%8;
		y1 = rand()%12;
		insert('C', x1, y1, x1+4, y1);
		for(int i=0; i<2; i++){
	//Inserisce 2 Corazzate verticali
			x1 = rand()%12;
			y1 = rand()%8;
			insert('C', x1, y1, x1, y1+4);
	//Inserisce 2 navi di Supporto verticali		
			x1 = rand()%12;
			y1 = rand()%9;
			insert('S', x1, y1, x1, y1+2);
	//Inserisce 2 sottomarini da Esplorazione
			x1 = rand()%12;
			y1 = rand()%12;
			insert('E', x1, y1, x1, y1);
		}
	}
};

//Metodo inserimento armate, in base al tipo dichiarato col Char
void Tecnica::insert(char tipo, int capoX, int capoY, int codaX, int codaY){
	//Esegue controllo delle coordinate nella tabella
	int x1, x2, y1, y2;
	x1=capoX-1;
	y1=capoY-1;
	x2=codaX-1;
	y2=codaY-1;
	while(!checkPosition(x1, y1, x2, y2)){
		//In caso di ostacoli, in base a chi richiama il metodo (CPU o Player), decide come inserire nuovi parametri
		if(cpu){
		//La CPU genera cordinate randomiche finché non ne lancia due accettabili
			x1 = rand()%8+1;
			y1 = rand()%8+1;
			x2 = x1+(codaX-capoX);
			y2 = y1+(codaY-capoY);
		}
		else {
		//Il giocatore sovvrascrive le coordinate date come parametro con nuove coordinate.
			std::cout<<"Coordinate non valide. RIPROVARE!"<<std::endl;
			std::cout<<"Le lettere devono essere maiuscole, tra A ed N."<<std::endl;
			std::cout<<"I numeri devono essere compresi tra 1 e 12."<<std::endl;
			char c1, c2;
			std::cin>>c1;
			std::cin>>y1;
			std::cin>>c2;
			std::cin>>y2;
			//Conversione c1 da char in int (con segno invalido, restituisce 0)
			switch(c1) {
				case 'A':
					x1=0;
					break;
				case 'B':
					x1=1;
					break;
				case 'C':
					x1=2;
					break;
				case 'D':
					x1=3;
					break;
				case 'E':
					x1=4;
					break;
				case 'F':
					x1=5;
					break;
				case 'G':
					x1=6;
					break;
				case 'H':
					x1=7;
					break;
				case 'I':
					x1=8;
					break;
				case 'L':
					x1=9;
					break;
				case 'M':
					x1=10;
					break;
				case 'N':
					x1=11;
					break;
				default:
					x1=0;
			}
			//Conversione c2 da char in int (con segno invalido, restituisce 0)
			switch(c2) {
				case 'A':
					x2=0;
					break;
				case 'B':
					x2=1;
					break;
				case 'C':
					x2=2;
					break;
				case 'D':
					x2=3;
					break;
				case 'E':
					x2=4;
					break;
				case 'F':
					x2=5;
					break;
				case 'G':
					x2=6;
					break;
				case 'H':
					x2=7;
					break;
				case 'I':
					x2=8;
					break;
				case 'L':
					x2=9;
					break;
				case 'M':
					x2=10;
					break;
				case 'N':
					x2=11;
					break;
				default:
					x2=0;
				}
			std::cout<<x1<<y1<<" "<<x2<<y2<<std::endl;
		}
	}
	if(x1==x2)
		for(int j=y1; j<=y2;j++)
			this -> def[x1][j]=tipo;
	if(y1==y2)
		for(int i=x1; i<=x2;i++)
			this -> def[i][y1]=tipo;	
};

//Metodo di controllo validità della posizione capo e coda destinataria
bool Tecnica::checkPosition(int capoX, int capoY, int codaX, int codaY){
	if(capoX!=codaX && capoY!=codaY)
		return false;
	if(capoX>codaX || capoY>codaY)
		return false;
	
	for(int i=capoX; i<=codaX;i++)
		for(int j=capoY; j<=codaY;j++)
			if(this -> def[i][j]!=' ' || capoX == 0 || codaX == 0)
				return false;
	
	return true;
};

//Metodo stampa griglia ATK e DEF
void Tecnica::showGrid(void){
	std::cout<<"\nGriglia Attacco\n"<<std::endl;
	
	char alfa[12]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'L', 'M', 'N'};
	std::cout<<"   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11| 12|"<<std::endl;
	for (int i = 0; i < 12; i++){
	std::cout<<"---┼---┼---┼---┼---┼---┼---┼---┼---┼---┼---┼---┼---┤"<<std::endl;
		std::cout<<" "<< alfa[i]<<" ";
		for (int j = 0; j < 12; j++)
			std::cout<<"| "<< this -> atk[i][j] << " ";
		std::cout << "|"<< std::endl;
	}
	std::cout<<"---┴---┴---┴---┴---┴---┴---┴---┴---┴---┴---┴---┴---┘"<<std::endl;
	std::cout<<"\nGriglia Difesa\n"<<std::endl;
	std::cout<<"   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11| 12|"<<std::endl;
	for (int i = 0; i < 12; i++){
	std::cout<<"---┼---┼---┼---┼---┼---┼---┼---┼---┼---┼---┼---┼---┤"<<std::endl;
		std::cout<<" "<< alfa[i]<<" ";
		for (int j = 0; j < 12; j++)
			std::cout<<"| "<< this -> def[i][j] << " ";
		std::cout << "|"<< std::endl;
	}
	std::cout<<"---┴---┴---┴---┴---┴---┴---┴---┴---┴---┴---┴---┴---┘"<<std::endl;
	
}

//Date due coordinate, svolgere il turno: C,S,E
bool Tecnica::action(int x1, int y1, int x2, int y2){
	char ship = checkType(x1, y1);
	if(ship=='C' || ship=='c'){
		//Azione Corazzata
	}
	else if(ship=='S' || ship=='s'){
		//Controllo validità coordinate
		if(checkPosition(x2-1,y2-1, x2+1, y2+1)){
			//Azione Nave di Supporto
		}
		return false;
	}
	else if(ship=='E' || ship=='e'){
		//Controllo validità coordinate
		if(checkPosition(x2,y2,x2,y2)){
			//Azione Nave di Supporto
		}
		return false;
		//Azione Sottomarino di Esplorazione
	}
	return false;
}

//Metodo di controllo di una singola casella, data le coordinate
char Tecnica::checkType(int x, int y){
	return this -> def[x][y];
}
/* bool Tecnica::checkHealth(int x, int y){
	//Si identifica il tipo di armata, da cui si deduce la sua vita massima (DIM), se i colpi ricevuti (counterHealth) sono pari 
	//alla sua vita massima, la nave va eliminata. Richiamare metodo killShip();
	char ship = Tecnica::checkType(x,y);
	int counterHealth, dim, i = 0;
	//Creiamo degli int per tenere traccia delle coordinate trovate in caso di nave abbattuta
	int deathX1, deathY1, deathX2, deathY2 = 0;
	bool found=false;
	if(ship=='c')
		dim=5;
	else if(ship=='s')
		dim=3;
	else if(ship=='e')
		dim=1;
	//Partiamo a controllare dall'asse x
	i=x-dim;
	while(!found&&i<(x+dim)){
		if(def[i,y]==ship){
			counterHealth++;
			if(counterHealth==1){
				deathX1 = i;
				deathY1 = y;
				deathY2 = y;
			}
		}
		else
			counterHealth=0;
		if(counterHealth==dim){
			found=true;
			deathX2=i;
		}
	}
	//Ora controlliamo l'asse y
	i=y-dim;
	while(!found&&i<(y+dim)){
		if(def[x,i]==ship){
			counterHealth++;
			if(counterHealth==1){
				deathY1 = i;
				deathX1 = x;
				deathX2 = x;
			}
		else
			counterHealth=0;
		if(counterHealth==dim){
			found=true;
			deathY2=i;
		}		
	}
	if(found)
		killShip(deathX1, deathY1, deathX2, deathY2);
	
	return (!found);
}


//Metodo svuotamento caselle
void Tecnica::killShip(int x1, int x2, int y1, int y2){
	if(x1==x2)
		for(int j=y1; j<y2;j++)
			this -> def[x1][j]=' ';
	if(y1==y2)
		for(int i=x1; i<x2;i++)
			this -> def[i][y1]=' ';
}*/