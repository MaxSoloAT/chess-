#ifndef SQUARE_H
#define SQUARE_H

#include "piece.h"

class Square
{
public:
    Square();
    Piece* piece;
    Square(Piece* piece);
};

#endif // SQUARE_H
