#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

unsigned long long inversions_count = 0;

vector<int> merge(vector<int> first_array, vector<int> second_array) {
  vector<int> merged;

  int j = 0;
  int i = 0;
  for (int k = 0; k < (int) (first_array.size() + second_array.size()); k++) {
    if (i < (int) first_array.size()) {
      if (j < (int) second_array.size()) {
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

vector<int> merge_sort(vector<int> numbers, int start, int end) {
  if (end == start) {
    return vector<int>{numbers[start]};
  }

  if (end - start < 2) {
    vector<int> first_array = {numbers[start]};
    vector<int> second_array = {numbers[end]};
    return merge(first_array, second_array);
  }

  return merge(merge_sort(numbers, start, (end + start) / 2), merge_sort(numbers, (end + start) / 2 + 1, end));
}


int main() {
  ifstream file("data.txt");

  int data;
  vector<int> numbers;

  while (file >> data) {
    numbers.push_back(data);
  }

  vector<int> merged = merge_sort(numbers, 0, (int) numbers.size() - 1);

  for (int i = 0; i < merged.size(); ++i) {
    cout << merged[i] << endl;
  }

  cout << endl << "Inversions count in your array is: " << inversions_count << endl;

  return 0;
}
