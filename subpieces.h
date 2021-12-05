#ifndef SUBPIECES_H
#define SUBPIECES_H

#include "piece.h"

namespace chess
{
    class pawn : public piece
    {
    public:
        pawn(char c): piece{c, 'P'} {};
        bool is_move_allowed(piece* temp[8][8], int irow, int icol, int frow, int fcol);
    };

    class king : public piece
    {
    public:
        king(char c): piece{c, 'K'} {};
        bool is_move_allowed(piece* temp[8][8], int irow, int icol, int frow, int fcol);
    };

    class queen : public piece
    {
    public:
        queen(char c): piece{c, 'Q'} {};
        bool is_move_allowed(piece* temp[8][8], int irow, int icol, int frow, int fcol);
    };

    class bishop : public piece
    {
    public:
        bishop(char c): piece{c, 'B'} {};
        bool is_move_allowed(piece* temp[8][8], int irow, int icol, int frow, int fcol);
    };

    class knight : public piece
    {
    public:
        knight(char c): piece{c, 'N'} {};
        bool is_move_allowed(piece* temp[8][8], int irow, int icol, int frow, int fcol);
    };

    class rook : public piece
    {
    public:
        rook(char c): piece{c, 'R'} {};
        bool is_move_allowed(piece* temp[8][8], int irow, int icol, int frow, int fcol);
    };
}

#endif