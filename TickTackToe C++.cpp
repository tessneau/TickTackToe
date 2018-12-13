//File Name: health.cpp 
//Author: Tess Neau
//Email Address: neaut@kenyon.edu
//Assignment Number: TickTackToe Extra Credit
//Description: Tick Tack Toe game #3, where the computer never loses.
//Last Changed: Tuesday 29th November 2016


#include <iostream>
using namespace std;

void seedRandom()
{
    srand(time(NULL));
}

void displayBoard(char board[][3]) 
{
    cout << endl;
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            cout << " " << board[i][j];
            if (j < 2) 
            {
                cout << " |";
            }
        }
        cout << endl;
        if (i < 2) {
            cout << "-----------" << endl;
        }
    }
    cout << endl;
}

void clearBoard (char board[][3])
{
    for (int i=0 ; i < 3 ; i++)
    {
        for (int j=0 ; j < 3 ; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void nextMovePlayer(char p, char board[][3]) 
{
    int row, col;
    bool ok = true;
    do {
        ok = true;
        cout << "Player " << p << " What row (1,2,3) and column (1,2,3)? ";
        cin >> row >> col;
        if (row < 1 || row > 3) 
        {
            cout << "Bad row, must be between 1 and 3." << endl;
            ok = false;
        }
        if (col < 1 || col > 3) 
        {
            cout << "Bad column, must be between 1 and 3." << endl;
            ok = false;
        }
        if (ok && board[row - 1][col - 1] != ' ') 
        {
            cout << "Sorry, there is already an " << board[row - 1][col - 1] << " in that position!" << endl;
            ok = false;
        }
    } while (!ok);
    board[row - 1][col - 1] = p;

}

bool match3(char a, char b, char c) 
{
    if (a == b && b == c) 
        return true;
    else 
        return false;
}

bool match2(char a, char b, char c) // computer uses this to check either if it can win next turn or if player can win next turn.
{
    if (a == b && a != c) 
        return true;
    else 
        return false;
}

int checkEmpty(char board[][3])
{
    int empty(0);
    
    for(int i=0 ; i < 3 ; i++)
    {
        for(int j=0 ; j < 3 ; j++)
        {
            if (board[i][j] == ' ')
                empty++;
        } 
    }
    
    return empty;
}

void Block(char board[][3], char c) // computer uses this to block the player if the player is close to a win (next-turn win)
{  
    int possibleSpots = checkEmpty(board);
    
    
    //Check rows
    for (int i = 0; i < 3; i++) 
    {
            if (match2(board[i][2],board[i][1],' ') && board[i][2] != c && board[i][0] == ' ') 
            {
                board[i][0] = c;
            }
            else if (match2(board[i][0],board[i][2],' ') && board[i][2] != c && board[i][1] == ' ')
            {
                board[i][1] = c;
            }
            else if (match2(board[i][1],board[i][0],' ') && board[i][1] != c && board[i][2] == ' ')
            {
                board[i][2] = c;
            }
    }
    if (checkEmpty(board) == possibleSpots) // each time we want to make sure that the computer only plays one move, by keeping count of the empty spaces
    {
        //Check columns
        for (int i = 0; i < 3; i++) 
        {
                if (match2(board[2][i],board[1][i],' ') && board[2][i] != c && board[0][i] == ' ') 
                {
                    board[0][i] = c;
                }
                else if (match2(board[0][i],board[2][i],' ') && board[2][i] != c && board[1][i] == ' ')
                {
                    board[1][i] = c;
                }
                else if (match2(board[0][i],board[1][i],' ') && board[1][i] != c && board[2][i] == ' ')
                {
                    board[2][i] = c;
                }
        }
    }
    
    if (checkEmpty(board) == possibleSpots)
    {
    //Check diagonals 
            if (match2(board[0][0],board[1][1],' ') && board[0][0]!=c && board[2][2] ==' ') 
            {
                board[2][2] = c;
            }
            else if (match2(board[1][1],board[2][2],' ') && board[0][0]!=c && board[0][0] ==' ')
            {
                board[0][0] = c;
            }
            else if (match2(board[0][0],board[2][2],' ') && board[0][0]!=c && board[1][1] ==' ')
            {
                board[1][1] = c;
            }
        
            if (match2(board[0][0],board[1][1],' ') && board[0][0]!=c && board[2][2] ==' ') 
            {
                board[2][2] = c;
            }
            else if (match2(board[1][1],board[2][2],' ') && board[0][0]!=c && board[0][0] ==' ')
            {
                 board[0][0] = c;
            }
            else if (match2(board[0][0],board[2][2],' ') && board[0][0]!=c && board[1][1] ==' ')
            {
                board[1][1] = c;
            }
            
            if (match2(board[2][0],board[1][1],' ') && board[2][0]!=c && board[0][2] ==' ') 
            {
                board[0][2] = c;
            }
            else if (match2(board[0][2],board[1][1],' ') && board[0][2]!=c && board[2][0] ==' ') 
            {
                board[2][0] = c;
            }
            else if (match2(board[2][0],board[0][2],' ') && board[2][0]!=c && board[1][1] ==' ') 
            {
                board[1][1] = c;
            }
    }
}

void checkCompWin(char board[][3], char c) //computer checks if it could win and does so if possible
{
    int possibleSpots = checkEmpty(board);
    
    if (checkEmpty(board) == possibleSpots)
    {
        //Check rows
        for (int i = 0; i < 3; i++) 
        {
                if (match2(board[i][2],board[i][1],' ') && board[i][2] == c && board[i][0] == ' ') 
                {
                    board[i][0] = c;
                }
                else if (match2(board[i][0],board[i][2],' ') && board[i][2] == c && board[i][1] == ' ')
                {
                    board[i][1] = c;
                }
                else if (match2(board[i][1],board[i][0],' ') && board[i][1] == c && board[i][2] == ' ')
                {
                    board[i][2] = c;
                }
        }
    }
    
    if (checkEmpty(board) == possibleSpots)
    {
        //Check columns
        for (int i = 0; i < 3; i++) 
        {
                if (match2(board[2][i],board[1][i],' ') && board[2][i] == c && board[0][i] == ' ') 
                {
                    board[0][i] = c;
                }
                else if (match2(board[0][i],board[2][i],' ') && board[2][i] == c && board[1][i] == ' ')
                {
                    board[1][i] = c;
                }
                else if (match2(board[0][i],board[1][i],' ') && board[1][i] == c && board[2][i] == ' ')
                {
                    board[2][i] = c;
                }
        }
    }
    
    if (checkEmpty(board) == possibleSpots)
    {
    
    //Check diagonals 
    {
            if (board[0][0] != ' ' || board[1][1] != ' ' || board[2][2] != ' ') 
            {
                if (match2(board[0][0],board[1][1],' ') && board[2][2] ==' ') 
                {
                    board[2][2] = c;
                }
                else if (match2(board[1][1],board[2][2],' ') && board[0][0] ==' ')
                {
                    board[0][0] = c;
                }
                else if (match2(board[0][0],board[2][2],' ') && board[1][1] ==' ')
                {
                    board[1][1] = c;
                }
            }

            if (board[0][2] != ' ' || board[1][1] != ' ' || board[2][0] != ' ') 
            {
                if (match2(board[0][0],board[1][1],' ') && board[2][2] ==' ') 
                {
                    board[2][2] = c;
                }
                else if (match2(board[1][1],board[2][2],' ') && board[0][0] ==' ')
                {
                     board[0][0] = c;
                }
                else if (match2(board[0][0],board[2][2],' ') && board[1][1] ==' ')
                {
                    board[1][1] = c;
                }
            }
        }
    }
}

void firstMove(char comp, char board[][3]) //randomly chooses someone to go first
{
    seedRandom();
    int random = (rand()%100);
    
    if ((random) <= 50)
    {
        cout << "\nComputer has the first move.\n";
        board[1][1] = comp;
    }
    else 
    {
        cout << "\nYou get the first move!\n";
    }
}

void nextMoveComputer(char c, char board[][3]) //big function for the computer's move
{
    seedRandom();
    int a = rand()%3;
    int b = rand()%3;
    
    if (checkEmpty(board) == 8)
    {
        if (board[1][1] == ' ')
            board[1][1] = c;
        else
            board[2][2] = c;
    }
    else if (checkEmpty(board) == 7)
    {
        if (board[1][1] != ' ' && board[2][2] == 'c')
            board[0][0] = c;
        else
        {
            Block(board,c);
            while (checkEmpty(board) == 7)
            {
                if(board[a][b]==' ')
                {
                    board[a][b] = c;
                    a = rand()%3;
                    b = rand()%3;
                }
            }
        }    
    }
    else if (checkEmpty(board) == 6)
    {
        checkCompWin(board,c);
        if (checkEmpty(board) == 6)
            Block(board,c);
        while (checkEmpty(board) == 6)
        {
            if(board[a][b]==' ')
            {
                board[a][b] = c;
                a = rand()%3;
                b = rand()%3;
            }
        }
    }
    else if (checkEmpty(board) == 5)
    {
        checkCompWin(board,c);
        if (checkEmpty(board) == 5)
            Block(board,c);
        while (checkEmpty(board) == 5)
        {
            if(board[a][b]==' ')
            {
                board[a][b] = c;
                a = rand()%3;
                b = rand()%3;
            }
        }
    }
    else if (checkEmpty(board) == 4)
    {
        checkCompWin(board,c);
        if (checkEmpty(board) == 4)
            Block(board,c);
        while (checkEmpty(board) == 4)
        {
            if(board[a][b]==' ')
            {
                board[a][b] = c;
                a = rand()%3;
                b = rand()%3;
            }
        }
    }
    else if (checkEmpty(board) == 3)
    {
        checkCompWin(board,c);
        if (checkEmpty(board) == 3)
            Block(board,c);
        while (checkEmpty(board) == 3)
        {
            if(board[a][b]==' ')
            {
                board[a][b] = c;
                a = rand()%3;
                b = rand()%3;
            }
        }
    }
    else if (checkEmpty(board) == 2)
    {
        checkCompWin(board,c);
        if (checkEmpty(board) == 2)
            Block(board,c);
        while (checkEmpty(board) == 2)
        {
            if(board[a][b]==' ')
            {
                board[a][b] = c;
                a = rand()%3;
                b = rand()%3;
            }
        }
    }
    else if (checkEmpty(board) == 1)
    {
        checkCompWin(board,c);
        if (checkEmpty(board) == 1)
            Block(board,c);
        while (checkEmpty(board) == 1)
        {
            if(board[a][b]==' ')
            {
                board[a][b] = c;
                a = rand()%3;
                b = rand()%3;
            }
        }
    }
}

bool checkDone(char board[][3], char& winner) // checks to see if someone has won
{
    // Checks rows
    for (int i = 0; i < 3; i++) 
    {
        if (board[i][0] != ' ') 
        {
            if (match3(board[i][0],board[i][1],board[i][2])) 
            {
                winner = board[i][0];
                return true;
            }
        }
    }
    // Checks columns
    for (int i = 0; i < 3; i++) 
    {
        if (board[0][i] != ' ') 
        {
            if (match3(board[0][i],board[1][i],board[2][i])) 
            {
                winner = board[0][i];
                return true;
            }
        }
    }

    // Check diagonals
    if (board[0][0] != ' ') 
    {
        if (match3(board[0][0],board[1][1],board[2][2])) 
        {
            winner = board[0][0];
            return true;
        }
    }
    if (board[2][0] != ' ') 
    {
        if (match3(board[2][0],board[1][1],board[0][2])) 
        {
            winner = board[2][0];
            return true;
        }
    }
    return false;
}

bool Tie(char board[][3]) //checks for a full board in which there are no more moves possible
{
    int empty(0);
    
    for (int i=0 ; i < 3 ; i++)
    {
        for (int j=0 ; j < 3 ; j++)
        {
            if (board[i][j] == ' ')
                    empty++;
        }
    }
    
    if (empty==0)
        return true;
    else
        return false;
}

/*
 * 
 */
int main() 
{
    
    char myBoard[3][3];
    char player, computer;
    char winner;
    char anotherGame;
    int win(0), loss(0), draw(0);
    
    cout << "Hi, would you like to play as X or as O?: ";
    cin  >> player;
    
    if(player == 'O' || player == 'X')
    {
        if (player == 'O')
            computer = 'X';
        else
            computer = 'O';
        
        do
        {
            //new game
            clearBoard(myBoard);
            firstMove(computer, myBoard);
            
            do 
            {   // new X or O
                displayBoard(myBoard);
                nextMovePlayer(player, myBoard);
                if (checkDone(myBoard, winner)) 
                {
                    displayBoard(myBoard);
                    cout << "You win "<< winner << "!!!! \n";
                    win++;
                    break;
                }
                if(Tie(myBoard))
                {
                    displayBoard(myBoard);
                    cout << "Seems like you tied!\n";
                    draw++;
                    break;
                }
                
                nextMoveComputer(computer,myBoard);
                if (checkDone(myBoard, winner)) 
                {
                    displayBoard(myBoard);
                    cout << "Computer "<< winner << " wins! Better luck next time... \n";
                    loss++;
                    break;
                }
                if(Tie(myBoard))
                {
                    displayBoard(myBoard);
                    cout << "Seems like you tied!\n";
                    draw++;
                    break;
                }
            } while (1);
            
            cout << "Score:\nWins: "<< win << "\nDraws: "<< draw << "\nLosses: " << loss;

            cout << "\nWould you like to play another match?(y or n): ";
            cin  >>  anotherGame;


        } while (anotherGame == 'y' || anotherGame == 'Y');
    }
    else
        cout << "That is not a valid character.";
    
    return 0;
}
