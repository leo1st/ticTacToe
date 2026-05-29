#include <iostream>
char tictactoe[3][3] = {
    {'*','*','*'},
    {'*','*','*'},
    {'*','*','*'}
};

bool checkForWin() {
    // Check für Sieg Waagerecht
    for (int row = 0; row < 3; row++) {
        if (tictactoe[row][0] == tictactoe[row][1] && tictactoe[row][0] == tictactoe[row][2] && tictactoe[row][0] != '*') {
            return true;
        }
    }
    // Check für Sieg Senkrecht
    for (int row = 0; row < 3; row++) {
        if (tictactoe[0][row] == tictactoe[1][row] && tictactoe[0][row] == tictactoe[2][row] && tictactoe[0][row] != '*') {
            return true;
        }
    }
    // Check für Sieg Diagonal
    if (tictactoe[0][0] == tictactoe[1][1] && tictactoe[0][0] == tictactoe[2][2] && tictactoe[0][0] != '*') {
        return true;
    }
    if (tictactoe[0][2] == tictactoe[1][1] && tictactoe[0][2] == tictactoe[2][0] && tictactoe[0][2] != '*') {
        return true;
    }
    return false;


}



void coutTicTacToe() {
    for (int row = 0; row < 3; row++) {
        std::cout << "|";
        for (int chara = 0; chara < 3; chara++) {
            std::cout << tictactoe[row][chara];
            std::cout << "|";
        }
        std::cout << '\n';
    }

}

void playerMove(char charSymbol) {
    while (true) {
        int row;
        int charac;
        std::cout << "Welche Reihe (" << charSymbol <<"): ";
        std::cin >> row;
        row--;
        std::cout << "Welcher Platz (" << charSymbol <<"): ";
        std::cin >> charac;
        charac--;
        if (row > 2 || charac > 2 || charac < 0 || row < 0) {
            std::cout << "Zug ist ausserhalb von Spielfeld!\n";
            continue;
        }
        if (tictactoe[row][charac] == '*') {
            tictactoe[row][charac] = charSymbol;
            break;
        }
        else {
            std::cout << "Da ist schon ein Zeichen!\n";
        }
    }
}



int main() {
    int row;
    int charac;

    while (true) {
        coutTicTacToe();
        playerMove('X');
        if (checkForWin()) {
            std::cout << "X hat Gewonnen";
            break;
        }
        coutTicTacToe();
        playerMove('O');
        if (checkForWin()) {
            std::cout << "O hat Gewonnen!";
            break;
        }
    }
    return 0;
}