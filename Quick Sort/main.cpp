#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

unsigned long long comparisons_count = 0;

int pivot_first(vector<int> numbers) {
  return numbers[0];
}

int pivot_last(vector<int> numbers) {
  return numbers[numbers.size() - 1];
}

int pivot_median(vector<int> numbers) {
  int f = numbers[0];
  int l = numbers[numbers.size() - 1];
  int m;
  if (numbers.size() % 2 == 1) {
    m = numbers[numbers.size() / 2];
  } else {
    m = numbers[numbers.size() / 2 - 1];
  }

  int median = m;
  if (f >= l) {
    if (median >= f) {
      median = f;
    }
  } else if (l >= f) {
    if (median >= l) {
      median = l;
    }
  }

  return median;
}

vector<int> quick_sort(vector<int> numbers) {
  if (numbers.size() <= 1) {
    return numbers;
  }

  vector<int> return_array;
  vector<int> left;
  vector<int> right;

  int pivot = numbers[0];

  for (int i = 1; i < numbers.size(); ++i) {
    if (numbers[i] < pivot) {
      left.push_back(numbers[i]);
    } else {
      right.push_back(numbers[i]);
    }
  }

  left = quick_sort(left);
  right = quick_sort(right);
  comparisons_count += numbers.size() - 1;

  for (int i = 0; i < left.size(); ++i) {
    return_array.push_back(left[i]);
  }

  return_array.push_back(pivot);

  for (int i = 0; i < right.size(); ++i) {
    return_array.push_back(right[i]);
  }

  return return_array;
}

int main() {
  ifstream file("../QuickSort.txt");

  int data;
  vector<int> numbers;

  while (file >> data) {
    numbers.push_back(data);
  }

  vector<int> sorted_array = quick_sort(numbers);

  cout << comparisons_count << endl;

  return 0;
}