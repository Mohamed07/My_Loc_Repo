#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>

using std::vector;

int binary_search(const vector<long int> &a, int x) {
  int left = 0, right = (int)a.size(); 
  //write your code here
  bool found = false;
  int mid = left + floor(((float) (right - left)/2));
  while( (left <= right))
  {
    //std::cout << "(" << left << ", " << right << "), mid = " << mid <<'\n';
    if(a[mid] == x)
    {
      //found = true;
      return mid;
    }
    else if (a[mid] < x)
    {
        left = mid + 1;
        mid  = left + floor(((float) (right - left)/2));
    }
    else
    {
        right = mid - 1;
        mid   = left + floor(((float) (right - left)/2));
    }
  }
  if(found)
    return mid;
  else
    return -1;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<long int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<long int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    //std::cout << "linear : "<< linear_search(a, b[i]) << ' '<<"\n";
    std::cout<< binary_search(a, b[i]) << ' ';
  }
}
