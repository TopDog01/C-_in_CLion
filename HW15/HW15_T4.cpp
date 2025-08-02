#include <iostream>
#include <vector>

void printSortedByAbsoluteValue(const std::vector<int>& arr) {
    int n = arr.size();
    int left = 0;
    int right = n - 1;

    std::vector<int> result;

    while (left <= right) {

        if (std::abs(arr[left]) < std::abs(arr[right])) {
            result.push_back(arr[left]);
            left++;
        } else {
            result.push_back(arr[right]);
            right--;
        }
    }

    // Printing the sorted output
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i];
        if (i != result.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {-100, -50, -5, 1, 10, 15};

    std::cout << "Array sorted by absolute values: ";
    printSortedByAbsoluteValue(arr);

    return 0;
}