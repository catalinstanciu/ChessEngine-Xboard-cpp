#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

typedef struct {
	int start;
	int fin;
} pieceLocation;

typedef struct{
	int aux;
	char type;
	int color;
} Elemente;

class ChessBoard {
public:

	ChessBoard();
	virtual ~ChessBoard();
    int kingPosition;
	Elemente b[120];
	int noGame;
    char* locationToString(pieceLocation x);
	int newBoard();
	int resetBoard();
	pieceLocation transformare(char * aux);
	int updateBoard(pieceLocation x);
	int flipBoard();

protected:
private:
};
