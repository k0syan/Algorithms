#include <iostream>
#include <cmath>
using namespace std;

int getMax(int* array,int size) {
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

int main() {
  int array[8] = {1, 3, 2, 3, 3, 4, 0, 10};
  
  int size = sizeof(array) / sizeof(int);
  int min = getMin(array, size);
  int max = getMax(array, size);
 
  int size1 = 1;

  size1 = max - min + 1;
  
  int *array1 = new int[size1];

  for (int i = 0; i < size1; ++i) {
    array1[i] = 0;
  }
  
  for (int i = 0; i < size; ++i) {
    int index = array[i] - min;
    array1[index]++;
  }

  for (int i = 0; i < size1; ++i) {
    while(array1[i] != 0) {
      cout << i - abs(min) << " ";   
      --array1[i];
    }
  }

  cout << endl;

  return 0;
}
