#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

// global variables
const int MAX_ROW = 30;
const int MAX_COL = 60;

// function prototypes
void displayMenu(void);
void setZeroArray(int setZero[30][60]);
void setInitialPatternArray(int setPattern[30][60]);
void displayArray(int displayArray[30][60]);
void copyArray(int sourceArray[30][60], int copyArray[30][60]);
void restartInput(char & ans, bool & restart);

int main ()
{
// restart beginning
    bool restart = true;
    while (restart == true)
    {
        system ("cls");

        // variables
        char ans;
        int tempArray[30][60];
        int currentArray[30][60];

        //Initialize random seed
        srand(time(NULL));

        // body
        displayMenu();

        setZeroArray(tempArray);

        setInitialPatternArray(tempArray);

        copyArray(tempArray, currentArray);

        displayArray(currentArray);

        // restart program
        restartInput(ans, restart);
    }
    return 0;
}

// functions
// display menu function
void displayMenu(void)
{
    cout << '[' << "P" << ']' << "lay " << static_cast<char>(150) << " Press 'P' to play." << endl;
    cout << '[' << "Q" << ']' << "uit " << static_cast<char>(150) << " Press 'Q' to exit." << endl;
}

// initialize and set array to 0
void setZeroArray(int setZero[30][60])
{
    // body
    for (int row = 0; row < 30; row++)
    {
        for (int col = 0; col < 60; col++)
        {
            setZero[row][col] = 0;
        }
    }
}

// set array pattern
void setInitialPatternArray(int setPattern[30][60])
{
    // variables
    int rowRand = (rand() % 24) + 1;
    int colRand = (rand() % 53) + 1;

    // body
    for (int row = rowRand; row < 6 + rowRand; row++)
    {
        // body
        for (int col = colRand; col < 7 + colRand; col++)
        {
            if (row < 5 + rowRand && col == colRand)
            {
                setPattern[row][col] = 1;
            }
            else if (row < 5 + rowRand && col == 6 + colRand)
            {
                setPattern[row][col] = 1;
            }
            else if (row == 5 + rowRand)
            {
                setPattern[row][col] = 1;
            }
            else
            {
                setPattern[row][col] = 0;
            }
        }
    }
}

// print function
void displayArray(int displayArray[30][60])
{
    // body
    for (int row = 0; row < 30; row++)
    {
        for (int col = 0; col < 60; col++)
        {
            cout << displayArray[row][col];
            if ((col + 1) % 60 == 0)
            {
                cout << endl;
            }
        }
    }
}

// copy array function
void copyArray(int sourceArray[30][60], int copyArray[30][60])
{
    for (int row = 0; row < 30; row++)
    {
        for (int col = 0; col < 60; col++)
        {
            copyArray[row][col] = sourceArray[row][col];
        }
    }
}

// restart function
void restartInput(char & ans, bool & restart)
{
    // body
    cout << ">>";
    cin >> ans;
    ans = static_cast<char>(toupper(ans));
    while (ans != 'P' && ans != 'Q')
    {
        cout << "Invalid input. Please try again." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> ans;
        ans = static_cast<char>(toupper(ans));
    }
    if (ans == 'P')
    {
        restart = true;
    }
    else
    {
        restart = false;
    }
}
