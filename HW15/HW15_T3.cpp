#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int main() {
    std::set<int> smallestNumbers;
    int input;

    while (true) {
        std::cin >> input;

        if (input == -2) {
            std::cout << "Program terminated." << std::endl;
            break;
        }
        if (input == -1) {
            if (smallestNumbers.size() < 5) {
                std::cout << "Not enough numbers." << std::endl;
            } else {
                auto it = smallestNumbers.begin();
                std::advance(it, 4);
                std::cout << "Fifth smallest number: " << *it << std::endl;
            }
            continue;
        }

        smallestNumbers.insert(input);

        if (smallestNumbers.size() > 5){
            smallestNumbers.erase(--smallestNumbers.end());
        }
    }

    return 0;
}