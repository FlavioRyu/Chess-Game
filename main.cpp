#include "board.h"
#include <iostream>

using namespace chess;

int main()
{
    board chessboard;
    bool is_draw{false};
    chessboard.start_message();
    chessboard.print_board();
    while (true) {
        chessboard.make_move();
        chessboard.alternate_turn();
        if (chessboard.is_checkmate()) {
            chessboard.print_board();
            std::string winning_player;
            winning_player = (chessboard.get_turncolour() == 'W') ? "Black" : "White";
            chessboard.end_message_win(winning_player);
            break;
        } else if (chessboard.is_stalemate()) {
            chessboard.print_board();
            chessboard.end_message_draw();
            break;
        }
        chessboard.print_board();
    }
    return 0;
}