#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include <string>

class Piece
{
public:
    Piece();        //constructor
    int plr = 0;    //player
    int mvc = 0;    //moves counter
    //int x;
    std::string name;    //name
    bool dir = false;       //direction
    bool pwn = false;//for PAWN
    bool cas = false;
    bool lcas = false;
    bool rcas = false;
    struct pos{
        int x;
        int y;
    };
    pos def_pos = {0, 0};
    std::vector<pos> move;
    std::vector<pos> pawn;
    std::vector<pos> a_pos;
    Piece(std::string name, int plr, int y, int x, int mvc);
};

#endif // PIECE_H
