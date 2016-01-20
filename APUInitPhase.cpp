#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Don't let the machines win. You are humanity's last hope...
 **/
int main()
{
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();
    cerr << width << " " << height << endl;
    
    std::vector<std::string> lines;
    lines.reserve(height);
    for (int i = 0; i < height; i++) {
        string line; // width characters, each either 0 or .
        getline(cin, line);
        lines.push_back(line);
        cerr << line << endl;
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    for (size_t i = 0; i < lines.size(); ++i) {
        string& line = lines[i];
        for (size_t cell = 0; cell < line.size(); ++cell) {
            char c = line[cell];
            if (c == '.')
                continue;
                
            int x1 = cell;
            int y1 = i;
            int x2 = -1;
            int y2 = -1;
            int x3 = -1;
            int y3 = -1;
            for (int next = cell + 1; next < line.size(); ++next) {
                char c = line[next];
                if (c == '.')
                    continue;
                
                x2 = next;
                y2 = i;
                break;
            }
            for (int next = i + 1; next < lines.size(); ++next) {
                string& secondLine = lines[next];
                char c = secondLine[cell];
                if (c == '.')
                    continue;
                    
                    x3 = cell;
                    y3 = next;
                    break;
            }
            cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
        }
    }
}
