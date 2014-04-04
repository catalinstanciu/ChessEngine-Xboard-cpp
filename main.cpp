/*TEAM CodeWatchers :
    Stanciu Catalin 322CA
    Dobrin Tanase-Alexandru 322CA
	Nedelcu Mihai-Ovidiu 322CA
	Crac Mihai Ovidiu 322CA
	*/
//#include "ChessBoard.h"
#include "include/ChessPieces.h"
using namespace std;
ofstream g("out.txt");
ChessBoard moveToGetOutFromChess(ChessBoard c){
    srand(time(0));
    ChessPieces p;
    Moves x;
    pieceLocation y;
    Elemente aux;
    while (p.isChess(c.kingPosition,c.b).size!=0)
          for(int k =21;k<=98;k++){
            if (c.b[k].color == 1){
                switch (c.b[k].type) {
                    case 'p':{x = p.pawn_moves(k , c.b);x.poz = k;}break;
                    case 'r':{x = p.rock_moves(k , c.b);x.poz = k;}break;
                    case 'b':{x = p.bishop_moves(k , c.b);x.poz = k;}break;
                    case 'k':{x = p.king_moves(k , c.b);x.poz = k;}break;
                    case 'q':{x = p.queen_moves(k , c.b);x.poz = k;}break;
                    case 'n':{x = p.nite_moves(k , c.b);x.poz = k;}break;
                }
                for(int j=0;j<x.size;j++){
                    y.start = x.poz;
                    y.fin = x.m[j];
                    aux = c.b[y.fin];
                    c.updateBoard(y);
                    if (y.start==c.kingPosition){
                        c.kingPosition = y.fin;
                    }
                    g<<"assjjjjj\n";
                    if (p.isChess(c.kingPosition,c.b).size==0) {
                            g<<"intra "<<y.start<<" "<<y.fin<<"si pozitia regelui "<<c.kingPosition<<endl;
                            char* a = c.locationToString(y);
                            char str[10] = "move ";
                            strcat(str, a);
                            cout << str << endl;
                            return c;
                    }
                    else {
                    //revenire la tabla initiala
                    if (y.fin==c.kingPosition){
                            c.kingPosition = y.start;
                    }
                    y.start = x.m[j];
                    y.fin = x.poz;
                    c.updateBoard(y);
                    c.b[y.start] = aux;

                    /*for(int p=0;p<p.isChess(c.kingPosition,c.b).size;p++){

                    }*/
                    }

                }
            }

        }

    return c;
}
ChessBoard moveRandom(ChessBoard c){
    srand(time(0));
    ChessPieces p;
    Moves x;

    x = p.random_move_gen(c.b);
    int r = rand() % x.size;
    int m = x.m[r];
    pieceLocation y;
    int ok=1;
    Elemente aux;
    while (ok==1){
        y.start = x.poz;
        y.fin = m;
        aux = c.b[y.fin];
        c.updateBoard(y);
        if(y.start == c.kingPosition){
            c.kingPosition = y.fin;
        }
        if (p.isChess(c.kingPosition,c.b).size!=0){
            if(y.fin == c.kingPosition){
                c.kingPosition=y.start;
            }
            y.start = m;
            y.fin = x.poz;
            c.updateBoard(y);
            c.b[y.start] = aux;
            x = p.random_move_gen(c.b);
            r = rand() % x.size;
            m = x.m[r];
        }
        else {
            ok=0;
        }
    }
    if(y.start == c.kingPosition){
        c.kingPosition = y.fin;
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
	int his=1;
    int colorup=1;
    ChessPieces p;

	char buff[200];
	ChessBoard c;
	c.newBoard();
	int enginemode=1;
	while (quitGame == 0){
		cin >> buff;
		g<<buff<<endl;
        if (strcmp(buff, "force") == 0) {
            his=enginemode;
            enginemode=0;
		}
		/*if (strlen(buff) == 5 &&  buff[3] - '0' <= 9 && buff[1] - '0' >= 1&&enginemode==1){
            pieceLocation x = c.transformare(buff);
            c.updateBoard(x);
            c.b[x.fin].type = buff[4];
            enginemode=2;
		}*/
		if (strlen(buff) == 4 && buff[3] - '0' <= 9 && buff[1] - '0' >= 1&&enginemode==1){
			pieceLocation x = c.transformare(buff);
			c.updateBoard(x);
			enginemode=2;
		}
		if(enginemode==2){
            //daca este sah fa mutare de iesire din sah
           /* int resign = c.mutareRandom(colorup);
			if (resign == 3){
				strcpy(buff, "resign");
			}*/

			if (p.isChess(c.kingPosition,c.b).size==0){
                g<<"go to moverandom"<<endl;
                c = moveRandom(c);
			}
			else {
                    g<<"moveToGetOutFromChess"<<endl;
                    c = moveToGetOutFromChess(c);
            }

            for (int i=120;i>0;i--){
                g<<c.b[i].type<<" ";
                if (i % 10 == 0) g<<endl;
            }
            g<<c.kingPosition<<" pozitie rege"<<endl;
			enginemode=1;
		}
		if (strcmp(buff, "xboard") == 0) {
			cout << "feature myname=\"CodeWatchersChessEngine\"" << endl;
		}
		if (strcmp(buff, "new") == 0) {
			c.resetBoard();
			colorup=1;
			enginemode =1;
			his=1;
			cout << buff << endl;
		}

		if (strcmp(buff, "white") == 0) {
            colorup=2;
            c.flipBoard();
            c.mutareRandom(colorup);
		}

		if (strcmp(buff, "black") == 0) {
            colorup=1;
            c.flipBoard();
            c.mutareRandom(colorup);
		}

		if (strcmp(buff, "quit") == 0) {
                return 0;
		}

		if (strcmp(buff, "resign") == 0) {
			cout << buff << endl;
		}

        if (strcmp(buff, "go") == 0) {
            enginemode=his;
        }
	}

	return 0;
}
