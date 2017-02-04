#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void numberOfInversions(vector<int> numbers, int start, int end) {

    if (numbers.size() == 2) {
        cout << "yaaay" << endl;
    }


}

int main() {
//    int *numbers = new int[100000];
//    int j = 0;

    vector<int> numbers;

    ifstream file("../IntegerArray.txt");

    int data;

    while (file >> data) {
        numbers.push_back(data);
    }

    numberOfInversions(numbers, 0, (int)numbers.size() - 1);

    return 0;
}