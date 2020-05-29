#include <iostream>
#include <fstream>
#include <sstream>
#include "board.h"


void playGame(std::vector <Piece>& pieces, int curr_plr);

bool InvalidFormat(std::string move);

int main()
{
    while(true){
        std::cout << "Do you want to load the game?" << std::endl;
        std::cout << "'y' to load, 'n' to start new game." << std::endl;
        char in = getchar();
        if(in == 'n' || in =='N'){
            std::vector <Piece> default_pos{
            Piece("WRk", 1, 0, 0,0),
            Piece("WKn", 1, 0, 1,0),
            Piece("WBp", 1, 0, 2,0),
            Piece("WQn", 1, 0, 3,0),
            Piece("WKg", 1, 0, 4,0),
            Piece("WBp", 1, 0, 5,0),
            Piece("WKn", 1, 0, 6,0),
            Piece("WRk", 1, 0, 7,0),
            Piece("WPn", 1, 1, 0,0),
            Piece("WPn", 1, 1, 1,0),
            Piece("WPn", 1, 1, 2,0),
            Piece("WPn", 1, 1, 3,0),
            Piece("WPn", 1, 1, 4,0),
            Piece("WPn", 1, 1, 5,0),
            Piece("WPn", 1, 1, 6,0),
            Piece("WPn", 1, 1, 7,0),
            Piece("BRk", 2, 7, 0,0),
            Piece("BKn", 2, 7, 1,0),
            Piece("BBp", 2, 7, 2,0),
            Piece("BQn", 2, 7, 3,0),
            Piece("BKg", 2, 7, 4,0),
            Piece("BBp", 2, 7, 5,0),
            Piece("BKn", 2, 7, 6,0),
            Piece("BRk", 2, 7, 7,0),
            Piece("BPn", 2, 6, 0,0),
            Piece("BPn", 2, 6, 1,0),
            Piece("BPn", 2, 6, 2,0),
            Piece("BPn", 2, 6, 3,0),
            Piece("BPn", 2, 6, 4,0),
            Piece("BPn", 2, 6, 5,0),
            Piece("BPn", 2, 6, 6,0),
            Piece("BPn", 2, 6, 7,0)};
            int curr_plr = 2;
            playGame(default_pos, curr_plr);
        }
        else{
            if(in == 'y' || in == 'Y'){
                std::cout << "Enter full name of file." << std::endl;
                std::string name_file;
                std::cin>>name_file;
                std::ifstream last_load(name_file);
                int curr_plr;
                std::vector <Piece> load_data;
                if (last_load.is_open()){
                    std::string line;
                    std::string name_load;
                    int plr;
                    int x,y;
                    int mvc;
                    std::stringstream data;
                    while(getline(last_load,line)){
                        if(line.length() == 1){
                            data<<line[0];
                            data>>curr_plr;
                            data.clear();
                            }
                        else{
                            name_load.push_back(line[0]);
                            name_load.push_back(line[1]);
                            name_load.push_back(line[2]);
                            data<<line[3];
                            data>>plr;
                            data.clear();
                            data<<line[4];
                            data>>y;
                            data.clear();
                            data<<line[5];
                            data>>x;
                            data.clear();
                            data<<line[6];
                            data>>mvc;
                            data.clear();
                            Piece piece = Piece(name_load,plr,y,x,mvc);
                            load_data.push_back(piece);
                            name_load.clear();
                            data.clear();
                        }
                    }
                    last_load.close();
                    playGame(load_data,curr_plr);
                }
                else{
                    std::cout<<"No such file."<<std::endl;
                    getchar();
                }
            }
        }
    }
}

void playGame(std::vector <Piece>& pieces, int curr_plr) {
    Board board;
    int length = pieces.size();
    for(int i = 0; i < length; i++ ){
        board.main_board[pieces[i].def_pos.y][pieces[i].def_pos.x] = &pieces[i];
    }

    std::string move;
    while(true){
        std::string plr = "White";
        if(curr_plr == 1) {
            plr = "Black";
        }
        else{
            plr = "White";
        }
            system("cls");
            board.DrawBoard();
            std::cout << "You can use main cmd or move chess e.g.(move a2a3)" << std::endl;
            std::cout <<"Player "<<plr<<" your turn!" << std::endl;
            std::cout << "cmd:";
            std::cin>>move;
            if(move == "Exit" || move == "exit"){
                std::cout << "\t\t\tpress any key..." << std::endl;
                break;
            }
            else{
                if(move == "restart" || move == "Restart"){
                    board.CleanBoard();
                    std::vector <Piece> default_pos{
                    Piece("WRk", 1, 0, 0,0),
                    Piece("WKn", 1, 0, 1,0),
                    Piece("WBp", 1, 0, 2,0),
                    Piece("WQn", 1, 0, 3,0),
                    Piece("WKg", 1, 0, 4,0),
                    Piece("WBp", 1, 0, 5,0),
                    Piece("WKn", 1, 0, 6,0),
                    Piece("WRk", 1, 0, 7,0),
                    Piece("WPn", 1, 1, 0,0),
                    Piece("WPn", 1, 1, 1,0),
                    Piece("WPn", 1, 1, 2,0),
                    Piece("WPn", 1, 1, 3,0),
                    Piece("WPn", 1, 1, 4,0),
                    Piece("WPn", 1, 1, 5,0),
                    Piece("WPn", 1, 1, 6,0),
                    Piece("WPn", 1, 1, 7,0),
                    Piece("BRk", 2, 7, 0,0),
                    Piece("BKn", 2, 7, 1,0),
                    Piece("BBp", 2, 7, 2,0),
                    Piece("BQn", 2, 7, 3,0),
                    Piece("BKg", 2, 7, 4,0),
                    Piece("BBp", 2, 7, 5,0),
                    Piece("BKn", 2, 7, 6,0),
                    Piece("BRk", 2, 7, 7,0),
                    Piece("BPn", 2, 6, 0,0),
                    Piece("BPn", 2, 6, 1,0),
                    Piece("BPn", 2, 6, 2,0),
                    Piece("BPn", 2, 6, 3,0),
                    Piece("BPn", 2, 6, 4,0),
                    Piece("BPn", 2, 6, 5,0),
                    Piece("BPn", 2, 6, 6,0),
                    Piece("BPn", 2, 6, 7,0)};
                    for (int i = 0; i < 32; i++) {
                        pieces[i] = default_pos[i];
                    }
                    int length = pieces.size();
                    for (int i = 0; i < length; i++ ) {
                        board.main_board[pieces[i].def_pos.y][pieces[i].def_pos.x] = &pieces[i];
                    }
                    curr_plr = 2;
                    }
                    else{
                        if(move == "Save" || move == "save"){
                            std::cout << "Enter the name of file." << std::endl;
                            std::string name_file;
                            std::cin >> name_file;
                            std::cout << std::endl;
                            std::ofstream last_save(name_file);
                            if (last_save.is_open()) {
                                for (int y = 0; y <= 7; y++) {
                                    for (int x = 0; x <= 7; x++) {
                                        if (board.main_board[y][x].piece != nullptr) {
                                            last_save<<board.main_board[y][x].piece->name
                                                     <<board.main_board[y][x].piece->plr
                                                     <<y
                                                     <<x
                                                     <<board.main_board[y][x].piece->mvc
                                                     <<std::endl;
                                        }
                                    }
                                }
                            last_save << curr_plr;
                            last_save.close();
                            }
                            std::cout<<"Game was saved."<<std::endl;
                        }
                        else{
                            if(move == "move" || move == "Move"){
                                if(curr_plr == 1){
                                    curr_plr = 2;
                                }
                                else{
                                    curr_plr = 1;
                                }

                                std::cout << "Move: ";
                                std::cin >> move;
                                std::cout << std::endl;
                                while (InvalidFormat(move) == false) {
                                std::cout << "Invalid format. Please re-enter your move" << std::endl;
                                std::cin>>move;
                                }
                                //board.MoveCmd(move);
                                while(board.Rules(move, curr_plr) == false) {
                                    std::cout << "Please re-enter your move: ";
                                    std::cin >> move;
                                while (InvalidFormat(move) == false) {
                                std::cout << "Invalid format. Please re-enter your move" << std::endl;
                                std::cin>>move;
                                }
                                }

                                int check = board.Check();
                                if(check == 1 && check == curr_plr) {
                                    std::cout << "Player " << plr << " lost!";
                                    break;
                                }
                                if(check == 2 && check == curr_plr) {
                                    std::cout << "Player " << plr << " lost!";
                                    break;
                                }
                                if (check == 1 ) {
                                    getchar();
                                    system("cls");
                                    board.DrawBoard();
                                    std::cout << "White King is in check!" << std::endl;
                                    bool checkMate = board.Mate(check);
                                    if (checkMate) {
                                        std::cout << "CHECK MATE!" << std::endl;
                                        std::cout << "Player " << plr << " won!";
                                        system("pause");
                                        getchar();
                                        break;
                                    }

                                }
                                if(check == 2){
                                    getchar();
                                    system("cls");
                                    board.DrawBoard();
                                    std::cout << "Black King is in check!" << std::endl;
                                    bool checkMate = board.Mate(check);
                                    if(checkMate) {
                                        std::cout << "CHECK MATE!" << std::endl;
                                        std::cout << "Player " << plr << " won!";
                                        system("pause");
                                        getchar();
                                        break;
                                    }
                                }


                            }
                            else{
                                std::cout << "Unknown command!" << std::endl;
                            }
                }
            }
        }
    }
    std::cout << std::endl;
}

bool InvalidFormat(std::string move){
    if (move.length() < 4 || move.length() == 0 ){
        return false;
    }
    else if(move[0] != 'a' && move[0] != 'b' && move[0] != 'c' && move[0] != 'd' &&
            move[0] != 'e' && move[0] != 'f' && move[0] != 'g' && move[0] != 'h'){
        return false;
    }
    else if(move[2] != 'a' && move[2] != 'b' && move[2] != 'c' && move[2] != 'd' &&
            move[2] != 'e' && move[2] != 'f' && move[2] != 'g' && move[2] != 'h'){
        return false;
    }
    else if(move[1] != '1' && move[1] != '2' && move[1] != '3' && move[1] != '4' && move[1] != '5'
            && move[1] != '6' && move[1] != '7' && move[1] != '8'){
        return false;
    }
    else if(move[3] != '1' && move[3] != '2' && move[3] != '3' && move[3] != '4' && move[3] != '5'
            && move[3] != '6' && move[3] != '7' && move[3] != '8'){
        return false;
    }
    else return true;


}




