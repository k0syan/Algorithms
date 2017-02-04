#include <iostream>
#include <fstream>

int numberOfInversions(int *numbers) {

    return 0;
}

int main() {
    int *numbers = new int[100000];
    int j = 0;

    std::ifstream file("../IntegerArray.txt");

    int data;

    while (file >> data) {
        numbers[j] = data;
        j++;
    }

    return 0;
}