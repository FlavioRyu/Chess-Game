#ifndef BOARD_H
#define BOARD_H

#include "piece.h"
#include "subpieces.h"
#include <string>


namespace chess
{
    class board
    {
    private:
        char turncolour{'W'};
        int ranks[8] = {8, 7, 6, 5, 4, 3, 2, 1};
        char files[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
        int wking_row, wking_col, bking_row, bking_col;
        piece* position[8][8]{nullptr};
    public:
        board();
        ~board();
        // miscellaneous functions
        void print_board();
        char get_turncolour();
        void alternate_turn();
        void start_message();
        void end_message_win(std::string& player);
        void end_message_draw();
        // move-related functions
        void make_move();
        void input_checker(std::string& input);
        int input_converter(char& i, int mode);
        // king-related functions
        void find_kings(piece* temp[8][8]);
        bool is_king_check(piece* temp[8][8], char& king_colour);
        bool will_king_check(int irow, int icol, int frow, int fcol, char king_colour);
        bool can_king_move(char king_colour);
        bool can_any_move();
        bool is_checkmate();
        bool is_stalemate();
        // special moves
        void pawn_promotion(int row, int col);
        bool castling(char king_colour, int fcol);
    };
}

#endif