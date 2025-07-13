#include <iostream>

int main() {

    int cutlery[2][6] = {
            {3, 3, 3, 3, 3, 3},
            {3, 3, 3, 3, 3, 3}
    };


    int plates[2][2] = {
            {2, 1},
            {2, 1}
    };


    int chairs[2][6] = {
            {1, 1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1, 1}
    };


    chairs[0][4] += 1;


    cutlery[1][2] -= 1;


    cutlery[0][0] -= 1;
    cutlery[1][2] += 1;


    plates[0][1] -= 1;


    std::cout << "Cutlery (forks, spoons, knives):\n";
    for (int i = 0; i < 2; ++i) {
        std::cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < 6; ++j) {
            std::cout << cutlery[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\nPlates (regular, dessert):\n";
    for (int i = 0; i < 2; ++i) {
        std::cout << "Row " << i + 1 << ": " << plates[i][0] << " regular, " << plates[i][1] << " dessert\n";
    }

    std::cout << "\nChairs:\n";
    for (int i = 0; i < 2; ++i) {
        std::cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < 6; ++j) {
            std::cout << chairs[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}