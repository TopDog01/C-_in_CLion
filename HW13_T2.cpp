#include <iostream>
#include <vector>

int main() {
    // Вектор цен
    std::vector<float> prices {2.5, 4.25, 3.0, 10.0};


    std::vector<int> items {1, 1, 0, 3};

    float totalCost = 0.0f;


    for (int index : items) {
        if (index >= 0 && index < prices.size()) {
            totalCost += prices[index];
        } else {
            std::cout << "Index " << index << " is out of bounds for prices vector." << std::endl;
        }
    }


    std::cout << "Total cost of purchases: " << totalCost << std::endl;

    return 0;
}