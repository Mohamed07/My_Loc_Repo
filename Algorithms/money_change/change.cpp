#include <iostream>

int deno[3] = {1, 5, 10};

int get_change(int m) {
  //write your code here
  int n = 0;
  for(int i= 2; i >= 0; i--)
  {
    while(m >= deno[i])
    {
      n++;
      m -= deno[i];
    }
  }
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
