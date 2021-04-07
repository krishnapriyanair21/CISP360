#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

//declare function prototypes
void fillBoard(char [][COLS]);
void showBoard(char [][COLS]);
void getChoice(char [][COLS], bool);
bool gameOver(char [][COLS]);

int main()
{
    ///main is complete, nothing to do here
    char board[ROWS][COLS];
    bool playerToggle = false;

    fillBoard(board);
    showBoard(board);

    while (!gameOver(board))
    {
        getChoice(board, playerToggle);
        showBoard(board);
        playerToggle = !playerToggle;
    }

    return 0;
}

///TODO (0)
   ///Define fillBoard
   ///Use a nested for loop to Fill the 2D array with '*'s
        ///DONE???
void fillBoard(char board[ROWS][COLS]){
    for (int i= 0 ; i < ROWS; i++){
        for (int j= 0; j< COLS; j++) {
            board[i][j] = '*';
        }
        cout<<endl;
    }
}

void showBoard(char b[][COLS]){
    cout << "  " << '1' << ' ' << '2' << ' ' << '3' << endl;

    for (int i = 0; i < ROWS; i++) {
        cout << i + 1 << ' ';
        for (int j = 0; j < COLS; j++){
            cout << b[i][j] << ' ';
        }
        cout <<endl;
    }
}
///TODO (1)
   ///Define showBoard
   ///Use a nested for loop to print the board
   ///For each row, print the row number, then use an inner for loop to print each cell, separated by a space
   ///print a newline when the inner for loop is complete to move on to the next row


void getChoice(char board[][COLS], bool playerToggle)
{
    string player;
    char c;
    int row, col;

    if (playerToggle == false) {
        player = "player 1";
        c = 'X';

        do
        {
            do
            {
                cout << "player 1, " << "Row: ";
                cin >> row;
            } while (!(row >= 1 && row <= 3));
            do
            {
                cout << "player 1, " << "Column: ";
                cin >> col;
            } while (!(col >= 1 && col <= 3));
        } while ((board[row - 1][col - 1] == 'X' || board[row - 1][col - 1] == 'O'));

        board[row - 1][col - 1] = c;

    }
    else if (playerToggle == true) {
        player = "player 2";
        c = 'O';

        do
        {
            do
            {
                cout << "player 2, " << "Row: ";
                cin >> row;
            } while (!(row >= 1 && row <= 3));
            do
            {
                cout << "player 2, " << "Column: ";
                cin >> col;
            } while (!(col >= 1 && col <= 3));
        } while ((board[row - 1][col - 1] == 'X' || board[row - 1][col - 1] == 'O'));

        board[row - 1][col - 1] = c;


    }
}

///TODO (4)
   ///implement gameOver

bool gameOver(char board[][COLS])
{
    bool gameOver = false;
    int count;
    count = 0;

    for (int i = 0; i < 3; i++){
        if( (  board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X')
           ||(board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X')
           ||(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
           ||(board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X')) /// X Wins
        {
            cout <<"Player 1 wins!" <<endl;
            gameOver = true;
            break;
        }
        else if((board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O')
             ||(board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O')
             ||(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
             ||(board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O')) ///O Wins
        {
            cout << "Player 2 wins!" <<endl;
            gameOver = true;
            break;
        }
        ///Tie
    }
    for (int i =0 ; i < 3; i++) {
        for (int j= 0; j <3; j++) {
            if (board[i][j] != '*')
            count++;
        }
    }
    if (count == 9){
        cout<< "Tie!" <<endl;
        gameOver = true;
    }
    return gameOver;
}

