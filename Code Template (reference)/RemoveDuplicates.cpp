#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void removeDuplicates(vector<int>& sorted_vec) {
    auto last = unique(sorted_vec.begin(), sorted_vec.end());
    sorted_vec.erase(last, sorted_vec.end());
}

void printVector(const vector<int>& vec) {
    for (int number : vec) {
        cout << number << " ";
    }
    cout << endl;
}

int main() {
    vector<int> numbers = {1, 1, 1, 2, 4, 5, 5, 6, 6, 6, 7, 8, 8}; // syarat: harus sudah terurut

    cout << "Vector sebelum duplikat dihapus: ";
    printVector(numbers);

    removeDuplicates(numbers);

    cout << "Vector setelah duplikat dihapus:  ";
    printVector(numbers);

    return 0;
}
