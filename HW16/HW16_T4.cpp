#include <iostream>
#include <string>
#include <unordered_set>

enum note {
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SI = 64
};

int main() {
    std::string input;
    std::cout << "Enter a chord (sequence of digits from 1 to 7): ";
    std::cin >> input;

    int notes = 0;
    std::unordered_set<char> unique_notes;


    for (char c : input) {
        if (c >= '1' && c <= '7' && unique_notes.find(c) == unique_notes.end()) {
            unique_notes.insert(c);
            int note_index = c - '1';
            notes |= (1 << note_index);
        }
    }


    std::cout << "The notes in your chord are: ";
    if (notes & DO) std::cout << "DO ";
    if (notes & RE) std::cout << "RE ";
    if (notes & MI) std::cout << "MI ";
    if (notes & FA) std::cout << "FA ";
    if (notes & SOL) std::cout << "SOL ";
    if (notes & LA) std::cout << "LA ";
    if (notes & SI) std::cout << "SI ";


    std::cout << std::endl;

    return 0;
}