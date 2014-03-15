#include "ChessBoard.h"

using namespace std;
ChessBoard::ChessBoard()
{
	//ctor
	// noGame=1;
}

ChessBoard::~ChessBoard()
{
	//dtor
}
int ChessBoard::newBoard(){
	noGame++;
	resetBoard();
	return 0;
}
po ChessBoard::transformare(char * aux){
	char a = aux[0];
	char b = aux[1];
	char c = aux[2];
	char d = aux[3];
	int v1, v2, r1, r2;
	switch (a){
	case 'a':v1 = 1; break;
	case 'b':v1 = 2; break;
	case 'c':v1 = 3; break;
	case 'd':v1 = 4; break;
	case 'e':v1 = 5; break;
	case 'f':v1 = 6; break;
	case 'g':v1 = 7; break;
	case 'h':v1 = 8; break;
	}
	v2 = b - '0' + 1;
	r1 = v2 * 10 + v1;
	switch (c){
	case 'a':v1 = 1; break;
	case 'b':v1 = 2; break;
	case 'c':v1 = 3; break;
	case 'd':v1 = 4; break;
	case 'e':v1 = 5; break;
	case 'f':v1 = 6; break;
	case 'g':v1 = 7; break;
	case 'h':v1 = 8; break;
	}
	v2 = d - '0' + 1;
	r2 = v2 * 10 + v1;
	po a1;
	a1.start = r1;
	a1.fin = r2;
	return a1;
}
int ChessBoard::updateBoard(po x){
	if (b[x.fin].type != 'a' && b[x.fin].color != b[x.start].color){
		b[x.fin] = b[x.start];
		b[x.start].type = '0';
	}
	else {
		// cout<<"Mutare nepermisa!!!"<<endl;
		return 1;
	}
	return 0;
}
int ChessBoard::mutareRandom(int player_color){
	int ok = 0;
	char a[5];
	srand(time(0));
	while (ok == 0){
		//srand(time(0));
		int n = rand() % 8 + 1;
		a[0] = 'a' - 1 + n;
		//srand(time(0));
		n = rand() % 8 + 1;
		a[1] = '1' - 1 + n;
		a[2] = a[0];
		if (player_color == 1){
			a[3] = a[1] - 1;
		}
		else a[3] = a[1] + 1;
		a[5] = '\0';
		po x = transformare(a);

		//  cout<<<<endl;
		if (b[x.start].type == 'p' && b[x.start].color == player_color){
			// cout<<"aaa";
			if (b[x.fin].type == '0'){
				if (updateBoard(x) == 0){
					char str[10] = "move ";
					strcat(str, a);
					cout << str << endl;
					ok = 1;

				}
			}
			else{
				return 3;
			}


		}


	}
	return 0;
}
int ChessBoard::flipBoard(){
	for (int i = 20; i < 90; i++){
		if (b[i].color == 2){
			b[i].color = 1;
		}
		else
		if (b[i].color == 1){
			b[i].color = 2;
		}


	}
	return 0;
}
int ChessBoard::resetBoard(){
	for (int i = 0; i < 120; i++){

		if (i == 31){
			b[i].type = 'p';
			b[i].color = 2;
			i++;
			b[i].type = 'p';
			b[i].color = 2;
			i++;
			b[i].type = 'p';
			b[i].color = 2;
			i++;
			b[i].type = 'p';
			b[i].color = 2;
			i++;
			b[i].type = 'p';
			b[i].color = 2;
			i++;
			b[i].type = 'p';
			b[i].color = 2;
			i++;
			b[i].type = 'p';
			b[i].color = 2;
			i++;
			b[i].type = 'p';
			b[i].color = 2;
			i++;
		}
		if (i == 81){
			b[i].type = 'p';
			b[i].color = 1;
			i++;
			b[i].type = 'p';
			b[i].color = 1;
			i++;
			b[i].type = 'p';
			b[i].color = 1;
			i++;
			b[i].type = 'p';
			b[i].color = 1;
			i++;
			b[i].type = 'p';
			b[i].color = 1;
			i++;
			b[i].type = 'p';
			b[i].color = 1;
			i++;
			b[i].type = 'p';
			b[i].color = 1;
			i++;
			b[i].type = 'p';
			b[i].color = 1;
			i++;
		}
		if (i == 21){//coonsideram jucatoru alb sus si negru jos;
			b[i].type = 'r';
			b[i].color = 2;
			i++;
			b[i].type = 'n';
			b[i].color = 2;
			i++;
			b[i].type = 'b';
			b[i].color = 2;
			i++;
			b[i].type = 'q';
			b[i].color = 2;
			i++;
			b[i].type = 'k';
			b[i].color = 2;
			i++;
			b[i].type = 'b';
			b[i].color = 2;
			i++;
			b[i].type = 'n';
			b[i].color = 2;
			i++;
			b[i].type = 'r';
			b[i].color = 2;
			i++;
		}
		if (i == 91){
			b[i].type = 'r';
			b[i].color = 1;
			i++;
			b[i].type = 'n';
			b[i].color = 1;
			i++;
			b[i].type = 'b';
			b[i].color = 1;
			i++;
			b[i].type = 'q';
			b[i].color = 1;
			i++;
			b[i].type = 'k';
			b[i].color = 1;
			i++;
			b[i].type = 'b';
			b[i].color = 1;
			i++;
			b[i].type = 'n';
			b[i].color = 1;
			i++;
			b[i].type = 'r';
			b[i].color = 1;
			i++;

		}
		if (i<20)
			b[i].type = 'a';
		if (i % 10 == 0 || i % 10 == 9 || i>99)
			b[i].type = 'a';
		if (i > 40 && i % 10 > 0 && i % 10 < 9 && i < 79)
			b[i].type = '0';

	}
	return 0;
};
/*typedef struct {
int start;int fin;
} po;*/
po transformare(char * aux){
	char a = aux[0];
	char b = aux[1];
	char c = aux[2];
	char d = aux[3];
	int v1, v2, r1, r2;
	switch (a){
	case 'a':v1 = 1; break;
	case 'b':v1 = 2; break;
	case 'c':v1 = 3; break;
	case 'd':v1 = 4; break;
	case 'e':v1 = 5; break;
	case 'f':v1 = 6; break;
	case 'g':v1 = 7; break;
	case 'h':v1 = 8; break;
	}
	v2 = b - '0' + 1;
	r1 = v2 * 10 + v1;
	switch (c){
	case 'a':v1 = 1; break;
	case 'b':v1 = 2; break;
	case 'c':v1 = 3; break;
	case 'd':v1 = 4; break;
	case 'e':v1 = 5; break;
	case 'f':v1 = 6; break;
	case 'g':v1 = 7; break;
	case 'h':v1 = 8; break;
	}
	v2 = d - '0' + 1;
	r2 = v2 * 10 + v1;
	po a1;
	a1.start = r1;
	a1.fin = r2;
	return a1;
}
