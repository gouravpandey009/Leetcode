#include <iostream>
using namespace std;

bool judgeCircle(string moves) {
    int x = 0, y = 0;

    for(char move : moves) {
        if(move == 'U') y++;
        else if(move == 'D') y--;
        else if(move == 'L') x--;
        else if(move == 'R') x++;
    }

    return x == 0 && y == 0;
}

int main() {
    string moves = "UDLR";
    
    if(judgeCircle(moves))
        cout << "Returned to origin" << endl;
    else
        cout << "Did not return to origin" << endl;

    return 0;
}