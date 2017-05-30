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

pair<int, int> pivot_median(vector<int> numbers) {
  if (numbers.size() == 2) {
    pair<int, int> r = {numbers[0], 0};
    return r;
  }
  int f = numbers[0];
  int l = numbers[numbers.size() - 1];
  int m;
  int index;
  if (numbers.size() % 2 == 1) {
    m = numbers[numbers.size() / 2];
    index = (int) numbers.size() / 2;
  } else {
    m = numbers[numbers.size() / 2 - 1];
    index = (int) numbers.size() / 2 - 1;
  }

  int median = m;

  if (f >= l) {
    if (median >= f) {
      median = f;
      index = (int) numbers.size() - 1;
    }
  } else if (l >= f) {
    if (median >= l) {
      median = l;
      index = 0;
    }
  }

  pair<int, int> r = {median, index};
  return r;
}

vector<int> quick_sort(vector<int> numbers) {
  if (numbers.size() <= 1) {
    return numbers;
  }

  vector<int> return_array;
  vector<int> left;
  vector<int> right;

//  int pivot = pivot_median(numbers).first;
//  int index = pivot_median(numbers).second;

//  cout << pivot << " AaA " << index << endl;

//  int pivot = pivot_last(numbers);
//  int index = (int) numbers.size() - 1;

  int pivot = pivot_first(numbers);
  int index = 0;

  for (int i = 0; i < numbers.size(); ++i) {
    if (i != index) {
      if (numbers[i] < pivot) {
        left.push_back(numbers[i]);
      } else {
        right.insert(right.begin(), numbers[i]);
      }
    }
  }

//  for (int i = 0; i < left.size(); ++i) {
//    cout << left[i] << " A ";
//  }
//
//  cout << endl;

  comparisons_count += (int) left.size() + (int) right.size();

  left = quick_sort(left);
  right = quick_sort(right);

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
  ifstream file("../1.txt");

  int data;
  vector<int> numbers;

  while (file >> data) {
    numbers.push_back(data);
  }

  vector<int> sorted_array = quick_sort(numbers);

  for (int i = 0; i < sorted_array.size(); ++i) {
    cout << sorted_array[i] << endl;
  }

  cout << endl << comparisons_count << endl;
  return 0;
}
