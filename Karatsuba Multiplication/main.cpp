#include <iostream>
#include <cmath>

unsigned long long karatsuba_mul(unsigned long long x, unsigned long long y) {
  int len_x = (int) std::to_string(x).length();

  if (len_x == 2) {
    return x * y;
  } else {
    unsigned long long a = (unsigned long long) (x / pow(10, len_x / 2));
    unsigned long long b = x % (unsigned long long) (pow(10, len_x / 2));
    unsigned long long c = (unsigned long long) (y / pow(10, len_x / 2));
    unsigned long long d = y % (unsigned long long) (pow(10, len_x / 2));

    return (unsigned long long) (pow(10, len_x) * karatsuba_mul(a, c) +
                                 pow(10, len_x / 2) * (karatsuba_mul(a, d) + karatsuba_mul(b, c)) +
                                 karatsuba_mul(b, d));
  }
}

int main() {
  //unsigned long long x = 3141592653589793238462643383279502884197169399375105820974944592;
  //unsigned long long y = 2718281828459045235360287471352662497757247093699959574966967627;

  unsigned long long x = 1234;
  unsigned long long y = 5678;
  unsigned long long answer = karatsuba_mul(x, y);

  std::cout << answer << std::endl;

  return 0;
}