#include <iostream>
#include <vector>
#include <algorithm>

std::pair<int, int> maxSubarraySum(const std::vector<int>& arr) {
    int maxSum = arr[0];
    int currentSum = arr[0];
    int start = 0, end = 0, tempStart = 0;

    for (size_t i = 1; i < arr.size(); i++) {
        if (currentSum < 0) {
            currentSum = arr[i];
            tempStart = i;
        } else {
            currentSum += arr[i];
        }

        if (currentSum > maxSum) {
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }
    }

    return {start, end};
}

int main() {
    std::vector<int> a = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    auto result = maxSubarraySum(a);
    std::cout << "Indices of the maximum subarray sum: " << result.first << " and " << result.second << std::endl;

    return 0;
}