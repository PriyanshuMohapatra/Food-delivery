#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// Set up the game board as an array
vector<string> board = {"-", "-", "-", "-", "-", "-", "-", "-", "-"};

// Define a function to print the game board
void printBoard() {
    cout << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

// Function to handle a player's turn
void takeTurn(string player) {
    cout << player << "'s turn." << endl;
    cout << "Choose a position from 1-9: ";
    int position;
    cin >> position;
    position -= 1;  // Convert to 0-indexed
    while (position < 0 || position > 8 || board[position] != "-") {
        cout << "Invalid input or position already taken. Choose a different position: ";
        cin >> position;
        position -= 1;
    }
    board[position] = player;
    printBoard();
}

// Function to check if the game is won
bool checkWin() {
    // Define the 8 possible winning combinations (rows, columns, diagonals)
    int winCombos[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // columns
        {0, 4, 8}, {2, 4, 6}             // diagonals
    };

    // Loop through each winning combination
    for (int i = 0; i < 8; i++) {
        if (board[winCombos[i][0]] == board[winCombos[i][1]] &&
            board[winCombos[i][1]] == board[winCombos[i][2]] &&
            board[winCombos[i][0]] != "-") {
            return true;
        }
    }
    return false;
}

// Define a function to check if the game is over (win or tie)
string checkGameOver() {
    // Check if there is a winner
    if (checkWin()) {
        return "win";
    }
    // Check for a tie (if the board is full and no winner)
    else if (count(board.begin(), board.end(), "-") == 0) {
        return "tie";
    }
    // Otherwise, the game continues
    return "play";
}

// Main function to run the game
int main() {
    printBoard();
    string currentPlayer = "X";
    bool gameOver = false;

    // Loop until the game is over
    while (!gameOver) {
        takeTurn(currentPlayer);
        string gameResult = checkGameOver();
        
        // Check if the game is won or tied
        if (gameResult == "win") {
            cout << currentPlayer << " wins!" << endl;
            gameOver = true;
        } else if (gameResult == "tie") {
            cout << "It's a tie!" << endl;
            gameOver = true;
        } else {
            // Switch to the other player
            currentPlayer = currentPlayer == "X" ? "O" : "X";
        }
    }
    
    return 0;
}
