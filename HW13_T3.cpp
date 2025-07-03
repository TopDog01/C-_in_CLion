#include <iostream>
#include <vector>

int main() {
    std::vector<int> db(20);
    int currentPosition = 0;
    int input;

    while (true) {
        std::cout << "Input number: ";
        std::cin >> input;

        if (input == -1) {

            std::cout << "Output: ";
            for (int i = 0; i < 20; i++) {
                if (i < currentPosition) {
                    std::cout << db[i] << " ";
                } else {
                    std::cout << "0 ";
                }
            }
            std::cout << std::endl;
            break;
        }


        if (currentPosition < 20) {
            db[currentPosition] = input;
            currentPosition++;
        } else {

            db.erase(db.begin());
            db.push_back(input);
        }
    }

    return 0;
}