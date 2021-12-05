#include "subpieces.h"
#include "board.h"
#include <algorithm>

using namespace chess;

bool pawn::is_move_allowed(piece* temp[8][8], int irow, int icol, int frow, int fcol)
{
    int flag{0};
    if (this->get_colour() == 'W') { // white pawn
        if (frow == irow - 1) {
            if ((fcol == icol - 1 && temp[irow-1][icol-1]->get_colour() == 'B') || 
                (fcol == icol + 1 && temp[irow-1][icol+1]->get_colour() == 'B') || 
                (fcol == icol && temp[irow-1][icol] == nullptr)) {
                flag = 1;
            }
        } else if (frow == irow - 2 && !has_moved()) {
            if (fcol == icol && temp[irow-1][icol] == nullptr && temp[irow-2][icol] == nullptr) {
                flag = 1;
            }
        }
    } else { // black pawn
        if (frow == irow + 1) {
            if ((fcol == icol - 1 && temp[irow+1][icol-1]->get_colour() == 'W') || 
                (fcol == icol + 1 && temp[irow+1][icol+1]->get_colour() == 'W') || 
                (fcol == icol && temp[irow+1][icol] == nullptr)) {
                flag = 1;
            }
        } else if (frow == irow + 2 && !has_moved()) {
            if (fcol == icol && temp[irow+1][icol] == nullptr && temp[irow+2][icol] == nullptr) {
                flag = 1;
            }
        }
    }
    if (flag == 1) {
        return true;
    } else {
        return false;
    }
}

bool bishop::is_move_allowed(piece* temp[8][8], int irow, int icol, int frow, int fcol)
{
    int obstacle{0};
    if (abs(frow - irow) == abs(fcol - icol)) {
        int distance{abs(frow - irow)};
        if (distance > 1) {
            if (frow - irow < 0 && fcol - icol < 0) {
                for (int n{1}; n < distance; n++) {
                    if (temp[irow-n][icol-n] != nullptr) {
                        obstacle++;
                    }
                }
            } else if (frow - irow < 0 && fcol - icol > 0) {
                for (int n{1}; n < distance; n++) {
                    if (temp[irow-n][icol+n] != nullptr) {
                        obstacle++;
                    }
                }
            } else if (frow - irow > 0 && fcol - icol < 0) {
                for (int n{1}; n < distance; n++) {
                    if (temp[irow+n][icol-n] != nullptr) {
                        obstacle++;
                    }
                }
            } else if (frow - irow > 0 && fcol - icol > 0) {
                for (int n{1}; n < distance; n++) {
                    if (temp[irow+n][icol+n] != nullptr) {
                        obstacle++;
                    }
                }
            }
        }
    } else {
        return false;
    }
    if (obstacle == 0) {
        return true;
    } else {
        return false;
    }
}

bool rook::is_move_allowed(piece* temp[8][8], int irow, int icol, int frow, int fcol)
{
    int obstacle{0};
    if (frow == irow) {
        int distance = abs(fcol - icol);
        if (distance > 1) {
            if (fcol < icol) {
                for (int n{1}; n < distance; n++) {
                    if (temp[irow][icol-n] != nullptr) {
                        obstacle++;
                    }
                }
            } else {
                for (int n{1}; n < distance; n++) {
                    if (temp[irow][icol+n] != nullptr) {
                        obstacle++;
                    }
                }
            }
        }
    } else if (fcol == icol) {
        int distance = abs(frow - irow);
        if (distance > 1) {
            if (frow < irow) {
                for (int n{1}; n < distance; n++) {
                    if (temp[irow-n][icol] != nullptr) {
                        obstacle++;
                    }
                }
            } else {
                for (int n{1}; n < distance; n++) {
                    if (temp[irow+n][icol] != nullptr) {
                        obstacle++;
                    }
                }
            }
        }
    } else {
        return false;
    }
    if (obstacle == 0) {
        return true;
    } else {
        return false;
    }
}

bool knight::is_move_allowed(piece* temp[8][8], int irow, int icol, int frow, int fcol)
{
    if ((abs(fcol - icol) == 1 && abs(frow - irow) == 2) ||
        (abs(frow - irow) == 1 && abs(fcol - icol) == 2)) {
        return true;
    } else {
        return false;
    }
}

bool queen::is_move_allowed(piece* temp[8][8], int irow, int icol, int frow, int fcol)
{
    int obstacle{0};
    if (frow == irow) {
        int distance{abs(fcol - icol)};
        if (distance > 1) {
            if (fcol < icol) {
                for (int n{1}; n < distance; n++) {
                    if (temp[irow][icol-n] != nullptr) {
                        obstacle++;
                    }
                }
            } else {
                for (int n{1}; n < distance; n++) {
                    if (temp[irow][icol+n] != nullptr) {
                        obstacle++;
                    }
                }
            }
        }
    } else if (fcol == icol) {
        int distance{abs(frow - irow)};
        if (distance > 1) {
            if (frow < irow) {
                for (int n{1}; n < distance; n++) {
                    if (temp[irow-n][icol] != nullptr) {
                        obstacle++;
                    }
                }
            } else {
                for (int n{1}; n < distance; n++) {
                    if (temp[irow+n][icol] != nullptr) {
                        obstacle++;
                    }
                }
            }
        }
    } else if (abs(frow - irow) == abs(fcol - icol)) {
        int distance{abs(frow - irow)};
        if (distance > 1) {
            if (frow - irow < 0 && fcol - icol < 0) {
                for (int n{1}; n < distance; n++) {
                    if (temp[irow-n][icol-n] != nullptr) {
                        obstacle++;
                    }
                }
            } else if (frow - irow < 0 && fcol - icol > 0) {
                for (int n{1}; n < distance; n++) {
                    if (temp[irow-n][icol+n] != nullptr) {
                        obstacle++;
                    }
                }
            } else if (frow - irow > 0 && fcol - icol < 0) {
                for (int n{1}; n < distance; n++) {
                    if (temp[irow+n][icol-n] != nullptr) {
                        obstacle++;
                    }
                }
            } else if (frow - irow > 0 && fcol - icol > 0) {
                for (int n{1}; n < distance; n++) {
                    if (temp[irow+n][icol+n] != nullptr) {
                        obstacle++;
                    }
                }
            }
        }
    } else {
        return false;
    }
    if (obstacle == 0) {
        return true;
    } else {
        return false;
    }
}

bool king::is_move_allowed(piece* temp[8][8], int irow, int icol, int frow, int fcol)
{
    if ((abs(frow - irow) == 1 && abs(fcol - icol) == 1) || 
        (frow == irow && abs(fcol - icol) == 1) ||
        (fcol == icol && abs(frow - irow) == 1)) {
        return true;
    } else {
        return false;
    }
}