#include "ChessBoard.h"

using namespace std;
ChessBoard::ChessBoard()
{
    kingPosition = 95;

}

ChessBoard::~ChessBoard()
{
}
int ChessBoard::newBoard(){
	noGame++;
	resetBoard();
	return 0;
}
pieceLocation ChessBoard::transformare(char * aux){
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
	pieceLocation a1;
	a1.start = r1;
	a1.fin = r2;
	return a1;
}
int ChessBoard::updateBoard(pieceLocation x){
	//if (b[x.fin].type == '0'){
        Elemente aux;
        if (b[x.fin].type!='0' /*&& b[x.start].type!='0'*/){
            b[x.fin] = b[x.start];
            b[x.start].type='0';
            b[x.start].color= 0 ;
        }
        else {
            aux = b[x.fin];
            b[x.fin] = b[x.start];
            b[x.start]=aux;
        }
	//}
	//else {
		//Mutare nepermisa!
	//	return 1;
	//}
	return 0;
}
char* ChessBoard::locationToString(pieceLocation x){
    char a[5];
    a[0] = 'a' - 1 + x.start%10;
    a[1] = '1' - 2 + x.start/10;
    a[2] = 'a' - 1 + x.fin%10;
    a[3] = '1' - 2 + x.fin/10;
    a[4] = '\0';
    return a;

}
int ChessBoard::mutareRandom(int player_color){
	int ok = 0;
	char a[5];
	srand(time(0));
	while (ok == 0){
		int n = rand() % 8 + 1;
		a[0] = 'a' - 1 + n;
		n = rand() % 8 + 1;
		a[1] = '1' - 1 + n;
		a[2] = a[0];
		if(player_color == 1){
            a[3] = a[1] - 1;
		}
            else a[3]=a[1] + 1;
		a[5] = '\0';
		pieceLocation x = transformare(a);

		if (b[x.start].type == 'p' && b[x.start].color == player_color){
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
    for (int i = 21; i < 59; i++){
        Elemente aux;
        aux = b[i];
        b[i] = b[99 - i + 20];
        b[99 - i + 20] = aux;
    }
return 0;
}
int ChessBoard::resetBoard(){
    kingPosition = 95;
	for (int i = 0; i < 120; i++){
		if (i == 31){
			b[i].type = 'p';
			b[i].color = 2;// 2 e om
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
		if (i == 21){
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
pieceLocation transformare(char * aux){
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
	pieceLocation a1;
	a1.start = r1;
	a1.fin = r2;
	return a1;
}
