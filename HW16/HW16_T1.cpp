#include <iostream>
#include <cstdio>
#include <limits>

using namespace std;

int main()
{
    double speed = 0.0;
    double delta;
    char speed_str[20];

    do {
        cout << "Speed delta: ";
        cin >> delta;

        speed += delta;

        if (speed < 0) {
            speed = 0;
        } else if (speed > 150){
            speed = 150;
        }

        sprintf(speed_str, "%.1f", speed);
        cout << "Speed: " << speed_str << endl;

    } while (speed > 0.01);

    return 0;
}