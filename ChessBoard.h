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
} pieceLocation;

typedef struct{
	int aux;
	char type;
	int color;
} Elemente;

class ChessBoard
{
public:
    int kingPosition;
	ChessBoard();
	virtual ~ChessBoard();

	Elemente b[120];
	int noGame;
    char* locationToString(pieceLocation x);
	int newBoard();
	int resetBoard();
	int generateBoardMatrix();
	pieceLocation transformare(char * aux);
	int updateBoard(pieceLocation x);
	int mutareRandom(int player_color);
	int flipBoard();

protected:
private:
};
