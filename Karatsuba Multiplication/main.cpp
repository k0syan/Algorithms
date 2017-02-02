#include <iostream>
#include <cmath>


unsigned long long karatsuba(unsigned long long x, unsigned long long y) {
  int len_x = (int) std::to_string(x).length();

  if (len_x == 2) {
    return x * y;
  } else {
    unsigned long long a = (unsigned long long) (x / pow(10, len_x / 2));
    unsigned long long b = x % (unsigned long long) (pow(10, len_x / 2));
    unsigned long long c = (unsigned long long) (y / pow(10, len_x / 2));
    unsigned long long d = y % (unsigned long long) (pow(10, len_x / 2));

    return (unsigned long long) (pow(10, len_x) * karatsuba(a, c) +
                                 pow(10, len_x / 2) * (karatsuba(a, d) + karatsuba(b, c)) +
                                 karatsuba(b, d));
  }
}

int main() {
  unsigned long long x = 1234;
  unsigned long long y = 5678;
  unsigned long long answer = karatsuba(x, y);

  std::cout << answer << std::endl;

  return 0;
}
