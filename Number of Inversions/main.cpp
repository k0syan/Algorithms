#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int inversions_count = 0;

vector<int> merge(vector<int> first_array, vector<int> second_array) {
    vector<int> merged;

//    1, 3, 5
//    2, 4, 6

    int j = 0;
    int i = 0;
    for (int k = 0; k < (int)first_array.size() * 2; k++) {
        if (i < (int)first_array.size()) {
            if (j < (int)second_array.size()) {
                if (first_array[i] <= second_array[j]) {
                    merged.push_back(first_array[i]);
                    i++;
                } else {
                    inversions_count += first_array.size() - i;
                    merged.push_back(second_array[j]);
                    j++;
                }
            } else {
                merged.push_back(first_array[i]);
                i++;
            }
        } else {
            merged.push_back(second_array[j]);
            j++;
        }
    }

    return merged;
}

void numberOfInversions(vector<int> numbers, int start, int end) {

    if (numbers.size() == 2) {
        cout << "yaaay" << endl;
    }


}

int main() {
//    int *numbers = new int[100000];
//    int j = 0;

    vector<int> numbers = {1, 3, 5};
    vector<int> numbers1 = {2, 4, 6};

    vector<int> merged = merge(numbers, numbers1);

    for (int i = 0; i < merged.size(); i++) {
        cout << merged[i] << " ";
    }
    cout << inversions_count << endl;

//    ifstream file("../IntegerArray.txt");
//
//    int data;
//
//    while (file >> data) {
//        numbers.push_back(data);
//    }
//
//    numberOfInversions(numbers, 0, (int)numbers.size() - 1);

    return 0;
}