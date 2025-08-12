#include <iostream>

using namespace std;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 20;
    int b = 10;

    cout << "Before the exchange: " << a << " " << b << endl;

    swap(&a, &b);

    cout << "After the exchange: " << a << " " << b << endl;

    return 0;
}