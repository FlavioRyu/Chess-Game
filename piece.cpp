#include "piece.h"

using namespace chess;

char piece::get_id()
{
    if (this == nullptr) {
        return ' ';
    } else {
        return id;
    }
}

char piece::get_colour() {
    if (this == nullptr) {
        return ' ';
    } else {
        return colour;
    }
}

bool piece::has_moved()
{
    return status;
}

void piece::set_has_moved()
{
    status = true;
}