#include <iostream>
#include <vector>
using namespace std;

class Robot {
public:
    int x = 0, y = 0;
    int w, h;
    int dir = 0;

    Robot(int width, int height) {
        w = width;
        h = height;
    }

    void move(int num) {
        int perimeter = 2 * (w + h) - 4;

        num %= perimeter;

        if (num == 0 && (x != 0 || y != 0)) {
            dir = 3;
            return;
        }

        while (num--) {
            if (dir == 0 && x + 1 < w) x++;
            else if (dir == 1 && y + 1 < h) y++;
            else if (dir == 2 && x - 1 >= 0) x--;
            else if (dir == 3 && y - 1 >= 0) y--;
            else {
                dir = (dir + 1) % 4;
                num++;
            }
        }
    }

    vector<int> getPos() {
        return {x, y};
    }

    string getDir() {
        if (dir == 0) return "East";
        if (dir == 1) return "North";
        if (dir == 2) return "West";
        return "South";
    }
};

int main() {
    Robot robot(6, 3);

    robot.move(2);
    auto pos = robot.getPos();

    cout << "Position: (" << pos[0] << ", " << pos[1] << ")" << endl;
    cout << "Direction: " << robot.getDir() << endl;

    return 0;
}