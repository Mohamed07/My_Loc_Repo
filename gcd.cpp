#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}


int gcd_naive_fast(int a, int b) {
    if(b == 0)
    {
        return a;
    }
    else
    {
        int a_prime = a % b;
        return gcd_naive_fast(b, a_prime);
    }
}
int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_naive(a, b) << std::endl;
  std::cout << gcd_naive_fast(a, b) << "\n";
  return 0;
}
