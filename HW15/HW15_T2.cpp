#include <iostream>
#include <vector>
#include <unordered_map>

void findSumPair(const std::vector<int>& arr, int target) {
    std::unordered_map<int, int> num_map;

    for (int num : arr) {
        int complement = target - num;


        if (num_map.find(complement) != num_map.end()) {
            std::cout << "Numbers that sum to " << target << ": " << num << " and " << complement << std::endl;
            return;
        }


        num_map[num] = num;
    }

    std::cout << "Pair of numbers not found." << std::endl;
}

int main() {
    std::vector<int> a = {2, 7, 11, 15};
    int result = 9;

    findSumPair(a, result);

    return 0;
}