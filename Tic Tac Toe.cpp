#include <vector>
#include <iomanip>
#include <iostream>
//#define ali ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
//int x = sizeof(array) / sizeof(array[0]);
    //sort(array, array + x);*/ //array sorting :D


//>>>>>>>>>>>>>>>>>>>>>the Board<<<<<<<<<<<<<<<<<<<<<
char theboard[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
};

vector<char> odd = { '1', '3', '5', '7', '9' }; // odd list in which the numbers the first player can play

vector<char> even = { '0', '2', '4', '6', '8' }; // even list in which the numbers the first player can play

int drawcounter = 1;

void board() {

    for (int row = 0; row < 3; ++row) {
        cout << "|  ";
        for (int column = 0; column < 3; ++column) {
            cout << theboard[row][column] << "  |  ";
        }
        cout << endl << "-------------------" << endl;

    }


}


bool checkwinner(string player) {
    bool flag = false;
    int sumrow = 0, columnsum = 0, leftdiagonalsum = 0, rightdiagonalsum = 0;

    //>>>>>>>>>>>>>>To Check Row Sum>>>>>>>>>>>>>>>>>>>

    for (int row = 0; row < 3; ++row) {
        if (flag) break;

        else {
            for (int cell = 0; cell < 3; ++cell) {
                if (theboard[row][cell] == ' ') {
                    flag = true;
                    break;
                }
                else if (sumrow == 15) {
                    board();
                    cout << player << "Is The Winner";
                    return true;
                }

                else sumrow += theboard[row][cell] - '0';
            }
        }
    }

    //>>>>>>>>>>>>>>>>>>>>>>>>End<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


    //>>>>>>>>>>>>>>>>>>>>>>>column sum <<<<<<<<<<<<<<<<<<<<<<<<<<<
    flag = true;
    columnsum = 0;
    for (int row = 0; row < 3; ++row) {

        if (flag) {

            for (int cell = 0; cell < 3; ++cell) {

                if (theboard[cell][row] == ' ') {
                    flag = false;
                    break;
                }
                else if (columnsum == 15) {
                    board();
                    cout << player << "Is The Winner";
                    return true;
                }
                else columnsum += (theboard[cell][row] - '0');
            }
        }
    }




    //>>>>>>>>>>>>>>>>>>>>>>>>End<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

    //>>>>>>>>>>>>>>>>>>>>>>>left diagonal sum<<<<<<<<<<<<<<<<<<<<
    for (int cell = 0; cell < 3; ++cell) {
        if (theboard[cell][cell] == ' ')
            break;

        else if (leftdiagonalsum == 15) {
            board();
            cout << player << "Is The Winner";
            return true;
        }

        else leftdiagonalsum += (theboard[cell][cell] - '0');
    }

    //>>>>>>>>>>>>>>>>>>>>>>>>End<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

    //>>>>>>>>>>>>>>>>>>>>>>>right diagonal sum<<<<<<<<<<<<<<<<<<<<

    for (int cell = 0; cell < 3; ++cell) {
        if (theboard[cell][2 - cell] == ' ')
            break;

        else if (rightdiagonalsum == 15) {
            board();
            cout << player << "Is The Winner";
            return true;
        }

        else rightdiagonalsum += (theboard[cell][2 - cell] - '0');
    }

    return false;
}

bool inputs() {
    char fprow, fpcolumn, fpinput, sprow, spcolumn, spinput;

    //>>>>>>>>>>>>>>>>>>First Player Inputs<<<<<<<<<<<<<<<<<<<<<<<<//

    cout << "first player enter the place you want to play the number in" << endl;
    cin >> fprow >> fpcolumn;


    while (fprow - '0' > 3 or fprow - '0' < 1 or fpcolumn - '0' > 3 or fpcolumn - '0' < 1 or
        theboard[fprow - '0' - 1][fpcolumn - '0' - 1] != ' ') {
        cout << "Invalid Place or taken one To Play In,enter a new one" << endl;
        cin >> fprow >> fpcolumn;
    }
    cout << "First play Enter the odd number you want play from 1 to 9" << endl;
    cin >> fpinput;


    while (find(odd.begin(), odd.end(), fpinput) == odd.end()) {
        cout << "invalid number,enter a new one" << endl;
        cin >> fpinput;
    }

    drawcounter += 1;
    odd.erase(find(odd.begin(), odd.end(), fpinput));


    theboard[(fprow - '0') - 1][(fpcolumn - '0') - 1] = fpinput;


    board();
    if (checkwinner("First Player ")) return true;

    if (drawcounter == 10 and !checkwinner("")) {
        cout << "Well Played Both Of You,It is a Draw :)" << endl;
        return true;
    }


    //>>>>>>>>>>>>>>>>>>>>>>>>End<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


    //>>>>>>>>>>>>>>>>>>>>Second Player Inputs<<<<<<<<<<<<<<<<<<<<<//


    cout << " second player enter the place you want to play the number in" << endl;
    cin >> sprow >> spcolumn;


    while (sprow - '0' > 3 or sprow - '0' < 1 or spcolumn - '0' > 3 or spcolumn - '0' < 1 or
        theboard[sprow - '0' - 1][spcolumn - '0' - 1] != ' ') {
        cout << "Invalid Place or taken one To Play In,enter a new one" << endl;
        cin >> sprow >> spcolumn;
    }
    cout << " second play Enter the even number you want play from 0 to 8" << endl;
    cin >> spinput;


    while (find(even.begin(), even.end(), spinput) == even.end()) {
        cout << "invalid number,enter a new one" << endl;
        cin >> spinput;
    }

    drawcounter += 1;

    even.erase(find(even.begin(), even.end(), spinput));


    theboard[(sprow - '0') - 1][(spcolumn - '0') - 1] = spinput;

    if (checkwinner("Second Player "))  return true;

    return false;

}
//>>>>>>>>>>>>>>>>>>>>>>>>End<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


int main() {
    while (true) {
        bool whiteflag = true;
        board();
        if (inputs())break;


        for (int i = 0; i < 3; ++i) {
            if (!whiteflag)  break;
            for (int j = 0; j < 3; ++j) {
                if (theboard[i][j] == ' ') {
                    whiteflag = false;
                    break;
                }
            }
        }
    }





}











