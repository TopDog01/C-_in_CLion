#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cout << "Input vector size: ";
    std::cin >> n;

    std::vector<int> vec(n);
    std::cout << "Input numbers: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> vec[i];
    }

    int x;
    std::cout << "Input number to delete: ";
    std::cin >> x;


    vec.erase(std::remove(vec.begin(), vec.end(), x), vec.end());

    std::cout << "Result: ";
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << (i == vec.size() - 1 ? "" : " ");
    }
    std::cout << std::endl;

    return 0;
}