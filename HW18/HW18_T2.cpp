#include <iostream>

int countWays(int n, int k = 3)
{
    if (n == 0) return 1;
    if (n < 0) return 0;

    int totalWays = 0;
    for (int i = 1; i <= k ; ++i) {
        totalWays += countWays(n -i, k);
    }

    return totalWays;
}

int main()
{
    int n = 3;
    int k = 2;

    int result = countWays(n, k);
    std::cout << "Number of ways: " << result << std::endl;

    return 0;
}