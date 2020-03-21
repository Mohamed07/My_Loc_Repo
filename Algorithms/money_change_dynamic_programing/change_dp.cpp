#include <iostream>
#include <stdint.h>
#include <cstring>

#define NUM_COINS 3

uint32_t coins[NUM_COINS] = {4,3,1};

uint32_t get_change(int m) {
  uint32_t hist[m+1];

  std::memset(hist, UINT32_MAX, sizeof(hist));

  hist[0] = 0;
  for(int i=1; i <= m; i++)
  {
    for(int j=0; j < NUM_COINS; j++)
    {
      if(coins[j] <= i)
      {
        int index = i - coins[j];
        if((hist[i] == UINT32_MAX) || (hist[index] + 1 < hist[i]))
          hist[i] = hist[index] + 1;
      }
    }
  }

  return hist[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
