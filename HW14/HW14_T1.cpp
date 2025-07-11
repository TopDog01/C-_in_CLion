#include <iostream>

int main() {
    // Initialize arrays
    int utensils[2][12] = { {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4},
                            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} };

    int plates[2][12] = { {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3},
                          {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} };

    int chairs[2][12] = { {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                          {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} };


    chairs[0][4] += 1;


    utensils[0][2] -= 1;


    utensils[0][10] -= 1;
    utensils[0][2] += 1;


    plates[0][10] -= 1;


    std::cout << "Utensils:" << std::endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 12; j++) {
            std::cout << utensils[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Plates:" << std::endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 12; j++) {
            std::cout << plates[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Chairs:" << std::endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 12; j++) {
            std::cout << chairs[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}