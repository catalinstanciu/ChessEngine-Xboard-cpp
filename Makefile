
CC = g++
CFLAGS = -Wall
SRC = ChessPieces.cpp ChessBoard.cpp main.cpp
EXE = ChessEngine
 
all:
	$(CC) -o $(EXE) $(SRC) $(CFLAGS)
 
.PHONY : clean
clean :
	rm -f $(EXE) *~