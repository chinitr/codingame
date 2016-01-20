#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int nbFloors; // number of floors
    int width; // width of the area
    int nbRounds; // maximum number of rounds
    int exitFloor; // floor on which the exit is found
    int exitPos; // position of the exit on its floor
    int nbTotalClones; // number of generated clones
    int nbAdditionalElevators; // ignore (always zero)
    int nbElevators; // number of elevators
    cin >> nbFloors >> width >> nbRounds >> exitFloor >> exitPos >> nbTotalClones >> nbAdditionalElevators >> nbElevators; cin.ignore();

    typedef struct ElevatorPos {
        int floor;
        int pos;
    };
    
    cerr << "n elevator=" << nbElevators << endl;
    std::vector<ElevatorPos> elevators;
    for (int i = 0; i < nbElevators; i++) {
        int elevatorFloor; // floor on which this elevator is found
        int elevatorPos; // position of the elevator on its floor
        cin >> elevatorFloor >> elevatorPos; cin.ignore();
        
        ElevatorPos pos;
        pos.floor = elevatorFloor;
        pos.pos = elevatorPos;
        elevators.push_back(pos);
        cerr << "elevator=" << elevatorFloor << " " << elevatorPos << endl;
    }

    int initPos = -1;
    // game loop
    while (1) {
        int cloneFloor; // floor of the leading clone
        int clonePos; // position of the leading clone on its floor
        string direction; // direction of the leading clone: LEFT or RIGHT
        cin >> cloneFloor >> clonePos >> direction; cin.ignore();
        cerr << cloneFloor << " " << clonePos << endl;
        
        if (initPos == -1) {
            initPos = clonePos;
        }
        if (initPos == clonePos) {
            cout << "WAIT" << endl;
            continue;
        }
        
        std::string cmd = "WAIT";
        if (exitFloor == cloneFloor) {
            if (clonePos > exitPos && direction == "RIGHT") {
                cmd = "BLOCK";
            } else if (clonePos < exitPos && direction == "LEFT") {
                cmd = "BLOCK";
            }
        } else {
            for (size_t i = 0; i < elevators.size(); ++i) {
                ElevatorPos& pos = elevators[i];
                if (pos.floor == cloneFloor) {
                    if (clonePos > pos.pos && direction == "RIGHT") {
                        cmd = "BLOCK";
                    } else if (clonePos < pos.pos && direction == "LEFT") {
                        cmd = "BLOCK";
                    }
                    break;
                }
            }            
        }
        
        cout << cmd << endl; // action: WAIT or BLOCK
    }
}
