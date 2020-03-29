#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;
using std::sort;

// We need this function to define how to sort
// // the vector. We will pass this function into the
// // third parameter and it will tell it to sort descendingly.
 bool wayToSort(int i, int j) { return i > j; }

int optimal_weight(int W, vector<int> &w) {
  int item_val = 10;
  //write your code here
  vector<vector<int>> Wmat(w.size()+1,vector<int>(W+1, 0));
  //std::cout<<Wmat.size() << Wmat[0].size() << "\n";
  sort(w.begin(), w.end(), wayToSort);
 
  int current_weight = 0;
  for (int i = 1; i <= w.size(); ++i) {
    for(int j = 1; j <= W; ++j)
    {
        int val;
            
        if((j - w[i-1]) >= 0)
        {
            //std::cout << "i = "<<i << "\t j = " << j  << "\t w[i-1] = "<< w[i-1] << "\n"; 
            val = max(Wmat[i-1][j-w[i-1]] + ( w[i-1] * item_val ), Wmat[i-1][j]);
            Wmat[i][j] = val;
        }
    }
  }

//  for (int col = 0; col <= W; ++col){
//    std::cout<<col << "\t";
//    }
//  std::cout <<"\n";
//  for (int row = 0; row <= w.size(); ++row){
//    for(int col = 0; col <= W; ++col)
//        std::cout << Wmat[row][col] << "\t";
    
//    std::cout << "\n";
//  }
    current_weight = Wmat[w.size()][W]/item_val;
  return current_weight;
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
