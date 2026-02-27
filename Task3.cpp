#include <iostream>
using namespace std;

char board[9] = {'1','2','3','4','5','6','7','8','9'};

void displayBoard() {
    cout << "\n";
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
    cout << "\n";
}

bool checkWin(char player) {
    int winPatterns[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8},
        {0,3,6}, {1,4,7}, {2,5,8}, 
        {0,4,8}, {2,4,6}           
    };

    for(int i = 0; i < 8; i++) {
        if(board[winPatterns[i][0]] == player &&
           board[winPatterns[i][1]] == player &&
           board[winPatterns[i][2]] == player)
           return true;
    }
    return false;
}

bool checkDraw() {
    for(int i = 0; i < 9; i++) {
        if(board[i] != 'X' && board[i] != 'O')
            return false;
    }
    return true;
}

void displayName() {
    cout << "======================\n";
    cout << "   Tic Tac Toe \n";
    cout << "======================\n\n";
}

int main() {
    char currentPlayer = 'X';
    char playAgain;

    displayName(); 

    do {
        for(int i = 0; i < 9; i++)
            board[i] = '1' + i;

        bool gameOver = false;

        while(!gameOver) {
            displayBoard();

            int choice;
            cout << (currentPlayer == 'X' ? "Yogesh" : "Shubham")
                 << ", enter position (1-9): ";
            cin >> choice;

            if(choice < 1 || choice > 9) {
                cout << "Invalid choice! Try again.\n";
                continue;
            }

            if(board[choice - 1] == 'X' || 
               board[choice - 1] == 'O') {
                cout << "Position already taken! Try again.\n";
                continue;
            }

            board[choice - 1] = currentPlayer;

            if(checkWin(currentPlayer)) {
                displayBoard();
                cout << "🎉 " << (currentPlayer == 'X' ? "Yogesh" : "Shubham") 
                     << " Wins!\n";
                gameOver = true;
            }
            else if(checkDraw()) {
                displayBoard();
                cout << "It's a Draw!\n";
                gameOver = true;
            }
            else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        cout << "Play again? (y/n): ";
        cin >> playAgain;

    } while(playAgain == 'y' || playAgain == 'Y');

    cout << "Thank you for playing!\n";
    displayName();
    return 0;
}