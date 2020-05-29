#include "board.h"
#include <string>
#include <sstream>
Board::Board()
{
}
void Board::AtoH(){
    std::cout<<' ';
    for(int l = 97; l <= 104; l++){
        std::cout<<"  "<<char(l)<<' ';
    }
    std::cout<<std::endl;
}
void Board::DrawBoard(){
    std::cout << "\t\tWhite";
    std::cout << std::endl;
    AtoH();
    std::cout<<" ";
    std::cout<<char(201)<<char(205)<<char(205)<<char(205)<<char(209)
                   <<char(205)<<char(205)<<char(205)<<char(209)
                   <<char(205)<<char(205)<<char(205)<<char(209)
                   <<char(205)<<char(205)<<char(205)<<char(209)
                   <<char(205)<<char(205)<<char(205)<<char(209)
                   <<char(205)<<char(205)<<char(205)<<char(209)
                   <<char(205)<<char(205)<<char(205)<<char(209)
                   <<char(205)<<char(205)<<char(205)<<char(187)<<"\tMain command restart, exit, save, load, move."<<std::endl;
    for (int y = 0; y <= 7; y++){
        std::cout<<y+1;
        std::cout<<char(186);
        for(int x = 0; x <= 7; x++){
            if (main_board[y][x].piece != nullptr) {
                std::cout<<main_board[y][x].piece->name;
            }
            else{
                std::cout<<"   ";
            }
            if(x != 7){
                std::cout<<char(179);
            }
        }
        std::cout<<char(186)<<y+1<<std::endl;
        if(y != 7){
             std::cout<<" ";
             std::cout<<char(199)<<char(196)<<char(196)<<char(196)<<char(197)
                                 <<char(196)<<char(196)<<char(196)<<char(197)
                                 <<char(196)<<char(196)<<char(196)<<char(197)
                                 <<char(196)<<char(196)<<char(196)<<char(197)
                                 <<char(196)<<char(196)<<char(196)<<char(197)
                                 <<char(196)<<char(196)<<char(196)<<char(197)
                                 <<char(196)<<char(196)<<char(196)<<char(197)
                                 <<char(196)<<char(196)<<char(196)<<char(182)<<std::endl;
        }
    }
    std::cout<<" ";
    std::cout<<char(200)<<char(205)<<char(205)<<char(205)<<char(207)
                   <<char(205)<<char(205)<<char(205)<<char(207)
                   <<char(205)<<char(205)<<char(205)<<char(207)
                   <<char(205)<<char(205)<<char(205)<<char(207)
                   <<char(205)<<char(205)<<char(205)<<char(207)
                   <<char(205)<<char(205)<<char(205)<<char(207)
                   <<char(205)<<char(205)<<char(205)<<char(207)
                   <<char(205)<<char(205)<<char(205)<<char(188)<<std::endl;
    AtoH();
    std::cout << "\t\tBlack";
    std::cout << std::endl;

}
void Board::CleanBoard(){
    for (int y = 0; y <= 7; y++) {
        for (int x = 0; x <= 7; x++) {
            Piece* currentPiece = main_board[y][x].piece;
            if (currentPiece != nullptr) {
                main_board[y][x] = nullptr;
            }
        }
    }
}

void Board::MoveCmd(std::string cmd){//a2a3

    std::stringstream stream;

    int selectedY;
    int selectedX;

    stream<<cmd[1];
    stream>>selectedY;
    if (cmd[0] == 'a')
            selectedX = 0;
        else if (cmd[0] == 'b')
            selectedX = 1;
        else if (cmd[0] == 'c')
            selectedX = 2;
        else if (cmd[0] == 'd')
            selectedX = 3;
        else if (cmd[0] == 'e')
            selectedX = 4;
        else if (cmd[0] == 'f')
            selectedX = 5;
        else if (cmd[0] == 'g')
            selectedX = 6;
        else
            selectedX = 7;

        stream.clear();
        sel_coor.x = selectedX;
        sel_coor.y = (selectedY-1);

        int targetY;
        int targetX;

        stream << cmd[3];
        stream >> targetY;

        if (cmd[2] == 'a')
            targetX = 0;
        else if (cmd[2] == 'b')
            targetX = 1;
        else if (cmd[2] == 'c')
            targetX = 2;
        else if (cmd[2] == 'd')
            targetX = 3;
        else if (cmd[2] == 'e')
            targetX = 4;
        else if (cmd[2] == 'f')
            targetX = 5;
        else if (cmd[2] == 'g')
            targetX = 6;
        else
            targetX = 7;
        tar_coor.x = targetX;
        tar_coor.y = (targetY-1);



}

void Board::Move(){
    main_board[tar_coor.y][tar_coor.x] = main_board[sel_coor.y][sel_coor.x].piece;
    main_board[sel_coor.y][sel_coor.x] = nullptr;


}
bool Board::ValidMove(Piece* sel_piece){
    for (unsigned int i = 0; i < sel_piece->a_pos.size(); i++) {
        pos available = { sel_piece->a_pos[i].x, sel_piece->a_pos[i].y};

        if (tar_coor.x == available.x && tar_coor.y == available.y) {
            return true;
        }
    }
    std::cout << sel_piece->name << " can not move this way!" << std::endl;
    return false;
}
bool Board::Rules(std::string cmd, int plr){

    bool result;

        MoveCmd(cmd);
        Piece* sel_Piece = main_board[sel_coor.y][sel_coor.x].piece;
        Piece* tar_Position = main_board[tar_coor.y][tar_coor.x].piece;

        if (sel_Piece == nullptr) {
            std::cout << "There's no piece at the specified location." << std::endl;
            return false;
        }
        else if (sel_Piece->plr != plr) {
            std::cout << "This is not your piece" << std::endl;
            return false;
        }
        if (tar_Position != nullptr && tar_Position->plr == plr && sel_Piece->plr == plr) {
            std::cout << "You already have a piece there." << std::endl;
            return false;
        }

        A_Pos(1);
        A_Pos(2);
        result = ValidMove(sel_Piece);
        sel_Piece->mvc += 1;


        if (result) {
            Move();
        }

        ClearPos(1);
        ClearPos(2);

        A_Pos(1);
        A_Pos(2);

        return result;


}


void Board::ClearPos(int plr){
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (main_board[y][x].piece != nullptr && main_board[y][x].piece->plr == plr) {
                main_board[y][x].piece->a_pos.clear();
            }
        }
    }
};



void Board::A_Pos(int targetPlayer) {
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            Piece* currentPiece = main_board[y][x].piece;
            // looping trhough all pieces
            if (currentPiece != nullptr && currentPiece->plr == targetPlayer) {

                // looping trhough all possible movements of a piece
                int length = currentPiece->move.size();
                for (int i = 0; i < length; i++) {
                    if (currentPiece->dir && !currentPiece->pwn) {

                        // find all available positions in a direction
                        pos movement = { currentPiece->move[i].x, currentPiece->move[i].y };
                        pos currentPos = { x, y };


                        // up
                        if (movement.y < 0 && movement.x == 0) {
                            // loop for step movement
                            int iy = (currentPos.y - 1);
                            int ix = currentPos.x;
                            while (iy >= 0)
                            {
                                // check if there is no piece on the way
                                if (main_board[iy][ix].piece == nullptr) {
                                    currentPiece->a_pos.push_back({ ix, iy });
                                }
                                else if (main_board[iy][ix].piece->plr != currentPiece->plr) {
                                    currentPiece->a_pos.push_back({ ix, iy });
                                    break;
                                }
                                else {
                                    break;
                                }
                                iy--;
                            }
                        }else if (movement.y > 0 && movement.x == 0) {
                        // down
                            // loop for step movement
                            int iy = (currentPos.y + 1);
                            int ix = currentPos.x;
                            while (iy < 8)
                            {
                                // check if there is no piece on the way
                                if (main_board[iy][ix].piece == nullptr) {
                                    currentPiece->a_pos.push_back({ ix, iy });
                                }
                                else if (main_board[iy][ix].piece->plr != currentPiece->plr) {
                                    currentPiece->a_pos.push_back({ ix, iy });
                                    break;
                                }
                                else {
                                    break;
                                }
                                iy++;
                            }
                        }else if (movement.y == 0 && movement.x > 0) {
                        //right
                            // loop for step movement
                            int iy = currentPos.y;
                            int ix = (currentPos.x + 1);
                            while (ix < 8)
                            {
                                // check if there is no piece on the way
                                if (main_board[iy][ix].piece == nullptr) {
                                    currentPiece->a_pos.push_back({ ix, iy });
                                }
                                else if (main_board[iy][ix].piece->plr != currentPiece->plr) {
                                    currentPiece->a_pos.push_back({ ix, iy });
                                    break;
                                }
                                else {
                                    break;
                                }
                                ix++;
                            }
                        } else if (movement.y == 0 && movement.x < 0) {
                        //left
                            // loop for step movement
                            int iy = currentPos.y;
                            int ix = (currentPos.x - 1);
                            while (ix >= 0)
                            {
                                // check if there is no piece on the way
                                if (main_board[iy][ix].piece == nullptr) {
                                    currentPiece->a_pos.push_back({ ix, iy });
                                }
                                else if (main_board[iy][ix].piece->plr != currentPiece->plr) {
                                    currentPiece->a_pos.push_back({ ix, iy });
                                    break;
                                }
                                else {
                                    break;
                                }
                                ix--;
                            }
                        } else if (movement.y < 0 && movement.x > 0) {
                        // up & right
                            // loop for step movement
                            int iy = (currentPos.y - 1);
                            int ix = (currentPos.x + 1);
                            while (iy >= 0 && iy < 8 && ix < 8)
                            {
                                // check if there is no piece on the way
                                if (main_board[iy][ix].piece == nullptr) {
                                    currentPiece->a_pos.push_back({ ix, iy });
                                }
                                else if (main_board[iy][ix].piece->plr != currentPiece->plr) {
                                    currentPiece->a_pos.push_back({ ix, iy });
                                    break;
                                }
                                else {
                                    break;
                                }
                                iy--;
                                ix++;
                            }
                        } else if (movement.y < 0 && movement.x < 0) {
                        // up & left
                            // loop for step movement
                            int iy = (currentPos.y - 1);
                            int ix = (currentPos.x - 1);
                            while (iy >= 0 && iy < 8 && ix >= 0)
                            {
                                // check if there is no piece on the way
                                if (main_board[iy][ix].piece == nullptr) {
                                    currentPiece->a_pos.push_back({ ix, iy });
                                }
                                else if (main_board[iy][ix].piece->plr != currentPiece->plr) {
                                    currentPiece->a_pos.push_back({ ix, iy });
                                    break;
                                }
                                else {
                                    break;
                                }
                                iy--;
                                ix--;
                            }
                        } else if (movement.y > 0 && movement.x > 0) {
                        // down & right
                            // loop for step movement
                            int iy = (currentPos.y + 1);
                            int ix = (currentPos.x + 1);
                            while (iy < 8 && ix < 8)
                            {
                                // check if there is no piece on the way
                                if (main_board[iy][ix].piece == nullptr) {
                                    currentPiece->a_pos.push_back({ ix, iy });
                                }
                                else if (main_board[iy][ix].piece->plr != currentPiece->plr) {
                                    currentPiece->a_pos.push_back({ ix, iy });
                                    break;
                                }
                                else {
                                    break;
                                }
                                iy++;
                                ix++;
                            }
                        } else if (movement.y > 0 && movement.x < 0){
                        // down & left
                            // loop for step movement
                            int iy = (currentPos.y + 1);
                            int ix = (currentPos.x - 1);
                            while (iy < 8 && ix >= 0)
                            {
                                // check if there is no piece on the way
                                if (main_board[iy][ix].piece == nullptr) {
                                    currentPiece->a_pos.push_back({ ix, iy });
                                }
                                else if (main_board[iy][ix].piece->plr != currentPiece->plr) {
                                    currentPiece->a_pos.push_back({ ix, iy });
                                    break;
                                }
                                else {
                                    break;
                                }
                                iy++;
                                ix--;
                            }
                        }
                    }

                    else if (!currentPiece->dir && !currentPiece->pwn) {

                        pos movement = { currentPiece->move[i].x, currentPiece->move[i].y };
                        pos currentPos = { x, y };
                        int ix = (currentPos.x + movement.x);
                        int iy = (currentPos.y + movement.y);

                        if (ix >= 0 && iy >= 0 && ix <= 7 && iy <= 7) {

                            if (main_board[iy][ix].piece == nullptr || main_board[iy][ix].piece->plr != currentPiece->plr) {
                                currentPiece->a_pos.push_back({ ix, iy });
                            }
                        }
                    }
                    else if (currentPiece->pwn && currentPiece->plr == 1) {
                    // white pawn logic
                    Piece* pawn = main_board[y][x].piece;
                        pos movement = { pawn->move[i].x, pawn->move[i].y };
                        pos currentPos = { x, y };

                        // down
                        if (movement.y > 0 && movement.x == 0) {
                            // loop for step movement
                            int iy = (currentPos.y + movement.y);
                            int ix = currentPos.x;
                            if (main_board[iy][ix].piece == nullptr) {
                                pawn->a_pos.push_back({ ix, iy });
                                if (pawn->mvc == 0) {
                                    iy = iy + 1;
                                    if (main_board[iy][ix].piece == nullptr) {
                                        pawn->a_pos.push_back({ ix, iy });
                                    }
                                }
                            }
                        }
                        // down & left
                        // looping trhough pawntakes
                        int lengthpw = currentPiece->pawn.size();
                        for (int i = 0; i < lengthpw; i++) {
                            if (currentPiece->pawn[i].y > 0 && currentPiece->pawn[i].x < 0) {
                                int iy = (currentPos.y + 1);
                                int ix = (currentPos.x - 1);
                                if (iy < 8 && iy >= 0 && ix < 8 && ix >= 0) {

                                    if (main_board[iy][ix].piece != nullptr) {
                                        if (main_board[iy][ix].piece->plr != currentPiece->plr) {
                                            currentPiece->a_pos.push_back({ ix, iy });
                                        }
                                    }
                                }
                            }
                        }
                        // down & right
                        for (int i = 0; i < lengthpw; i++) {
                            if (currentPiece->pawn[i].y > 0 && currentPiece->pawn[i].x > 0) {
                                int iy = (currentPos.y + 1);
                                int ix = (currentPos.x + 1);
                                if (iy < 8 && iy >= 0 && ix < 8 && ix >= 0) {
                                    if (main_board[iy][ix].piece != nullptr) {
                                        if (main_board[iy][ix].piece->plr != currentPiece->plr) {
                                            currentPiece->a_pos.push_back({ ix, iy });
                                        }
                                    }
                                }
                            }
                        }

                    }
                    else if (currentPiece->pwn && currentPiece->plr == 2) {
                    // black pawn logic
                        pos movement = { currentPiece->move[i].x, currentPiece->move[i].y };
                        pos currentPos = { x, y };


                        // up
                        if (movement.y < 0 && movement.x == 0) {
                            // loop for step movement
                            int iy = (currentPos.y - 1);
                            int ix = currentPos.x;
                            if (iy < 8 && iy >= 0 && ix < 8 && ix >= 0) {
                                if (main_board[iy][ix].piece == nullptr) {
                                    currentPiece->a_pos.push_back({ ix, iy });
                                    if (currentPiece->mvc == 0 && iy < 8 && iy >= 0 && ix < 8 && ix >= 0) {
                                        iy = iy - 1;
                                        if (main_board[iy][ix].piece == nullptr) {
                                            currentPiece->a_pos.push_back({ ix, iy });
                                        }
                                    }
                                }
                            }
                        }
                       // std::cout<<x<<y<<std::endl;

                        // up & left
                        // looping trhough pawntakes
                        int lengthpw = currentPiece->pawn.size();
                        for (int i = 0; i < lengthpw; i++) {
                            if (currentPiece->pawn[i].y < 0 && currentPiece->pawn[i].x < 0) {
                                int iy = (currentPos.y - 1);
                                int ix = (currentPos.x - 1);
                                if (iy < 8 && iy >= 0 && ix < 8 && ix >= 0) {
                                    if (main_board[iy][ix].piece != nullptr) {
                                        if (main_board[iy][ix].piece->plr != currentPiece->plr) {
                                            currentPiece->a_pos.push_back({ ix, iy });
                                        }
                                    }
                                }
                            }
                        }
                        // up & right
                        for (int i = 0; i < lengthpw; i++) {
                            if (currentPiece->pawn[i].y < 0 && currentPiece->pawn[i].x > 0) {
                                int iy = (currentPos.y - 1);
                                int ix = (currentPos.x + 1);
                                if (iy < 8 && iy >= 0 && ix < 8 && ix >= 0) {
                                    if (main_board[iy][ix].piece != nullptr) {
                                        if (main_board[iy][ix].piece->plr != currentPiece->plr) {
                                            currentPiece->a_pos.push_back({ ix, iy });
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}


int Board::Check(){
    for (int y = 0; y <= 7; y++) {
        for (int x = 0; x <= 7; x++) {
            Piece* current = main_board[y][x].piece;
            if (current != nullptr) {
                if (current->name == "BKg") {
                    pos bkg = { x, y };
                    for (int iy = 0; iy <= 7; iy++) {
                        for (int ix = 0; ix <= 7; ix++) {
                            Piece* new_current = main_board[iy][ix].piece;
                            if (new_current != nullptr && new_current->plr != 2) {
                                int length = new_current->a_pos.size();
                                for (int i = 0; i < length; i++) {
                                    if (new_current->a_pos[i].x == bkg.x && new_current->a_pos[i].y == bkg.y) {
                                        return 2;
                                    }
                                }
                            }
                        }
                    }
                }
                if (current->name == "WKg") {
                    pos wkg = { x, y };
                    for (int iy = 0; iy < 8; iy++) {
                        for (int ix = 0; ix < 8; ix++) {
                            Piece* new_current = main_board[iy][ix].piece;
                            if (new_current != nullptr && new_current->plr != 1) {
                            int length = new_current->a_pos.size();
                                for (int i = 0; i < length; i++) {
                                    if (new_current->a_pos[i].x == wkg.x && new_current->a_pos[i].y == wkg.y) {
                                        return 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
bool Board::Mate(int plr){
    for (int y = 0; y <=7; y++) {
        for (int x = 0; x <=7; x++) {
            Piece* current = main_board[y][x].piece;
            if (current != nullptr) {
                int length = current->a_pos.size();
                for (int i = 0; i < length; i++) {
                    if (current->plr == plr) {
                        Piece* temp = main_board[current->a_pos[i].y][current->a_pos[i].x].piece;
                        main_board[current->a_pos[i].y][current->a_pos[i].x] = current;
                        main_board[y][x] = nullptr;
                        if (plr == 1) {
                            ClearPos(2);
                            A_Pos(2);
                            }
                            if (plr == 2) {
                                ClearPos(1);
                                A_Pos(1);
                            }

                            int check = Check();
                            if (check == 0) {
                                main_board[current->a_pos[i].y][current->a_pos[i].x] = temp;
                               main_board[y][x] = current;
                                if (plr == 1) {
                                    ClearPos(2);
                                    A_Pos(2);
                                }
                                if (plr == 2) {
                                    ClearPos(1);
                                    A_Pos(1);
                                }

                                return false;
                            }
                            main_board[current->a_pos[i].y][current->a_pos[i].x] = temp;
                            main_board[y][x] = current;
                            if (plr == 1) {
                                ClearPos(2);
                                A_Pos(2);
                            }
                            if (plr == 2) {
                                ClearPos(1);
                                A_Pos(1);
                            }
                        }
                    }
                }
            }
        }
    return true;


}


