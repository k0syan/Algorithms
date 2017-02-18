#include <iostream>
#include <cmath>

typedef unsigned long long huge;

huge karatsuba(huge x, huge y) {
  int len_x = (int) std::to_string(x).length();

  if (len_x == 2) {
    return x * y;
  } else {
    huge a = (huge) (x / pow(10, len_x / 2));
    huge b = x % (huge) (pow(10, len_x / 2));
    huge c = (huge) (y / pow(10, len_x / 2));
    huge d = y % (huge) (pow(10, len_x / 2));

    return (huge) (pow(10, len_x) * karatsuba(a, c) +
                   pow(10, len_x / 2) * (karatsuba(a, d) + karatsuba(b, c)) +
                   karatsuba(b, d));
  }
}

int main() {
  huge x = 1234;
  huge y = 5678;
  huge answer = karatsuba(x, y);

  std::cout << answer << std::endl;

  return 0;
}
