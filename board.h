#ifndef BOARD_H
#define BOARD_H

#include "piece.h"
#include "square.h"
#include <iostream>

class Board
{
public:
    Board();

    Square main_board[8][8];

    void AtoH();        //print a-h
    void DrawBoard();   //draw
    void CleanBoard();  //clear ??
    void MoveCmd(std::string cmd);
    void Move();
    bool ValidMove(Piece* sel_piece);
    void forprint(); //delete
    void CalstlingW();
    void CalstlingB();

    int Check();
    bool Mate(int plr);

    bool Rules(std::string cmd, int plr);
    struct pos {
        int x;
        int y;
    };
    void ClearPos(int plr);
private:

    void A_Pos(int plr);



    pos tar_coor = {0,0};
    pos sel_coor = {0,0};
};

#endif // BOARD_H
