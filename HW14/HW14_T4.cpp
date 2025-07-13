#include <iostream>
using namespace std;

int main() {

    float A[4][4];
    float B[4];
    float C[4];


    cout << "Enter the elements of the matrix A (4x4):" << endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> A[i][j];
        }
    }


    cout << "Enter the elements of the vector B (4):" << endl;
    for (int i = 0; i < 4; ++i) {
        cin >> B[i];
    }


    for (int i = 0; i < 4; ++i) {
        C[i] = 0;
        for (int j = 0; j < 4; ++j) {
            C[i] += A[i][j] * B[j];
        }
    }


    cout << "Resulting vector C (AxB):" << endl;
    for (int i = 0; i < 4; ++i) {
        cout << C[i] << " ";
    }
    cout << endl;

    return 0;
}
