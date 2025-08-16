#include <iostream>

void evendigits(long long n, int& ans) {

    if (n == 0) return;


    int digit = n % 10;
    if (digit % 2 == 0) {
        ans++;
    }


    evendigits(n / 10, ans);
}

int main() {
    long long n = 9223372036854775806LL;
    int ans = 0;

    evendigits(n, ans);
    std::cout << "Number of even digits: " << ans << std::endl;

    return 0;
}
