/*TEAM CodeWatchers :
Stanciu Catalin 322CA
Dobrin Tanase-Alexandru 322CA
Nedelcu Mihai-Ovidiu 322CA
Crac Mihai Ovidiu 322CA
*/

#include "ChessPieces.h"

using namespace std;

ChessBoard moveToGetOutFromChess(ChessBoard c, int color){
	srand(time(0));
	ChessPieces p;
	Moves x;
	pieceLocation y;
	Elemente aux;
	for (int k = 21; k <= 98; k++){
		if (c.b[k].color == 1){
			switch (c.b[k].type) {
			case 'p':{x = p.pawn_moves(k, c.b, color); x.poz = k; }break;
			case 'r':{x = p.rock_moves(k, c.b, color); x.poz = k; }break;
			case 'b':{x = p.bishop_moves(k, c.b, color); x.poz = k; }break;
			case 'k':{x = p.king_moves(k, c.b, color); x.poz = k; }break;
			case 'q':{x = p.queen_moves(k, c.b, color); x.poz = k; }break;
			case 'n':{x = p.nite_moves(k, c.b, color); x.poz = k; }break;
			}
			for (int j = 0; j < x.size; j++){
				y.start = x.poz;
				y.fin = x.m[j];
				aux = c.b[y.fin];
				c.updateBoard(y);
				if (y.start == c.kingPosition){
					c.kingPosition = y.fin;
				}
				if (p.isChess(c.kingPosition, c.b, color).size == 0) {
					if (c.b[y.fin].type == 'p' && (y.fin / 10 == 9 || y.fin / 10 == 2)){
						c.b[y.fin].type = 'q';
					}
					char* a = c.locationToString(y);
					char str[10] = "move ";
					strcat(str, a);
					cout << str << endl;
					return c;
				}
				else {
					//revenire la tabla initiala
					if (y.fin == c.kingPosition){
						c.kingPosition = y.start;
					}
					y.start = x.m[j];
					y.fin = x.poz;
					c.updateBoard(y);
					c.b[y.start] = aux;
				}

			}
		}

	}

	return c;
}
ChessBoard moveRandom(ChessBoard c, int color){
	srand(time(0));
	ChessPieces p;
	Moves x;
	x = p.random_move_gen(c.b, color);
	int r = rand() % x.size;
	int m = x.m[r];
	pieceLocation y;
	int ok = 1;
	Elemente aux;
	while (ok == 1){
		y.start = x.poz;
		y.fin = m;
		aux = c.b[y.fin];
		c.updateBoard(y);
		if (y.start == c.kingPosition){
			c.kingPosition = y.fin;
		}
		if (p.isChess(c.kingPosition, c.b, color).size != 0){
			if (y.fin == c.kingPosition){
				c.kingPosition = y.start;
			}
			y.start = m;
			y.fin = x.poz;
			c.updateBoard(y);
			c.b[y.start] = aux;
			x = p.random_move_gen(c.b, color);
			r = rand() % x.size;
			m = x.m[r];
		}
		else {
			ok = 0;
		}
	}
	if (y.start == c.kingPosition){
		c.kingPosition = y.fin;
	}
	if (c.b[y.fin].type == 'p' && (y.fin / 10 == 9 || y.fin / 10 == 2)){
		c.b[y.fin].type = 'q';
	}
	char* a = c.locationToString(y);
	char str[10] = "move ";
	strcat(str, a);
	cout << str << endl;
	return c;
}
int main(int argc, char ** argv){
	cout.setf(ios::unitbuf);
	int quitGame = 0;
	int colorup = 1;
	ChessPieces p;
	char buff[200];
	ChessBoard c;
	c.newBoard();
	int enginemode = 1;
	while (quitGame == 0){
		cin >> buff;
		if (strcmp(buff, "result") == 0) {
            strcpy(buff, "new");
		}
		if (strcmp(buff, "new") == 0) {
			c.resetBoard();
			colorup = 1;
			enginemode = 1;
			cout << buff << endl;
			ChessPieces p;
			ChessBoard c;
			c.newBoard();
		}

		if (strlen(buff) == 5 && buff[3] - '0' <= 9 && buff[1] - '0' >= 1 && (buff[0] >= 'a'&&buff[0] <= 'z') && enginemode == 1){
			pieceLocation x = c.transformare(buff);
			c.updateBoard(x);
			c.b[x.fin].type = buff[4];
			enginemode = 2;
		}

		if (strlen(buff) == 4 && buff[3] - '0' <= 9 && buff[1] - '0' >= 1 && enginemode == 1){
			int check = 1;
			pieceLocation x = c.transformare(buff);
			if (strcmp(buff, "e1g1") == 0 && c.b[x.start].type == 'k') {
				//rocada mica
				c.b[27] = c.b[25];
				c.b[25].type = '0';
				c.b[25].color = 0;
				c.b[26] = c.b[28];
				c.b[28].type = '0';
				c.b[28].color = 0;
				check = 0;
			}

			if (strcmp(buff, "e1c1") == 0 && c.b[x.start].type == 'k') {
				//rocada mare
				c.b[23] = c.b[25];
				c.b[25].type = '0';
				c.b[25].color = 0;
				c.b[24] = c.b[21];
				c.b[21].type = '0';
				c.b[21].color = 0;
				check = 0;
			}
			if (strcmp(buff, "e8c8") == 0 && c.b[x.start].type == 'k') {
				//rocada mica
				c.b[96] = c.b[94];
				c.b[94].type = '0';
				c.b[94].color = 0;
				c.b[95] = c.b[98];
				c.b[98].type = '0';
				c.b[98].color = 0;
				check = 0;
			}

			if (strcmp(buff, "e8g8") == 0 && c.b[x.start].type == 'k') {
				//rocada mare
				c.b[92] = c.b[94];
				c.b[94].type = '0';
				c.b[94].color = 0;
				c.b[93] = c.b[91];
				c.b[91].type = '0';
				c.b[91].color = 0;
				check = 0;
			}
			if (check == 1){
				if (c.b[x.start].type == 'p'&&c.b[x.fin].type == '0'
					&& (x.start == x.fin + 9 || x.start == x.fin + 11 || x.start == x.fin - 9 || x.start == x.fin - 11)){
					if (x.start > x.fin){
						c.b[x.fin + 10].type = '0';
						c.b[x.fin + 10].color = 0;
					}
					else {
						c.b[x.fin - 10].type = '0';
						c.b[x.fin - 10].color = 0;
					}

				}
				c.updateBoard(x);
			}
			enginemode = 2;
		}

		if (enginemode == 2){
			if (p.isChess(c.kingPosition, c.b, colorup).size == 0){
				c = moveRandom(c, colorup);
			}
			else {
				c = moveToGetOutFromChess(c, colorup);
			}
			enginemode = 1;
		}
		if (strcmp(buff, "xboard") == 0) {
			cout << "feature myname=\"CodeWatchersChessEngine\"" << endl;
		}

		if (strcmp(buff, "white") == 0) {
			colorup = 2;
			c.flipBoard();
			if (p.isChess(c.kingPosition, c.b, colorup).size == 0){
				c = moveRandom(c, colorup);
			}
			else {
				c = moveToGetOutFromChess(c, colorup);
			}
		}

		if (strcmp(buff, "black") == 0) {
			colorup = 1;
			c.flipBoard();
			if (p.isChess(c.kingPosition, c.b, colorup).size == 0){
				c = moveRandom(c, colorup);
			}
			else {
				c = moveToGetOutFromChess(c, colorup);
			}
		}

		if (strcmp(buff, "quit") == 0) {
			return 0;
		}

		if (strcmp(buff, "resign") == 0) {
			cout << buff << endl;
		}
	}
	return 0;
}
