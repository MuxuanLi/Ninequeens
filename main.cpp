#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <cstdio>
#define clear() cout << "\033c" << flush
using namespace std;

const int SIZE = 9;
int Queen[15][15]; 

void intro()
{
    cout << "===============================================" << endl;
    cout << "***Welcome to run the nine queens game! ***" << endl;
    cout << "【The rules of the game are as follows:】" << endl;
    cout << "In this game there will be a 9*9 chess board, we can place queens on the chess board," << endl;
    cout << "Make it impossible to attack each other, i.e. any two queens cannot be on the same row, column and diagonal of the board." << endl;
    cout << "1. If one side is within the attack range of other queens when placing the queen, the side fails and the game is over!" << endl;
    cout << "2. If you cannot make any placements, the game is over!" << endl; 
    cout << "================================================" << endl << endl;
}


void drawBoard()
{
    
    cout << " ";
    for (int i = 1; i <= SIZE; i++) cout << "   " << i;
    cout << "\n";
    
    cout << "  ╔";
    for (int i = 1; i <= SIZE-1; i++) cout << "═══╤";
    cout << "═══╗\n";
    
    for (int i = 1; i <= SIZE; i++) 
    {
        cout << i << " ║";
        for (int j = 1; j <= SIZE; j++) 
        {
            if (Queen[i][j] == 9) 
            {
                cout << " ♕ ";
            }
            if (Queen[i][j] == -9) 
            {
                cout << " ♛ ";
            }
            if (Queen[i][j] == 0 || Queen[i][j] == 1) 
            {
                cout << "   ";
            }
            if (j != SIZE)
                cout << "│";
            else
                cout << "║";
        }
        cout << " \n";
        
        if (i != SIZE)
        {
            cout << "  ╟";
            for (int i = 1; i <= SIZE-1; i++) cout << "───┼";
            cout << "───╢\n";
        }
        else
        {
            cout << "  ╚";
            for (int i = 1; i <= SIZE-1; i++) cout << "═══╧";
            cout << "═══╝\n";
        }
    }
}


bool isValid(int hang, int lie) 
{
    if (Queen[hang][lie] != 0)
        return false;
    return true;
}


void mark(int who, int hang, int lie) 
{
   
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
           
            if (Queen[i][j] != 0) continue;
            
            if (hang - i == 0 && lie - j != 0)
            {
                Queen[i][j] = 1;
            }
           
            if (hang - i != 0 && lie - j == 0)
            {
                Queen[i][j] = 1;
            }
            
            if (abs(hang - i) == abs(lie - j))
            {
                Queen[i][j] = 1;
            }
        }
    }
    
    if (who == 9) Queen[hang][lie] = 9;
    else Queen[hang][lie] = -9;
}


void game() 
{
    cout << "【Players start first! 】" << endl << endl; 
    while (true)
    {
        
        cout << "Ask the player to enter the row and column numbers (example: row and column numbers: 1 2)" << endl;
        int hang1, lie1;
        cin >> hang1 >> lie1;
        if (isValid(hang1, lie1) == false) 
        {
            cout << "Victory or defeat is standard issue! Heroes, please come again!" << endl;
            exit(0);
        }
        else
        {
        
            mark(9, hang1, lie1);
         
            drawBoard();
        }
        
       
        srand(time(0));
        int hang2, lie2;
        for (int i = 1; i <= 1000000; i++)
        {
            hang2 = rand() % 9 + 1;
            lie2 = rand() % 9 + 1;
            if (isValid(hang2, lie2) == false) continue;
            else break;
        }
        if (isValid(hang2, lie2) == false)
        {
            cout << "The computer cannot place any position, congratulations to the player! game over" << endl;
            exit(0);
        }
        else
        {
          
            mark(-9, hang2, lie2);
            cout << "computer placed a queen at (" << hang2 << ", " << lie2 << ") " << endl;
            cout << "Press enter to see the computer rounds..." << endl;
            getchar();
            getchar();
           
            drawBoard();
        }
    }
}

int main()
{
    intro(); 
    drawBoard(); 
    game(); 
    
    return 0;
}