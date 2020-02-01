#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::vector;

double get_optimal_value(int capacity, vector<int> &weights, vector<int> &values) {
  double value = 0.0;
  // Bubble Sort
  bool swap = true;
  while(swap)
  {
          swap = false;
          for(unsigned int i = 0; i < weights.size()-1; ++i)
          {
                if( ((double)values[i]) / weights[i] < ((double)values[i+1]) / weights[i+1] )
                {
                        swap = true;
                        int tmp = values[i];
                        values[i]   = values[i+1];
                        values[i+1] = tmp;

                        tmp = weights[i];
                        weights[i]   = weights[i+1];
                        weights[i+1] = tmp;
                }
          }


  }


  // Algorithm Here
  int frac = 0;
  for(unsigned int i = 0; (i < weights.size()) && (capacity > 0); ++i)
  {
          if(weights[i] != 0)
          {
              frac = std::min(weights[i], capacity);
              capacity -= frac;
              value += (((double) frac)/weights[i])*values[i];
          }
          else
          {
              std::cout<< "size = "<< weights.size()<<"\n";
              std::cout<< "cap = "<<capacity <<", value["<<i<<"] = "<<values[i]<<", frac = "<<frac<<"\n";
          }
  }

  if(value - int(value) >= 0.9)
  {
      value = ceil(value);
  }
  else
  {
      value *= 10000;
      value = ceil(value);
      value /= 10000;
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  std::vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(9);
  std::cout << optimal_value << std::endl;
  return 0;
}
