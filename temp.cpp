#include <iostream>
using namespace std;

int count = 0;
char board[8][8];
int col[8];
int bslash[15];
int slash[15];

void chess(int row);
void init(void);
void print(void);

int main(void)
{
    int i, j;
    init();
    print();
    chess(0);
    return 0 ;
}

void init(void)
{
    int i;
    int j;
    for (i = 0; i < 8; i++)
    {
        col[i] = 0;
        for (j = 0; j < 8; j++)
            board[i][j] = '*';
    }
    for (i = 0; i < 15; i++)
    {
        bslash[j] = 0;
        slash[j] = 0;
    }
}

void print(void)
{
    int i, j;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
            cout << board[i][j] << ' ';
        cout << endl;
    }
    cout << endl << endl;
}

void chess(int row)
{
    int c;
    for (c = 0; c < 8; c++)
    {
        if (col[c] == 0 && bslash[row + 7 - c] == 0 && slash[row + c] == 0)
        {
            col[c] = 1;
            bslash[row + 7 - c] = 1;
            slash[row + c] = 1;
            board[row][c] = '@';

            if (row < 7)
                chess(row + 1);
            else
                print();

            col[c] = 0;
            bslash[row + 7 - c] = 0;
            slash[row + c] = 0;
            board[row][c] = '*';
        }
    }
}


