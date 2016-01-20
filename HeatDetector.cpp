#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
typedef struct Rect {
    int left;
    int top;
    int right;
    int bottom;
};

int main()
{
    int W; // width of the building.
    int H; // height of the building.
    cin >> W >> H; cin.ignore();
    int N; // maximum number of turns before game over.
    cin >> N; cin.ignore();
    int X0;
    int Y0;
    cin >> X0 >> Y0; cin.ignore();
    
    Rect rc;
    rc.left = 0;
    rc.top = 0;
    rc.right = W - 1;
    rc.bottom = H - 1;
    
    cerr << "w=" << W << " " << "h=" << H << endl;
    // game loop
    while (1) {
        string BOMB_DIR; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> BOMB_DIR; cin.ignore();
        
        cerr << BOMB_DIR << endl;
        cerr << "left=" << rc.left << " ";
        cerr << "top=" << rc.top << " ";
        cerr << "right=" << rc.right << " ";
        cerr << "bottom=" << rc.bottom << endl;
        
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        int x = 0;
        int y = 0;
        if (BOMB_DIR == "U") {
            rc.bottom = Y0-1;
        } else if (BOMB_DIR == "UR") {
            rc.left = X0+1;
            rc.bottom = Y0-1;
        } else if (BOMB_DIR == "R") {
            rc.left = X0+1;
        } else if (BOMB_DIR == "DR") {
            rc.left = X0+1;
            rc.top = Y0+1;
        } else if (BOMB_DIR == "D") {
            rc.top = Y0+1;
        } else if (BOMB_DIR == "DL") {
            rc.right = X0-1;
            rc.top = Y0+1;
        } else if (BOMB_DIR == "L") {
            rc.right = X0-1;
        } else if (BOMB_DIR == "UL") {
            rc.right = X0-1;
            rc.bottom = Y0-1;
        }
        
        x = rc.left + (rc.right - rc.left) / 2;
        y = rc.top + (rc.bottom - rc.top) / 2;
        X0 = x;
        Y0 = y;
        cout << x << " " << y << endl;
    }
}
