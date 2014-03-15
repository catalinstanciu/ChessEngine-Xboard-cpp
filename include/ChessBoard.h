#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef struct {
	int start; int fin;
} po;

typedef struct{
	int aux;
	char type;//king,pawn,etc.
	int color;//2 alb, 1 negru
} Elemente;

class ChessBoard
{
public:
	ChessBoard();
	virtual ~ChessBoard();
	//variabile
	Elemente b[120];
	int noGame;
	//functiile tablei de sah
	int newBoard();
	int resetBoard();
	int generateBoardMatrix();
	po transformare(char * aux);
	int updateBoard(po x);
	int mutareRandom(int player_color);
	int flipBoard();

protected:
private:
};
