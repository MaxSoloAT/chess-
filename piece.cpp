#include "piece.h"

Piece::Piece()
{
}
Piece::Piece(std::string name, int plr, int y, int x, int mvc){
    this->name = name;
    this->plr = plr;
    this->mvc = mvc;
    this->def_pos.x = x;
    this->def_pos.y = y;

    if (name == "BKg" || name == "WKg") {
            move.push_back({ 1, 0 });
            move.push_back({ 1, 1 });
            move.push_back({ 0, 1 });
            move.push_back({ -1, 1 });
            move.push_back({ -1, 0 });
            move.push_back({ -1, -1 });
            move.push_back({ 0, -1 });
            move.push_back({ 1, -1 });
            dir = false;
            pwn = false;
            cas = true;
    }
    else{
        if (name == "BQn" || name == "WQn") {
            move.push_back({ 1, 0 });
            move.push_back({ 1, 1 });
            move.push_back({ 0, 1 });
            move.push_back({ -1, 1 });
            move.push_back({ -1, 0 });
            move.push_back({ -1, -1 });
            move.push_back({ 0, -1 });
            move.push_back({ 1, -1 });
            dir = true;
            pwn = false;
        }
        else {
            if (name == "BKn" || name == "WKn") {
                move.push_back({ 2, 1 });
                move.push_back({ 2, -1 });
                move.push_back({ -2, 1 });
                move.push_back({ -2, -1 });
                move.push_back({ 1, 2 });
                move.push_back({ 1, -2 });
                move.push_back({ -1, -2 });
                move.push_back({ -1, 2 });
                dir = false;
                pwn = false;
            }
            else{
                if (name == "BBp" || name == "WBp") {
                    move.push_back({ 1, 1 });
                    move.push_back({ 1, -1 });
                    move.push_back({ -1, 1 });
                    move.push_back({ -1, -1 });
                    dir = true;
                    pwn = false;
                }
                else{
                    if (name == "BRk" || name == "WRk") {
                        move.push_back({ 0, 1 });
                        move.push_back({ 0, -1 });
                        move.push_back({ 1, 0 });
                        move.push_back({ -1, 0 });
                        dir = true;
                        pwn= false;
                    }
                    else{
                        if (name == "BPn") {
                            move.push_back({ 0, -1 });
                            pawn.push_back({ 1, -1 });
                            pawn.push_back({ -1, -1 });
                            pwn = true;
                            dir = false;
                        }
                        else{
                            if (name == "WPn") {
                                move.push_back({ 0, 1 });
                                pawn.push_back({ -1, 1 });
                                pawn.push_back({ 1, 1 });
                                pwn = true;
                                dir = false;
                            }
                        }
                    }
                }
            }
        }
    }
}
