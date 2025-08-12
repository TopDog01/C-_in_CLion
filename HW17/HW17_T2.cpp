#include <iostream>

void reverseArray(int* arr) {
    for (int i = 0; i < 5; ++i) {

        int temp = arr[i];
        arr[i] = arr[9 - i];
        arr[9 - i] = temp;
    }
}

int main() {
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "Original array: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    reverseArray(array);

    std::cout << "Reversed array: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}