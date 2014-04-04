#ifndef CHESSPIECES_H
#define CHESSPIECES_H
#include "../ChessBoard.h"
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
        Moves random_move_gen(Elemente b[]);
        Moves pawn_moves(int poz,Elemente b[]);
        Moves nite_moves(int poz,Elemente b[]);
        Moves rock_moves(int poz,Elemente b[]);
        Moves bishop_moves(int poz ,Elemente b[]);
        Moves king_moves(int poz,Elemente b[]);
        Moves queen_moves(int poz,Elemente b[]);
        Moves isChess(int poz_king,Elemente b[]);
    protected:
    private:
};

#endif // CHESSPIECES_H
