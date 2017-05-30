#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

vector<int> counting_sort(vector<int> arr, int pos) {
  int size = arr.size();
  vector<int> return_arr(size);
  vector<int> digits(10, 0);

  for (int i = 0; i < size; ++i) {
    int digit = (arr[i] / pos) % 10;
    digits[digit]++;
  }
  return return_arr;
}

vector<int> radix_sort(vector<int> arr) {
  vector<int> return_arr(arr);
  int max = *max_element(begin(arr), end(arr));

  for (int i = 1; max / i > 0; i *= 10) {
    return_arr = counting_sort(return_arr, i);
  }

  return return_arr;
};

int main() {
  vector<int> arr = {107, 71, 1, 13};

  vector<int> s = radix_sort(arr);
  
  for (int i = 0; i < s.size(); ++i) {
    cout << s[i] << " "; 
  }

  cout << endl;

  return 0;
}
