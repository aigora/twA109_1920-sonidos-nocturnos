#include <stdio.h>
#include <windows.h>
#include<conio.h>
#include<stdlib.h>
#define LIMIZ 2
#define LIMDER 60
//introduzco la funcion de movimiento, en la cual introducimos la funcion SetConsolePosition para controlar la posicion en pantalla

void gotoxy (int x,int y) //con la funcion gotoxy establecemos unas coordenadas introducidas por nosotros
{
	HANDLE hCon;
	hCon = GetStdHandle (STD_OUTPUT_HANDLE);
	
	COORD dwPos; //estructura coordenada
	dwPos.X=x;
	dwPos.Y=y;
	

	SetConsoleCursorPosition (hCon,dwPos);	
}

void OcultarCursor()//con esto quitamos el molesto cursor que espera letras a introducir
{
	HANDLE hCon;
	hCon = GetStdHandle (STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;	//estructura del cursor
	cci.dwSize=50;
	cci.bVisible=FALSE;
		
	SetConsoleCursorInfo(hCon,&cci);
}
class NAVE //introducimos el tipo de elemento nave
{
	int x,y;
public:
	NAVE(int _x,int _y): x(_x),y(_y){}
	void pintar();
	void borrar();
	void mover();


};


void NAVE::pintar()
{
	gotoxy(x,y); printf("  A");
	gotoxy(x,y+1); printf(" wHw");
	gotoxy(x,y+2); printf("WWHWW");
	
}

void NAVE::borrar()//para que la nave no deje una estela 
{
	gotoxy(x,y); printf("     ");
	gotoxy(x,y+1); printf("     ");
	gotoxy(x,y+2); printf("     ");
	
	
}

void NAVE::mover()
{
//con kbhit comprobamos si el jugador ha pulsado una letra
		if(kbhit())
		{
			char tecla=getch();
			borrar();
			if((tecla=='a'or tecla=='A')and x>LIMIZ ) x--;
			if((tecla=='d'or tecla=='D')and x+6<LIMDER)x++;
	//Pensaremos si mover vertical o no		if(tecla=='s'or tecla=='S') y++;
	//			if(tecla=='w'or tecla=='W')y--;
			pintar();
			}
}


int main()
{
	OcultarCursor();
	NAVE USER(30,30);
	USER.pintar();
	
	// introduzco ahora variable logica para que la funcion de movimiento
	//se ejecute hasta que muramos
	bool game_over = false;
	
	while(!game_over)
	{	
	USER.mover();

			Sleep(20);
	
		
	}
	
	
	return 0;
}
