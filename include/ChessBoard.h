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
	char type;//king,roock...etc.
	int color;//1 alb, 2 negru
} Elemente;

class ChessBoard
{
public:
	ChessBoard();
	virtual ~ChessBoard();


	Elemente b[120];
	int noGame;

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
