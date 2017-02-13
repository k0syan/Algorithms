#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
  ifstream file("../QuickSort.txt");

  int data;
  vector<int> numbers;

  while (file >> data) {
    numbers.push_back(data);
  }

  for (int i = 0; i < numbers.size(); ++i) {
    cout << numbers[i] << endl;
  }

  return 0;
}