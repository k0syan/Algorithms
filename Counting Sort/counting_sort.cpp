#include <iostream>
using namespace std;

int getMax(int* array, int size) {
  int max = array[0];
  for (int i = 1; i < size; ++i) {
    if (array[i] > max) {
      max = array[i];
    }
  }

  return max;
}

int getMin(int* array, int size) {
  int min = array[0];
  for (int i = 1; i < size; ++i) {
    if (array[i] < min) {
      min = array[i];
    }
  }

  return min;
}

int* countingSort(int* array,int size) { 
  int min = getMin(array, size);
  int max = getMax(array, size);
  int size1 = 1;
  size1 = max - min + 1;

  int *returnArray = new int[size];
  int *array1 = new int[size1];

  for (int i = 0; i < size1; ++i) {
    array1[i] = 0;
  }
  
  for (int i = 0; i < size; ++i) {
    int index = array[i] - min;
    array1[index]++;
  }

  int j = 0;
  for (int i = 0; i < size1; ++i) {
    while(array1[i] != 0) {
      returnArray[j] = i - abs(min);
      ++j;
      --array1[i];
    }
  }

  return returnArray;
}

int main() {
  int array[8] = {1, 3, 2, 3, 3, 4, 0, 10};

  int size = sizeof(array) / sizeof(int);

  int *sortedArray = countingSort(array, size);

  for (int i = 0; i < size; ++i) {
    cout << sortedArray[i] << " ";
  }

  cout << endl;

  return 0;
}
