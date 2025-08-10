#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;


enum Switches {
    LIGHTS_INSIDE        = 1,
    LIGHTS_OUTSIDE       = 2,
    HEATERS              = 4,
    WATER_PIPE_HEATING   = 8,
    CONDITIONER          = 16
};

int main() {
    int switches_state = 0;
    int current_hour = 0;
    int color_temperature = 5000;

    cout << fixed << setprecision(1);
    cout << "=== Smart Home Simulation for 2 Days ===" << endl;

    for (int day = 0; day < 2; ++day) {
        for (int hour = 0; hour < 24; ++hour) {
            current_hour = day * 24 + hour;


            cout << "\n[Time: " << setw(2) << hour << ":00]" << endl;


            string input;
            cout << "Temperature inside, temperature outside, movement, lights: ";
            getline(cin, input);

            if (input.empty()) {
                hour--;
                continue;
            }

            stringstream ss(input);
            double temp_inside, temp_outside;
            string movement, lights_input;
            ss >> temp_inside >> temp_outside >> movement >> lights_input;

            bool motion_detected = (movement == "yes");
            bool lights_on_input = (lights_input == "on");


            if (temp_outside < 0.0 && !(switches_state & WATER_PIPE_HEATING)) {
                switches_state |= WATER_PIPE_HEATING;
                cout << "Water pipe heating ON!" << endl;
            } else if (temp_outside >= 5.0 && (switches_state & WATER_PIPE_HEATING)) {
                switches_state &= ~WATER_PIPE_HEATING;
                cout << "Water pipe heating OFF!" << endl;
            }


            bool is_evening = (hour >= 16 || hour < 5);
            if (is_evening && motion_detected && !(switches_state & LIGHTS_OUTSIDE)) {
                switches_state |= LIGHTS_OUTSIDE;
                cout << "Garden lights ON!" << endl;
            } else if (!((is_evening && motion_detected)) && (switches_state & LIGHTS_OUTSIDE)) {
                switches_state &= ~LIGHTS_OUTSIDE;
                cout << "Garden lights OFF!" << endl;
            }


            if (temp_inside < 22.0 && !(switches_state & HEATERS)) {
                switches_state |= HEATERS;
                cout << "Heaters ON!" << endl;
            } else if (temp_inside >= 25.0 && (switches_state & HEATERS)) {
                switches_state &= ~HEATERS;
                cout << "Heaters OFF!" << endl;
            }


            if (temp_inside >= 30.0 && !(switches_state & CONDITIONER)) {
                switches_state |= CONDITIONER;
                cout << "Conditioner ON!" << endl;
            } else if (temp_inside <= 25.0 && (switches_state & CONDITIONER)) {
                switches_state &= ~CONDITIONER;
                cout << "Conditioner OFF!" << endl;
            }


            if (lights_on_input && !(switches_state & LIGHTS_INSIDE)) {
                switches_state |= LIGHTS_INSIDE;
                cout << "Lights ON!" << endl;
            } else if (!lights_on_input && (switches_state & LIGHTS_INSIDE)) {
                switches_state &= ~LIGHTS_INSIDE;
                cout << "Lights OFF!" << endl;
            }


            if (switches_state & LIGHTS_INSIDE) {
                if (hour == 0 && day == 0) {

                    color_temperature = 5000;
                }

                if (hour >= 16 && hour < 20) {
                    int minutes_into_period = (hour - 16) * 60;  // от 0 до 240 минут
                    double ratio = minutes_into_period / 240.0;

                    color_temperature = 5000 - static_cast<int>(round(ratio * (5000 - 2700)));
                } else if (hour == 20) {
                    color_temperature = 2700;
                }
                cout << "Color temperature: " << color_temperature << "K" << endl;
            }


            if (hour == 0) {
                color_temperature = 5000;
            }
        }
    }

    cout << "\n=== Simulation completed ===" << endl;
    return 0;
}