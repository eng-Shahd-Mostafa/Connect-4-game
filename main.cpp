#include<iostream>
#include<conio.h>

using namespace std;

char grid[7][7] = { {' ',' ',' ',' ',' ',' ',' '},
                    {' ',' ',' ',' ',' ',' ',' '},
                    {' ',' ',' ',' ',' ',' ',' '},
                    {' ',' ',' ',' ',' ',' ',' '},
                    {' ',' ',' ',' ',' ',' ',' '},
                    {' ',' ',' ',' ',' ',' ',' '},
                    {' ',' ',' ',' ',' ',' ',' '} };

void display()
{
    cout << "1 + 2 + 3 + 4 + 5 + 6 + 7" << endl;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            cout << grid[i][j] << " ";
            if (j < 6)
                cout << "| ";
        }
        cout << endl;
        if (i < 6)
            cout << "--+---+---+---+---+---+--";
        cout << endl;
    }
}

bool boardfull()
{
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            if (grid[i][j] == ' ')
                return false;
        }
    }
    return true;
}

bool check(char Player)
{
    for (int i = 0; i < 7; i++) 
        for (int j = 0; j < 4; j++) 
            if (grid[i][j] == Player && grid[i][j + 1] == Player && grid[i][j + 2] == Player && grid[i][j + 3] == Player)
                return true;
    for (int i = 0; i < 4; i++) 
        for (int j = 0; j < 7; j++) 
            if (grid[i][j] == Player && grid[i + 1][j] == Player && grid[i + 2][j] == Player && grid[i + 3][j] == Player)
                return true;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j] == Player && grid[i + 1][j + 1] == Player && grid[i + 2][j + 2] == Player && grid[i + 3][j + 3] == Player)
                return true;
            else if (grid[i][j + 3] == Player && grid[i + 1][j + 2] == Player && grid[i + 2][j + 1] == Player && grid[i + 3][j] == Player)
                return true;
        }
    }
    return false;
}

char Player = '1';

int main()
{
    cout << "Welcome to Connect 4! Please enter your position (1-7):\n";
    system("pause");
    while (true)
    {
        system("cls");
        display();
        int col, row;
        bool validInput = false;
        do {
            cout << "Player " << Player << " ,enter your position(1-7): \n";
            cin >> col;
            col--;

            if (col < 0 || col >= 7 || grid[0][col] != ' ') {
                cout << "Invalid input! Try again.\n";
                   if (cin.fail()) {
				cin.clear();
				cin.ignore(512, '\n');
               }
            }
            else {
                validInput = true;
            }
        } while (!validInput);

        row = 6;
        while (grid[row][col] != ' ' && row > 0)
            row--;

        if (row >= 0)
        {
            char symbol = (Player == '1') ? 'x' : 'o';
            grid[row][col] = symbol;
            if (check(symbol))
            {
                system("cls");
                display();
                cout << "Congratulations! Player " << Player << " wins!\n";
                cout << "Do you want to play again? (yes/no): ";
                string repeat;
                cin >> repeat;
                if (repeat == "yes")
                {
                    for (int i = 0; i < 7; i++)
                        for (int j = 0; j < 7; j++)
                            grid[i][j] = ' ';
                    cout << "Welcome to Connect 4! Please enter your position (1-7).\n";
                    continue;
                }
                break;
            }
            else if (boardfull())
            {
                system("cls");
                display();
                cout << "It's a draw!";
                cout << "Do you want to play again? (yes/no): ";
                string repeat;
                cin >> repeat;
                if (repeat == "yes")
                {
                    for (int i = 0; i < 7; i++)
                        for (int j = 0; j < 7; j++)
                            grid[i][j] = ' ';
                    cout << "Welcome to Connect 4! Please enter your position (1-7).\n";
                    continue;
                }
                break;
            }
            Player = (Player == '1') ? '2' : '1';
        }
    }
    return 0;
}
