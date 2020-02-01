#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
long int findcand(vector<long int> &a){
    int maj_index = 0, count = 1;
    for(unsigned int i = 1; i < a.size(); ++i)
    {
        if(a[i] == a[maj_index])
            count ++;
        else
            count --;
        
        if(count == 0)
        {
            maj_index = i;
            count = 1;
        }
    }
    
    return a[maj_index];
}


int get_majority_element(vector<long int> &a, int left, int right) {
  long int cand = findcand(a);
  int count = 0;
  for(unsigned int i = 0; i < a.size(); ++i)
  {
    if(a[i] == cand)
        count ++;
  }

  if(count > a.size()/2)
    return 1;
  else
    return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<long int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
