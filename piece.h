#ifndef PIECE_H
#define PIECE_H

namespace chess
{
    class piece
    {
    protected:
        char id, colour;
        bool status{false}; // if piece has moved or not
    public:
        piece(char c, char i): colour{c}, id{i} {};
        char get_id();
        char get_colour();
        bool has_moved();
        void set_has_moved();
        virtual bool is_move_allowed(piece* temp[8][8], int irow, int icol, int frow, int fcol) = 0;
    };
}

#endif