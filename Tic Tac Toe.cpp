#include <iostream>
#include <conio.h>     //→ getch() allows you to get a key instantly (WASD, ENTER) mane key press korar loga log input loi ami ENTER prss kori confirm koribo nalage 
#include <cstdlib>     //→ system("cls") clears the console screen [for redrawing board cleanly]
using namespace std;


char board[3][3];         // 3x3 Tic Tac Toe board
int cursorX, cursorY;     // Cursor position on the board
char currentPlayer;       // Current player ('X' or 'O')



void resetGame()            // This function clears everything for a new round , Resets board, cursor, and sets turn to X
{
    currentPlayer = 'X';       //Start with player X
    cursorX = 0;               // Reset cursor position to top-left corner with coordinates 0,0.
    cursorY = 0;
    for (int i = 0; i < 3; i++)           // this for loop is cleaning the board with empty spaces         
        for (int j = 0; j < 3; j++)    
            board[i][j] = ' ';        
}



void drawBoard() 
{
    system("cls");            //Clears the screen  

    cout << "Use WASD to move | Press ENTER/SPACE to mark\n";
    cout << "Player: " << currentPlayer << "\n\n";                     //shows current player's turn and control instructions

    for (int i = 0; i < 3; i++) 
    {    
        cout << " ";      // For better alignment of the board
        for (int j = 0; j < 3; j++) 
        {
            if (cursorY == i && cursorX == j)
                cout << "[" << (board[i][j] == ' ' ? ' ' : board[i][j]) << "]";     //the '?' is doing a check to see if the board is empty or not, if it is empty then it will show a space, otherwise it will show the current player's mark
            else
                cout << " " << (board[i][j] == ' ' ? ' ' : board[i][j]) << " ";
            if (j < 2) cout << "|";
        }
        cout << "\n";
        if (i < 2) cout << " ---|---|---\n";
    }
}



bool checkWin(char player)
{
    for (int i = 0; i < 3; i++) 
    {
        if ((board[i][0]==player && board[i][1]==player && board[i][2]==player) ||
            (board[0][i]==player && board[1][i]==player && board[2][i]==player))
            return true;
    }
    if ((board[0][0]==player && board[1][1]==player && board[2][2]==player) ||
        (board[0][2]==player && board[1][1]==player && board[2][0]==player))
        return true;
    return false;
}



bool isDraw() 
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ') return false;
    return true;
}



int main() 
{
    char key;
    bool gameOver = false;
    char playAgain;

    do {
        resetGame();

        while (true) 
        {
            drawBoard();
            key = getch();

            switch (key) 
            {
                case 'w':
                case 'W':
                    if (cursorY > 0) cursorY--;
                    break;
                case 's':
                case 'S':
                    if (cursorY < 2) cursorY++;
                    break;
                case 'a':
                case 'A':
                    if (cursorX > 0) cursorX--;
                    break;
                case 'd':
                case 'D':
                    if (cursorX < 2) cursorX++;
                    break;
                case '\r': // ENTER
                case ' ':  // SPACE
                    if (board[cursorY][cursorX] == ' ') 
                    {
                        board[cursorY][cursorX] = currentPlayer;
                        if (checkWin(currentPlayer)) 
                        {
                            drawBoard();
                            cout << "\n Player " << currentPlayer << " wins!\n";
                            gameOver = true;
                        } else if (isDraw()) 
                        {
                            drawBoard();
                            cout << "\n It's a draw!\n";
                            gameOver = true;
                        } else 
                        {
                            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                        }
                    }
                    break;
            }

            if (gameOver) break;
        }

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> playAgain;

        gameOver = false; // Reset for next round

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "\nThanks for playing! Press any key to exit...";
    getch();
    return 0;
}
