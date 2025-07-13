#include <iostream>
using namespace std;

const int SIZE = 12;


void initializeBubbleWrap(bool bubbleWrap[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            bubbleWrap[i][j] = true;
        }
    }
}


void displayBubbleWrap(bool bubbleWrap[SIZE][SIZE]) {
    cout << "Current bubble wrap state:\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << (bubbleWrap[i][j] ? 'o' : 'x') << " "; // 'o' for whole, 'x' for popped
        }
        cout << endl;
    }
}


void popBubbles(bool bubbleWrap[SIZE][SIZE], int startX, int startY, int endX, int endY) {
    bool bubblesPopped = false;
    for (int i = startX; i <= endX; ++i) {
        for (int j = startY; j <= endY; ++j) {
            if (i >= 0 && i < SIZE && j >= 0 && j < SIZE && bubbleWrap[i][j]) {
                bubbleWrap[i][j] = false;
                cout << "Pop!" << endl;
                bubblesPopped = true;
            }
        }
    }

    if (bubblesPopped) {
        displayBubbleWrap(bubbleWrap);
    }
}


bool hasIntactBubbles(bool bubbleWrap[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (bubbleWrap[i][j]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    bool bubbleWrap[SIZE][SIZE];
    initializeBubbleWrap(bubbleWrap);
    displayBubbleWrap(bubbleWrap);

    int startX, startY, endX, endY;


    while (hasIntactBubbles(bubbleWrap)) {
        cout << "Enter the top-left and bottom-right coordinates of the region to pop (startX startY endX endY): ";
        cin >> startX >> startY >> endX >> endY;

        // Input validation
        if (startX < 0 || startX >= SIZE || startY < 0 || startY >= SIZE ||
            endX < 0 || endX >= SIZE || endY < 0 || endY >= SIZE ||
            startX > endX || startY > endY) {
            cout << "Invalid coordinates! Please try again." << endl;
            continue;
        }

        // Pop the specified region of bubbles
        popBubbles(bubbleWrap, startX, startY, endX, endY);
    }

    cout << "All bubbles are popped! Game over." << endl;

    return 0;
}