#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using std::vector;
using std::max;

int partition3(vector<int> &A) {
  if(A.size() == 1)
    return 0;

  int val4each = accumulate(A.begin(), A.end(), 0);
  if(val4each % 3 != 0)
    return 0;

  val4each /= 3;
  
  sort(A.begin(), A.end(), std::greater<int>());

  vector<vector<int>> Wmat(A.size()+1, vector<int>(val4each+1, 0));

  for(int row = 1; row <= A.size(); ++row)
  {
    for(int col = 1; col <= val4each; ++col)
    {
        if( col - A[row-1] >= 0)
        {
           Wmat[row][col] = max( Wmat[row-1][col - A[row-1]] + A[row-1]*1,  Wmat[row-1][col] );
        }
    }
  }  
  
  if(Wmat[A.size()][val4each] == val4each)
    return 1;
  else
    return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
