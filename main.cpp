
#include "ChessBoard.h"


using namespace std;

int main(int argc, char ** argv){
	ofstream g("out.txt");

	cout.setf(ios::unitbuf);
	int quitGame = 0;
	int winBoard = 0;
	int his = 1;
	int colorup = 1;

	char buff[200];
	ChessBoard c;
	c.newBoard();
	int enginemode = 1;
	while (quitGame == 0){
		cin >> buff;
		g << "comanda primita:";
		g << buff << endl;
		if (strcmp(buff, "force") == 0) {
			his = enginemode;
			enginemode = 0;
			cout << "HIS esteeeeeeee:" << his;
		}
		//buff[1]-'0'<=9&&buff[1]-'0'>=1
		if (strlen(buff) == 4 && buff[3] - '0' <= 9 && buff[1] - '0' >= 1 && enginemode == 1){
			po x = c.transformare(buff);
			g << x.start << " " << x.fin << endl;
			c.updateBoard(x);
			enginemode = 2;

		}
		if (enginemode == 2){
			int bb = c.mutareRandom(colorup);
			if (bb == 3){
				strcpy(buff, "resign");

			}
			enginemode = 1;
		}
		if (strcmp(buff, "xboard") == 0) {
			winBoard = 1;

			cout << "feature myname=\"CodeWatchersChessEngine\"" << endl;
		}
		if (strcmp(buff, "new") == 0) {
			c.resetBoard();
			colorup = 1;
			enginemode = 1;
			his = 1;
			cout << buff << endl;
		}

		if (strcmp(buff, "time") == 0) {
			for (int i = 0; i < 120; i++){
				if (i % 10 == 9){
					cout << c.b[i].type << endl;
				}
				else {
					cout << c.b[i].type << " ";
				}
			}
		}
		if (strcmp(buff, "white") == 0) {
			//enginemode=2;
			colorup = 2;

			c.flipBoard();
			c.mutareRandom(colorup);

		}
		if (strcmp(buff, "black") == 0) {
			//enginemode=1;
			colorup = 1;
			// c.resetBoard();
			c.flipBoard();
			c.mutareRandom(colorup);
		}
		if (strcmp(buff, "quit") == 0) {
			return 0;
		}
		if (strcmp(buff, "resign") == 0) {
			//quitGame = 1;
			cout << buff << endl;
		}

		if (strcmp(buff, "go") == 0) {
			enginemode = his;
			//
		}

	}
	cin >> buff;

	return 0;
}
