#include <iostream>
#include <vector>
#include <cstdlib>
#include <math.h>
#include <string>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m = partition2(a, l, r);

  randomized_quick_sort(a, l, m - 1);
  randomized_quick_sort(a, m + 1, r);
}

int main(int argc, char* argv[]) {
  if(argc == 1)
  {
    std::cout<< "Usage: ./sort #size_of_list #list_members\n";
  }
  else if( argc - 2 == std::stoi(argv[1]))
  {
    vector<int> a(std::stoi(argv[1]));
    for (size_t i = 0; i < a.size(); ++i) {
        //std::cin >> a[i];
        a[i] = std::stoi(argv[i+2]);
    }
    randomized_quick_sort(a, 0, a.size() - 1);
    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << a[i] << ' ';
    }
   }else{
     std::cout<< "length of list = "<< std::stoi(argv[1]) << "\n";
     std::cout<< "provieded items >< \n";
    }
}
