#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

vector<int> countingSort(vector<int> array) { 
  int min = *min_element(begin(array), end(array));
  int max = *max_element(begin(array), end(array));

  cout << min << " " << max << endl;
  int size1 = max - min + 1;
  int size = array.size();

  vector<int> returnArray;
  vector<int> array1(size1, 0);

  for (int i = 0; i < size; ++i) {
    int index = array[i] - min;
    array1[index]++;
  }

  for (int i = 0; i < size1; ++i) {
    while(array1[i] != 0) {
      if (min < 0) {
        returnArray.push_back(i - abs(min));
      } else {
        returnArray.push_back(i + min);
      }
      --array1[i];
    }
  }

  return returnArray;
}

int main() {
  vector<int> array = {1, 3, 2, 3, 3, -12, 10};

  vector<int> sortedArray = countingSort(array);

  for (int i = 0; i < array.size(); ++i) {
    cout << sortedArray[i] << " ";
  }

  cout << endl;

  return 0;
}
