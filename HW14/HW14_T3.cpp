#include <iostream>
using namespace std;


bool areMatricesEqual(int A[4][4], int B[4][4]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (A[i][j] != B[i][j]) {
                return false;
            }
        }
    }
    return true;
}


void convertToDiagonal(int A[4][4]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (i != j) {
                A[i][j] = 0;
            }
        }
    }
}


void printMatrix(int A[4][4]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int A[4][4], B[4][4];


    cout << "Enter elements of matrix A (4x4):" << endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> A[i][j];
        }
    }


    cout << "Enter elements of matrix B (4x4):" << endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> B[i][j];
        }
    }


    if (areMatricesEqual(A, B)) {
        cout << "The matrices are equal." << endl;
        convertToDiagonal(A);
        cout << "Diagonal matrix A:" << endl;
        printMatrix(A);
    } else {
        cout << "The matrices are not equal." << endl;
    }

    return 0;
}
