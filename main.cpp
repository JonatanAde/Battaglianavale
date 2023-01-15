#include <iostream>
#include <cstdlib>
#include "Tecnica.cpp"



int main(int argc, char *argv[]) {
	Tecnica CPU = Tecnica(true);
	Tecnica Player = Tecnica(false);
	Player.insert('C', 10, 3, 10, 7);
	Player.insert('C', 2, 3, 6, 3);
	Player.showGrid();
	
	int maxTurni = 10;
	
	for(int i=0; i < maxTurni;i++){}
	
	return 0;
}

//Prendiamo la differenza tra coo. di partenza e quella di arrivo. 
/*
void Ship::Moves(int x, int y){
	int diffX = pMedio.first - x;
	int diffY = pMedio.second - y;
	
	int x1Arrivo = prua.first + diffX;
	int x2Arrivo = prua.second + diffY;
	int y1Arrivo = poppa.first + diffX;
	int y2Arrivo = poppa.second + diffY;
	
	if(x1Arrivo==x2Arrivo){
		i=prua.first;
		for(int j=prua.second; j<=poppa.second;j++){
			def[x1Arrivo][j]=def[i][j];
			i++;
		}
	}
	if(y1Arrivo==y2Arrivo){
		i=prua.second;
		for(int j=prua.second; j<=poppa.second;j++){
			def[x1Arrivo][i]=def[j][i];
			i++;
		}
	}
}
*/