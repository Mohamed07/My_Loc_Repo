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
int get_major_elem(vector<long int> &a, int left, int right, int LSM, int RSM) {
  if((LSM == -1) && (RSM == -1))
  {
    return -1;
  }
  else
  {
    int len = (right - left) + 1;
    int lsm_c = 0, rsm_c = 0;
    for(int i = left; i <= right; i++)
    {
      if(a[i] == LSM)
        lsm_c += 1;
      else if (a[i] == RSM)
        rsm_c += 1;
    }

    if(lsm_c > len/2)
      return LSM;
    else if (rsm_c > len/2)
      return RSM;
    else
      return -1;    
  }
  
}

int get_majority_element_r(vector<long int> &a, int left, int right) {

  if(left < right)
  {
    int mid = left + (right-left)/2;
    int LSM = get_majority_element_r(a, left, mid);
    int RSM = get_majority_element_r(a, mid+1, right);
    int FME = get_major_elem(a, left, right, LSM, RSM);

    return FME;
  }
  else
  {
    return a[left];
  }
  

}
int main() {
  int n;
  std::cin >> n;
  vector<long int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element_r(a, 0, a.size()-1) != -1) << '\n';
}
