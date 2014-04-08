#ifndef CHESSPIECES_H
#define CHESSPIECES_H
#include "ChessBoard.h"

typedef struct{
    int m[50];
    int size;
    int poz;
}  Moves;

class ChessPieces
{
    public:
        ChessPieces();
        virtual ~ChessPieces();
        Moves random_move_gen(Elemente b[],int color);
        Moves pawn_moves(int poz,Elemente b[],int color);
        Moves nite_moves(int poz,Elemente b[],int color);
        Moves rock_moves(int poz,Elemente b[],int color);
        Moves bishop_moves(int poz ,Elemente b[],int color);
        Moves king_moves(int poz,Elemente b[],int color);
        Moves queen_moves(int poz,Elemente b[],int color);
        Moves isChess(int poz_king,Elemente b[],int color);
    protected:
    private:
};

#endif // CHESSPIECES_H
