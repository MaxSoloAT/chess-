#include "square.h"

Square::Square()
{
    piece = nullptr;
}
Square::Square(Piece* piece){
    this->piece = piece;
}
